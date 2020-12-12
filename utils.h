#ifndef utils_hpp
#define utils_hpp

#include <vector>
#include <string>
#include <fstream>
#include <iostream>

std::vector<int> parseListOfInts(std::string path);
std::vector<std::string> splitString(std::string s, std::string delimiter);
std::string intToBinaryString(int i);
int stringToBinary(std::string s);

#endif 
