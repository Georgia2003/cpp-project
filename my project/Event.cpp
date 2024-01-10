#pragma once 
#include<iostream>
#include<string>
#include<stdexcept>

using namespace std;


class Event {

private:
    int* date = nullptr;
    char* time = nullptr;
    const static int date_length = 8;
    string nameOfEvent = " ";

public:


    int* getDate()
    {
        return this->date;
    }

    void setDate(int* date)
    {
        for (int i = 0; i < date_length; i++)
        {
            if (date[i] < 0 || date[i] > 9)
            {
                throw exception("the date should look like DD/MM/YYYY");
            }
        }



        delete[] this->date;
        this->date = new int[date_length];
        for (int i = 0; i < Event::date_length; i++) {
            this->date[i] = date[i];
        }
        //memcpy(this->date, date, sizeof(int) * date_length);
    }

    char* getTime()
    {
        return this->time;
    }

    void setTime(const char* time)
    {
        if (strlen(time) != 5)
        {
            throw exception("the time should look like HH:MM");
        }

        for (int i = 0; i < strlen(time); i++)
        {
            if(i != 2) {
                if(time[i] < '0' || time[i] > '9')
                {
                    throw exception("the time should look like HH:MM");

                }
            }
            else if (time[2] != ':') {
                throw std::invalid_argument("The time should look like HH:MM");
            }

        }
        delete[] this->time;
        this->time = new char[strlen(time) + 1];
        strcpy_s(this->time, strlen(time) + 1, time);
    }

    void printTime()
    {
        cout << this->time;
    }

    string getNameOfEvent()
    {
        return this->nameOfEvent;
    }

    void setNameOfEvent(string nameOfEvent)
    {
        if (nameOfEvent.size() > 50) {
            throw exception("this name is too long. please enter a shorter name  Eg.: MGF, ASR etc.");
        }

        this->nameOfEvent = nameOfEvent;
    }

    //default constructor
    Event()
    {
    }

    Event(string nameOfEvent, int* date, const char* time)
    {
        this->setDate(date);
        this->setTime(time);
        this->setNameOfEvent(nameOfEvent);
    }

    ~Event()
    {
        delete[] this->date;
        delete[] this->time;
    }

    bool operator !=(const Event& event)
    {
        int cnt = 0;
        for (int i = 0; i < date_length; i++)
        {
            if (getDate()[i] == event.date[i])
            {
                cnt++;
            }
        }

        for (int i = 0; i < 4; i++)
        {
            if (getTime()[i] == event.time[i])
            {
                cnt++;
            }
        }

        if (getNameOfEvent().compare(event.nameOfEvent) == 0 && cnt == 12)
        {
            return false;
        }
        else
            return true;
    }

    bool operator ==(const Event& event)
    {
        int cnt = 0;
        for (int i = 0; i < date_length; i++)
        {
            if (getDate()[i] == event.date[i])
            {
                cnt++;
            }
        }

        for (int i = 0; i < 4; i++)
        {
            if (getTime()[i] == event.time[i])
            {
                cnt++;
            }
        }

        if (getNameOfEvent().compare(event.nameOfEvent) == 0 && cnt == 12)
        {
            return true;
        }
        else
            return false;
    }

    friend ostream& operator<<(ostream& output, const Event& event);

    friend istream& operator>>(istream& input, Event& Event);
};


