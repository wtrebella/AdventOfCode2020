#ifndef day4_hpp
#define day4_hpp

#include <string>
#include <unordered_map>
#include <vector>
#include <iostream>
#include <fstream>

const std::string DAY4_PATH = "data/day4.txt";
const std::string DAY4_BYR = "byr";
const std::string DAY4_IYR = "iyr";
const std::string DAY4_EYR = "eyr";
const std::string DAY4_HGT = "hgt";
const std::string DAY4_HCL = "hcl";
const std::string DAY4_ECL = "ecl";
const std::string DAY4_PID = "pid";
const std::string DAY4_CID = "cid";

typedef std::unordered_map<std::string, std::string> PassportData;

std::vector<PassportData> parsePassportData(std::string path);
bool isPassportValid(PassportData p, bool validateFields);
bool entryExists(PassportData p, std::string key);
void printPassport(PassportData p, bool validateFields);
void runDay4();

#endif
