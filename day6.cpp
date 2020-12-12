#include "utils.h"
#include "day6.h"

using namespace std;

vector<GroupAnswers> getGroupAnswers(string path)
{
	vector<GroupAnswers> v;
	GroupAnswers groupAnswers;
	ifstream file(path);
	string line;
	if (file.is_open())
	{
		while (getline(file, line))
		{
			if (line.empty())
			{
				v.push_back(groupAnswers);
				groupAnswers = GroupAnswers();
			}
			else
			{
				sort(line.begin(), line.end());
				groupAnswers.answers.push_back(line);
			}
		}

		v.push_back(groupAnswers);
	}
	else
	{
		cout << "Unable to open file at path " << path << endl;
	}

	return v;
}

int getBinaryForQuestionsAnsweredByAll(GroupAnswers g)
{
	int binary = 0;

	for (vector<string>::size_type i = 0; i < g.answers.size(); i++)
	{
		string answer = g.answers[i];
		int answerBinary = getBinaryForAnswer(answer);
		if (i == 0)
		{
			binary = answerBinary;
		}
		else
		{
			binary &= answerBinary;
		}		
	}

	return binary;
}

int getNumQuestionsAnsweredByAll(GroupAnswers g)
{
	int binary = getBinaryForQuestionsAnsweredByAll(g);
	return getNumSetBits(binary);
}

int getBinaryForAnswer(string answer)
{
	int binary = 0;
	int shift = 25;
	for (char c = 'a'; c <= 'z'; c++)
	{
		if (stringContainsChar(answer, c))
		{
			binary |= (1 << shift);
		}

		shift--;
	}

	return binary;
}

string getNonOverlapString(GroupAnswers g)
{
	string nonOverlapString;
	for (vector<string>::size_type i = 0; i < g.answers.size(); i++)
	{
		string a = g.answers[i];
		for (string::size_type j = 0; j < a.size(); j++)
		{
			char c = a[j];
			if (!stringContainsChar(nonOverlapString, c))
			{
				nonOverlapString += c;
			}
		}
	}
	sort(nonOverlapString.begin(), nonOverlapString.end());
	return nonOverlapString;
}

int getNumNonOverlappingYesses(GroupAnswers g)
{
	string nonOverlapString = getNonOverlapString(g);
	return (int)nonOverlapString.size();
}

void runDay6()
{
	vector<GroupAnswers> groupAnswersVect = getGroupAnswers(DAY6_PATH);

	int numORYesses = 0;
	for (vector<GroupAnswers>::size_type i = 0; i < groupAnswersVect.size(); i++)
	{
		GroupAnswers g = groupAnswersVect[i];
		numORYesses += getNumNonOverlappingYesses(g);
	}

	int numANDYesses = 0;
	for (vector<GroupAnswers>::size_type i = 0; i < groupAnswersVect.size(); i++)
	{
		GroupAnswers g = groupAnswersVect[i];
		numANDYesses += getNumQuestionsAnsweredByAll(g);
	}

	cout << "Day 1" << endl;
	cout << "=================================================" << endl;
	cout << "  Puzzle 1" << endl;
	cout << "    number of OR yesses: " << numORYesses << endl;

	cout << "  Puzzle 2" << endl;
	cout << "    number of AND yesses: " << numANDYesses << endl;
	cout << "=================================================" << endl;
	cout << endl;
}