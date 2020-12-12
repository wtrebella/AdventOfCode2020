#ifndef day6_h
#define day6_h

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>

struct GroupAnswers
{
	std::vector<std::string> answers;
};

const std::string DAY6_PATH = "data/day6.txt";
int getBinaryForQuestionsAnsweredByAll(GroupAnswers g);
int getBinaryForAnswer(std::string answer);
int getNumQuestionsAnsweredByAll(GroupAnswers g);
std::vector<GroupAnswers> getGroupAnswers(std::string path);
std::string getNonOverlapString(GroupAnswers g);
int getNumNonOverlappingYesses(GroupAnswers g);
void runDay6();

#endif