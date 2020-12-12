#ifndef day5_hpp
#define day5_hpp

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>

struct Seat
{
	int row = 0;
	int column = 0;
	int seatID = 0;
};

const std::string DAY5_PATH = "data/day5.txt";

std::vector<std::string> splitBoardingPass(std::string boardingPass);
int getRow(std::string rowString);
int getColumn(std::string columnString);
int getSeatID(int row, int column);
void runDay5();
std::vector<std::string> getBoardingPassStrings(std::string path);
std::vector<Seat> getSeats(std::string path);
bool compareByRow(const Seat& bp1, const Seat& bp2);
bool compareByColumn(const Seat& bp1, const Seat& bp2);
bool compareBySeatID(const Seat& bp1, const Seat& bp2);

#endif 
