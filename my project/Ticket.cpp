#include <string>
#include <iostream>

using namespace std;

enum EventArea { NORMAL = 0, VIP = 1 };

class Ticket
{
private:
    int Row = 0;
    int Number = 0;
    static int Id;
    EventArea Area = EventArea::NORMAL;

public:

    Ticket()
    {
        this->Id++;
    }

    Ticket(int row, int number, EventArea Area = EventArea::NORMAL)
    {
        this->Row = row;
        this->Number = number;
        this->Id++;
        this->Area = Area;
    }

    ~Ticket()
    {
    }

    int getRow()
    {
        return this->Row;
    }

    void setRow(int row)
    {
        this->Row = row;
    }

    int getNumber()
    {
        return this->Number;
    }

    void setNumber(int number)
    {
        this->Number = number;
    }

    int getId()
    {
        return this->Id;
    }

    void setId(int id)
    {
        this->Id = id;
    }

    int getArea()
    {
        return this->Area;
    }

    void setArea(EventArea Area)
    {
        this->Area = Area;
    }

    static int GetNumberOfTickets()
    {
        return Id;
    }

    void printTicket()
    {
        cout << "Ticket-ul dumneavoastra are urmatoarele caracteristici: " << endl;
        cout << "Rand: " << this->getRow() << endl;
        cout << "Numar: " << this->getNumber() << endl;
        cout << "Zona: " << this->getArea() << endl;
        cout << "Numar unic de identificare: " << this->getId() << endl;
    }

    Ticket operator -()
    {
        Number = -this->Number;
        Row = -this->Row;

        return Ticket(Row, Number, Area);
    }

    Ticket operator+(const Ticket& ticket)
    {
        int number = this->getNumber() + ticket.Number;
        int row = this->getRow() + ticket.Row;
        EventArea area = EventArea::NORMAL;
        if (this->getArea() == EventArea::VIP && ticket.Area == EventArea::VIP)
        {
            int area = EventArea::VIP;
        }

        Ticket t(row, number, area);

        return t;
    }


    friend istream& operator>>(istream& input, Ticket& ticket)
    {
        int row, number, id;
        char zona[1000];

        input >> row;
        ticket.setRow(row);

        input >> number;
        ticket.setNumber(number);

        input >> id;
        ticket.setId(id);

        input.getline(zona, 1000);

        if (strcmp(zona, "NORMAL") == 0)
        {
            ticket.setArea(EventArea::NORMAL);
        }
        else if (strcmp(zona, "VIP") == 0)
        {
            ticket.setArea(EventArea::VIP);
        }

        return input;
    }

    friend ostream& operator<<(ostream& output, const Ticket& ticket)
    {
        output << "Ticket-ul dumneavoastra are urmatoarele caracteristici: " << endl;
        output << "Rand: " << ticket.Row << endl;
        output << "Numar: " << ticket.Number << endl;
        output << "Zona: " << ticket.Area << endl;
        output << "Numar unic de identificare: " << ticket.Id << endl;

        return output;
    }

};


