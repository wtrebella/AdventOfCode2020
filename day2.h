#ifndef day2_hpp
#define day2_hpp

#include <vector>
#include <string>
#include <iostream>
#include <fstream>

struct PasswordEntry
{
    char specialChar;
    int val1;
    int val2;
    std::string password;
};

void removeInvalidEntries(std::vector<PasswordEntry> &entries, bool validation (PasswordEntry));
std::vector<int> parseListOfInts(std::string path);
std::vector<PasswordEntry> parsePasswordEntries(std::string path);
bool isValidForPuz1(PasswordEntry entry);
bool isValidForPuz2(PasswordEntry entry);

#endif
