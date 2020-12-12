#include "utils.h"
#include "day5.h"

using namespace std;

vector<string> splitBoardingPass(string boardingPass)
{
	vector<string> v;

	if ((int)boardingPass.size() != 10)
	{
		cout << "Invalid boarding pass: " << boardingPass << endl;
		return v;
	}

	v.push_back(boardingPass.substr(0, 7));
	v.push_back(boardingPass.substr(7, boardingPass.size()));
	return v;
}


int getRow(string rowString)
{
	if ((int)rowString.size() != 7)
	{
		cout << "Invalid row string length: " << rowString << endl;
		return -1;
	}

	int min = 0;
	int max = 128;

	for (int i = 0; i < 7; i++)
	{
		char c = rowString[i];
		if (c == 'F')
		{
			max = (max - min) / 2 + min;
		}
		else if (c == 'B')
		{
			min = (max - min) / 2 + min;
		}
	}

	return min;
}

int getColumn(string columnString)
{
	if ((int)columnString.size() != 3)
	{
		cout << "Invalid column string length: " << columnString << endl;
		return -1;
	}

	int min = 0;
	int max = 8;

	for (int i = 0; i < 3; i++)
	{
		char c = columnString[i];
		if (c == 'L')
		{
			max = (max - min) / 2 + min;
		}
		else if (c == 'R')
		{
			min = (max - min) / 2 + min;
		}
	}

	return min;
}

int getSeatID(int row, int column)
{
	return row * 8 + column;
}

bool compareByRow(const Seat &bp1, const Seat &bp2)
{
	return bp1.row < bp2.row;
}

bool compareByColumn(const Seat& bp1, const Seat& bp2)
{
	return bp1.column < bp2.column;
}

bool compareBySeatID(const Seat& bp1, const Seat& bp2)
{
	return bp1.seatID < bp2.seatID;
}

vector<string> getBoardingPassStrings(string path)
{
	ifstream file(path);
	string line;
	vector<string> v;

	if (file.is_open())
	{
		while (getline(file, line))
		{
			v.push_back(line);
		}
		file.close();
	}
	else
	{
		cout << "Unable to open file";
	}

	return v;
}

vector<Seat> getSeats(string path)
{
	vector<Seat> v;
	vector<string> strings = getBoardingPassStrings(path);

	for (int i = 0; i < (int)strings.size(); i++)
	{
		string s = strings[i];
		vector<string> splitStrings = splitBoardingPass(s);
		
		int row = getRow(splitStrings[0]);
		int column = getColumn(splitStrings[1]);
		int seatID = getSeatID(row, column);

		Seat boardingPass;
		boardingPass.row = row;
		boardingPass.column = column;
		boardingPass.seatID = seatID;

		v.push_back(boardingPass);
	}

	return v;
}

void runDay5()
{
	cout << "Day 5" << endl;
	cout << "=================================================" << endl;

	vector<Seat> seats = getSeats(DAY5_PATH);
	sort(seats.begin(), seats.end(), compareBySeatID);
	cout << "  Puzzle 1" << endl;
	cout << "    Max seat ID: " << seats[seats.size() - 1].seatID << endl;

	cout << "  Puzzle 2" << endl;
	int prevID = seats[0].seatID;
	for (vector<int>::size_type i = 0; i < seats.size(); i++)
	{
		Seat seat = seats[i];
		if (seat.seatID - prevID > 1)
		{
			cout << "    Your seat ID: " << seat.seatID - 1 << endl;
			break;
		}
		prevID = seat.seatID;
	}
	
	cout << "=================================================" << endl;
	cout << endl;
}
