#include<iostream>
#include<string>
#include<stdexcept>

using namespace std;

class Event {

private:
	int* date = nullptr;
	char* time = nullptr;
	const int date_length = 8;
	string nameOfEvent = " ";

public:
	//default constructor
	Event()
	{
	}

	Event(string nameOfEvent, const int* date, const char* time)
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

	int* getDate()
	{
		return this->date;
	}

	void setDate(const int* date)
	{
		for (int i = 0; i < date_length; i++)
		{
			if (date[i] < 0 || date[i] > 9)
			{
				throw std::invalid_argument("the date should look like DD/MM/YYYY");
			}
		}

		if (date[date_length] != 0)
		{
			throw std::invalid_argument("the date should look like DD/MM/YYYY");
		}

		delete[] this->date;
		this->date = new int[date_length];
		memcpy(this->date, date, sizeof(int) * date_length);
	}

	char* getTime()
	{
		return this->time;
	}

	void setTime(const char* time)
	{
		if (strlen(time) != 4)
		{
			throw std::invalid_argument("the time should look like HH:MM");
		}

		for (int i = 0; i < strlen(time); i++)
		{
			if (time[i] < '0' || time[i] > '9')
			{
				throw std::invalid_argument("the time should look like HH:MM");
			}
		}

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
			throw std::invalid_argument("this name is too long. please enter a shorter name  Eg.: MGF, ASR etc.");
		}

		this->nameOfEvent = nameOfEvent;
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

	friend ostream& operator<<(ostream& output, const Event& Event)
	{
		output << "The name of this Event is: " << Event.nameOfEvent << endl;
		output << "The date is: " << Event.date << endl;
		output << "The time is: " << Event.time << endl;

		return output;
	}

	friend istream& operator>>(istream& input, Event& Event)
	{
		input >> Event.nameOfEvent;

		char date[1000], time[1000];
		int v[1000];
		input.getline(date, 1000);
		for (int i = 0; i < strlen(date); i++)
		{
			v[i] = date[i] - '0';
		}
		Event.setDate(v);

		input.getline(time, 1000);
		Event.setTime(time);

		return input;
	}
};


