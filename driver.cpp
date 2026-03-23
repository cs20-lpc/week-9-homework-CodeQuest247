#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

#include "QueueFactory.hpp"

using namespace std;

void simulateTicketCounter() {
    cout << "------ Ticket Counter Simulation ------" << endl;

    Queue<int>* ticketLine = QueueFactory<int>::GetQueue(10);

    int nextCustomer = 1;

    for (int i = 1; i <= 100; i++) {
        int action = rand() % 3 - 1;  

        cout << "Step " << i << ": ";

        if (action < 0) {
            try {
                int servedCustomer = ticketLine->front();
                ticketLine->dequeue();
                cout << "Customer " << servedCustomer << " was served and left." << endl;
            }
            catch (string& e) {
                cout << "No customers to serve." << endl;
            }
        }
        else {
            try {
                ticketLine->enqueue(nextCustomer);
                cout << "Customer " << nextCustomer << " joined the line." << endl;
                nextCustomer++;
            }
            catch (string& e) {
                cout << "Line is full. Customer turned away." << endl;
            }
        }

        cout << "Current line length: " << ticketLine->getLength() << endl;
    }

    delete ticketLine;
    cout << endl;
}

void simulateBankLine() {
    cout << "------ Bank Service Line Simulation ------" << endl;

    Queue<int>* bankLine = QueueFactory<int>::GetQueue();

    int nextCustomer = 1;

    for (int i = 1; i <= 100; i++) {
        int action = rand() % 4 - 1;  // random number from -1 to 2

        cout << "Step " << i << ": ";

        if (action < 0) {
            try {
                int servedCustomer = bankLine->front();
                bankLine->dequeue();
                cout << "Customer " << servedCustomer << " finished service and left." << endl;
            }
            catch (string& e) {
                cout << "No customers to serve." << endl;
            }
        }
        else {
            bankLine->enqueue(nextCustomer);
            cout << "Customer " << nextCustomer << " joined the line." << endl;
            nextCustomer++;
        }

        cout << "Current line length: " << bankLine->getLength() << endl;
    }

    delete bankLine;
    cout << endl;
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    simulateTicketCounter();
    simulateBankLine();

    return 0;
}