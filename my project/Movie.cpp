#include<iostream>
#include<string>

using namespace std;

class Movie {

private:
	int noOfSeats = 0;
	int noOfRows = 0;
	int date = 0;
	int time = 0;
	string nameOfMovie = " ";
	int noOfSeatsOccupied=0;

public:
	//default constructor
	Movie() {
		/*int noOfSeats = 0;
		int noOfRaws = 0;
		int date = 0;
		int time = 0;
		string nameOfMovie = " ";*/
	}

	Movie(int noOfSeats, int noOfRows, int date, int time, string nameOfMovie) {

		this->noOfSeats = noOfSeats;
		this->noOfRows = noOfRows;
		this->date = date;
		this->time = time;
		this->nameOfMovie = nameOfMovie;

	}

	int getNumberOfSeats()
	{
		return this->noOfSeats;
	}

	void setNumberOfSeats(int numberOfSeats)
	{
		if (numberOfSeats > 1000) {
			throw exception("this is the limit of our seats");
		}

		this->noOfSeats = numberOfSeats;
	}
	void printNumberOfSeats() {
		cout << "this is the total no of seats: "<<this->noOfSeats;
	}


	int getnoOfRows()
	{
		return this->noOfRows;
	}
	void setnoOfRows(int noOfRows)
	{
		if (noOfRows > 1000) {
			throw exception("this is the limit of our rows");
		}

		this->noOfRows = noOfRows;
	}



	int getDate()
	{
		return this->date;
	}
	void setDate(int date)
	{
		int c = 0;
		int cpy = date;
		while (cpy != 0) {
			c++;
			cpy = cpy / 10;
		}

		if (c != 8) {
			throw exception("the date should look like DD/MM/YYYY");
		}

		this->date = date;
	}

	int getTime()
	{
		return this->time;
	}
	void setTime(int time)
	{
		int c = 0;
		int cpy = time;
		while (cpy != 0) {
			c++;
			cpy = cpy / 10;
		}

		if (c != 4) {
			throw exception("the time should look like HH:MM");
		}

		this->time = time;
	}

	string getNameOfMovie()
	{
		return this->nameOfMovie;
	}
	void setNamrOfMovie(string nameOfMovie)
	{
		if (nameOfMovie.size()>50) {
			throw exception("this name is too long. please enter a shorter name  Eg.: MGF, ASR etc.");
		}

		this->nameOfMovie = nameOfMovie;
	}

	int getNoOfSeatsOccupied()
	{
		return this->noOfSeatsOccupied;
	}

	void setNoOfSeatsOccupied(int noOfSeatsOccupied)
	{
		if (noOfSeatsOccupied > this->noOfSeats) {
			throw exception("Number of seats occupied has to be smaller than the total number of seats!");
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
		cout << "the movie ivailable is " << nameOfMovie << endl;
		cout << "the no of seats available is " << noOfSeats-noOfSeatsOccupied << endl;
	}

	
};


//void operator<<(ostream& console, Movie movie) {
//
//	
//}