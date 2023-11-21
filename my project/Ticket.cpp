
class Ticket
{
private:

	int Row;
	int Number;
	int Id;

public:

	Ticket()
	{

	}

	Ticket(int row, int number, int id)
	{
		this->Row = row;
		this->Number = number;
		this->Id = id;
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

};
