#ifndef day2_h
#define day2_h

#include <vector>
#include <string>
#include <iostream>
#include <fstream>

const std::string DAY2_PATH = "data/day2.txt";

struct PasswordEntry
{
    char specialChar = ' ';
    int val1 = 0;
    int val2 = 0;
    std::string password;
};

void runDay2();
void removeInvalidEntries(std::vector<PasswordEntry> &entries, bool validation (PasswordEntry));
std::vector<PasswordEntry> parsePasswordEntries(std::string path);
bool isValidForPuz1(PasswordEntry entry);
bool isValidForPuz2(PasswordEntry entry);

#endif
