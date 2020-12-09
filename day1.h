#ifndef day1_hpp
#define day1_hpp

#include <vector>
#include <string>
#include <fstream>
#include <iostream>

const std::string DAY1_PATH = "data/day1.txt";

void runDay1();
void getNumsThatAddToVal(int &a, int &b, int val, std::vector<int> &nums);
void getNumsThatAddToVal(int &a, int &b, int &c, int val, std::vector<int> &nums);
std::vector<int> parseListOfInts(std::string path);

#endif
