#ifndef utils_h
#define utils_h

#include <vector>
#include <string>
#include <fstream>
#include <iostream>

std::vector<int> parseListOfInts(std::string path);
std::vector<std::string> splitString(std::string s, std::string delimiter);
std::string intTo8BitBinaryString(int i);
int stringToBinary(std::string s);
std::string intTo32BitBinaryString(int i);
bool stringContainsChar(std::string s, char c);
int getNumSetBits(int i);

#endif 
