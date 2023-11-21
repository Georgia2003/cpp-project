
#include "Ticket.cpp"
#include "Movie.cpp"
using namespace std;

enum MovieZone { NORMAL = 0, VIP = 1 };

class MovieTicket : public Ticket
{
private:
	MovieZone Zone = MovieZone::NORMAL;

public:

	MovieTicket()
	{

	}

	MovieTicket(int Row, int Number, int Id, MovieZone zone)
	{

		setRow(Row);
		setNumber(Number);
		setId(Id);
		this->Zone = zone;
	}

	int getZone()
	{
		return this->Zone;
	}
	void setZone(MovieZone zone)
	{
		if (zone != NORMAL && zone != VIP) {
			throw exception("this tiket should be NORMAL or VIP only");
		}
		else {
			this->Zone = zone;
		}
	}

};