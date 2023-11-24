#include<iostream>
#include<string>
#include<stdexcept>

using namespace std;

class Location
{
private:
	int noOfSeats = 0;
	int noOfRows = 0;
	int noOfSeatsOccupied = 0;
	static int noOfLocations;

public:

	Location()
	{
		Location::noOfLocations++;
	}

	Location(int noOfSeats, int noOfRows, int noOfSeatsOccupied)
	{
		this->setNumberOfSeats(noOfSeats);
		this->setnoOfRows(noOfRows);
		this->setNoOfSeatsOccupied(noOfSeatsOccupied);

		Location::noOfLocations++;
	}

	~Location()
	{
		Location::noOfLocations--;
	}

	int getNumberOfSeats()
	{
		return this->noOfSeats;
	}

	void setNumberOfSeats(int numberOfSeats)
	{
		if (numberOfSeats > 1000 || numberOfSeats < 0) {
			throw std::invalid_argument("The number of seats can't be greater than 1000 or smaller than 0!");
		}

		this->noOfSeats = numberOfSeats;
	}

	void printNumberOfSeats()
	{
		cout << "this is the total no of seats: " << this->noOfSeats;
	}

	int getnoOfRows()
	{
		return this->noOfRows;
	}

	void setnoOfRows(int noOfRows)
	{
		if (noOfRows > 1000) {
			throw std::invalid_argument("The number of rows can't be greater than 1000!");
		}

		this->noOfRows = noOfRows;
	}

	int getNoOfSeatsOccupied()
	{
		return this->noOfSeatsOccupied;
	}

	void setNoOfSeatsOccupied(int noOfSeatsOccupied)
	{
		if (noOfSeatsOccupied > this->noOfSeats) {
			throw std::invalid_argument("Number of seats occupied has to be smaller than the total number of seats!");
		}

		this->noOfSeatsOccupied = noOfSeatsOccupied;
	}

	void PercentageOfOccupiedSeats()
	{
		double copie_noSeats = this->noOfSeats;
		double copie_occupiedSeats = this->noOfSeatsOccupied;
		double percentage = copie_occupiedSeats / copie_noSeats;

		cout << "Percentage of occupied seats is: " << percentage << "%" << endl;
	}

	void Availability()
	{
		cout << "the no of seats available is " << noOfSeats - noOfSeatsOccupied << endl;
	}

	bool operator <(const Location& location)
	{
		if (getNumberOfSeats() < location.noOfSeats)
		{
			return true;
		}

		return false;
	}

	bool operator >(const Location& location)
	{
		if (getNumberOfSeats() > location.noOfSeats)
		{
			return true;
		}

		return false;
	}

	friend ostream& operator<<(ostream& output, const Location& location)
	{
		output << "Numarul total de scaune ale acestei lcatii este: " << location.noOfSeats << endl;
		output << "Numarul de randuri ale acestei lcatii este: " << location.noOfRows << endl;
		output << "Numarul de locuri ocupate ale acestei lcatii este: " << location.noOfSeatsOccupied << endl;
	}

	friend istream& operator>>(istream& input, Location& location)
	{
		input >> location.noOfSeats >> location.noOfRows >> location.noOfSeatsOccupied;
	}

};

int Location::noOfLocations = 0;