#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>

using namespace std;

enum EventArea { NORMAL = 0, VIP = 1 };

class AbstractLocation {
public:
    virtual void displayLocation() const = 0;
    virtual ~AbstractLocation() = default;
};

class Location : public AbstractLocation {
private:
    int noOfSeats = 0;
    int noOfRows = 0;
    int noOfSeatsOccupied = 0;

public:
    void displayLocation() const override {
        cout << "Number of seats: " << noOfSeats << endl;
        cout << "Number of rows: " << noOfRows << endl;
        cout << "Number of occupied seats: " << noOfSeatsOccupied << endl;
    }

    void SaveToFile(const char* fileName) {
        ofstream outFile(fileName, ios::binary);
        if (!outFile.is_open()) {
            cerr << "Error opening file for writing\n";
            return;
        }

        outFile.write(reinterpret_cast<char*>(&noOfSeats), sizeof(noOfSeats));
        outFile.write(reinterpret_cast<char*>(&noOfRows), sizeof(noOfRows));
        outFile.write(reinterpret_cast<char*>(&noOfSeatsOccupied), sizeof(noOfSeatsOccupied));

        outFile.close();
    }

    void LoadFromFile(const char* fileName) {
        ifstream inFile(fileName, ios::binary);
        if (!inFile.is_open()) {
            cerr << "Error opening file for reading\n";
            return;
        }

        inFile.read(reinterpret_cast<char*>(&noOfSeats), sizeof(noOfSeats));
        inFile.read(reinterpret_cast<char*>(&noOfRows), sizeof(noOfRows));
        inFile.read(reinterpret_cast<char*>(&noOfSeatsOccupied), sizeof(noOfSeatsOccupied));

        inFile.close();
    }
};

class Ticket {
private:
    int Row = 0;
    int Number = 0;
    static int Id;
    EventArea Area = EventArea::NORMAL;

public:
    Ticket() {
        this->Id++;
    }

    void SaveToFile(const char* fileName) {
        ofstream outFile(fileName, ios::binary | ios::app);
        if (!outFile.is_open()) {
            cerr << "Error opening file for writing\n";
            return;
        }

        outFile.write(reinterpret_cast<char*>(&Row), sizeof(Row));
        outFile.write(reinterpret_cast<char*>(&Number), sizeof(Number));
        outFile.write(reinterpret_cast<char*>(&Id), sizeof(Id));
        outFile.write(reinterpret_cast<char*>(&Area), sizeof(Area));

        outFile.close();
    }

    void LoadFromFile(const char* fileName) {
        ifstream inFile(fileName, ios::binary);
        if (!inFile.is_open()) {
            cerr << "Error opening file for reading\n";
            return;
        }

        inFile.read(reinterpret_cast<char*>(&Row), sizeof(Row));
        inFile.read(reinterpret_cast<char*>(&Number), sizeof(Number));
        inFile.read(reinterpret_cast<char*>(&Id), sizeof(Id));
        inFile.read(reinterpret_cast<char*>(&Area), sizeof(Area));

        inFile.close();
    }
};

int Ticket::Id = 0;

class VIP_Ticket : public Ticket {

};

class Event {
private:
    int* date = nullptr;
    char* time = nullptr;
    const static int date_length = 8;
    string nameOfEvent = " ";

public:
    void SaveToFile(const char* fileName) {
        ofstream outFile(fileName, ios::binary);
        if (!outFile.is_open()) {
            cerr << "Error opening file for writing\n";
            return;
        }

        outFile.write(reinterpret_cast<char*>(date), sizeof(int) * date_length);
        int timeLength = time ? strlen(time) : 0;
        outFile.write(reinterpret_cast<char*>(&timeLength), sizeof(int));
        outFile.write(time, timeLength);
        outFile.write(reinterpret_cast<char*>(&nameOfEvent), sizeof(nameOfEvent));

        outFile.close();
    }

    void LoadFromFile(const char* fileName) {
        ifstream inFile(fileName, ios::binary);
        if (!inFile.is_open()) {
            cerr << "Error opening file for reading\n";
            return;
        }

        delete[] date;
        inFile.read(reinterpret_cast<char*>(date), sizeof(int) * date_length);

        int timeLength;
        inFile.read(reinterpret_cast<char*>(&timeLength), sizeof(int));
        delete[] time;
        time = new char[timeLength + 1];
        inFile.read(time, timeLength);
        time[timeLength] = '\0';

        inFile.read(reinterpret_cast<char*>(&nameOfEvent), sizeof(nameOfEvent));

        inFile.close();
    }
};

int main(int argc, char* argv[]) {
    if (argc > 1) {

    }
    else {
        int choice;
        vector<Ticket> tickets;
        Location location;
        Event event;

        do {
            cout << "1. Issue Ticket\n";
            cout << "2. Display Data\n";
            cout << "3. Save Data to File\n";
            cout << "4. Load Data from File\n";
            cout << "5. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            if (choice == 1) {
                Ticket newTicket;
                tickets.push_back(newTicket);
            }
            else if (choice == 2) {
                for (const Ticket& ticket : tickets) {
                    //ticket.printTicket();
                }
                location.displayLocation();
            }
            else if (choice == 3) {
                location.SaveToFile("location_data.bin");
                for (Ticket& ticket : tickets) {
                    ticket.SaveToFile("ticket_data.bin");
                }
                event.SaveToFile("event_data.bin");
            }
            else if (choice == 4) {
                location.LoadFromFile("location_data.bin");
                tickets.clear();
                Ticket loadedTicket;
                loadedTicket.LoadFromFile("ticket_data.bin");
                tickets.push_back(loadedTicket);
                event.LoadFromFile("event_data.bin");
            }
            else if (choice == 5) {
                // Exit
            }
            else {
                cout << "Invalid choice. Please try again.\n";
            }

        } while (choice != 5);
    }

    return 0;
}
