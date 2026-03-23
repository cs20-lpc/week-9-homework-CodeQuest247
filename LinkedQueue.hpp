#ifndef LINKED_QUEUE_HPP
#define LINKED_QUEUE_HPP

#include "Queue.hpp"
#include <iostream>
using namespace std;

// This file declares the LinkedQueue class and all its functions 
// *LinkedQueue.hpp defines a queue implementation using a linked list. 
// It inherits the definitions from the Queue base class and provides actual implementations
// for all required queue operations (enqueue, dequeue, front, back, etc).
// virtual allows the correct version of a function to run if the queue is used through a base class like class Queue
// virtual allows the correct version of a function to run when a derived class object (like LinkedQueue class) is used through a base class like Queue.

template <typename T>
class LinkedQueue : public Queue<T> {
    protected:
        // represents an element in the queue
        struct Node {
            T value;
            Node* next;

            Node(T v = T(), Node* n = nullptr)
            : value(v), next(n) { }
        };

        // a pointer to the front (head) and back (last) of the queue
        Node *head, *last;

    private:
        // copy the state of the argument queue to `this`
        void copy(const LinkedQueue<T>&);

    public:
        // default constructor
        LinkedQueue();

        // copy constructor
        LinkedQueue(const LinkedQueue<T>&);

        // overloaded assignment operator
        LinkedQueue<T>& operator=(const LinkedQueue<T>&);

        // destructor
        virtual ~LinkedQueue();

        // return the element at the back of the queue
        virtual T back() const override;

        // remove all elements in the queue, resetting to the initial state
        virtual void clear() override;

        // remove the front element from the queue
        virtual void dequeue() override;

        // add the argument to the back of the queue
        virtual void enqueue(const T&) override;

        // return the element at the front of the queue
        virtual T front() const override;

        // return the current length of the queue
        virtual int getLength() const override;

        // determine if the queue currently empty
        virtual bool isEmpty() const override;
};

#include "LinkedQueue.tpp"
#endif
