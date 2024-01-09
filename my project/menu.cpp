

#include <iostream>
#include <fstream>  // Required for file operations
#include "Ticket.cpp"
#include "phase2.cpp"
using namespace std;


void displayMenu() {
    cout << "===== Menu =====" << endl;
    cout << "1. Buy Ticket" << endl;
    cout << "2. View Ticket Details" << endl;
    cout << "3. Save Tickets to File" << endl;
    cout << "4. Load Tickets from File" << endl;
    cout << "5. Exit" << endl;
    cout << "================" << endl;
}


void menu() {
    displayMenu();

    Ticket Ticket;

    int choice;

    do {

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            Ticket.Ticket();
            break;
        case 2:
            Ticket.printTicket();
            break;
        case 3:
            Ticket.saveToFile("ticket.dat");
            break;
        case 4:
            Ticket.loadFromFile("ticket.dat");
            break;
        case 5:
            cout << "Exiting the program. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice. Please enter a number between 1 and 5." << endl;
            break;
        }

    } while (choice != 5);


}

