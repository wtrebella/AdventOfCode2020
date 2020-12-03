#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct PasswordEntry
{
    char specialChar;
    int val1;
    int val2;
    string password;
};

// day 2
void removeInvalidEntries(vector<PasswordEntry> &entries, bool validation (PasswordEntry));
vector<int> parseListOfInts(string path);
vector<PasswordEntry> parsePasswordEntries(string path);
bool isValidForPuz1(PasswordEntry entry);
bool isValidForPuz2(PasswordEntry entry);

// day 1
void getNumsThatAddToVal(int &a, int &b, int val, vector<int> &nums);
void getNumsThatAddToVal(int &a, int &b, int &c, int val, vector<int> &nums);



int main()
{
    vector<int> nums = parseListOfInts("data/day1.txt");

    // Day 1 Puzzle 1
    int a = -1;
    int b = -1;
    int c = -1;

    getNumsThatAddToVal(a, b, 2020, nums);
 
    cout << "Day 1 Puzzle 1: a = " << a << ", b = " << b << ", a + b = " << (a + b) << ", a * b = " << (a * b) << endl;

    // Day 1 Puzzle 2
    getNumsThatAddToVal(a, b, c, 2020, nums);

    cout << "Day 1 Puzzle 2: a = " << a << ", b = " << b << ", c = " << c << ", a + b + c = " << (a + b + c) << ", a * b * c = " << (a * b * c) << endl;

    // Day 2 Puzzle 1
    vector <PasswordEntry> passwordEntries = parsePasswordEntries("data/day2.txt");
    vector <PasswordEntry> puz1validEntries = passwordEntries;

    removeInvalidEntries(puz1validEntries, isValidForPuz1);

    cout << "Day 2 Puzzle 1: number of valid passwords = " << puz1validEntries.size() << endl;

    // Day 2 Puzzle 2
    vector <PasswordEntry> puz2validEntries = passwordEntries;

    removeInvalidEntries(puz2validEntries, isValidForPuz2);

    cout << "Day 2 Puzzle 2: number of valid passwords = " << puz2validEntries.size() << endl;

    return 0;
}

void removeInvalidEntries(vector<PasswordEntry> &entries, bool validation (PasswordEntry))
{
    auto it = entries.begin();
    while (it != entries.end())
    {
        PasswordEntry e = *it;
        if (validation(e))
        {
            ++it;
        }
        else
        {
            it = entries.erase(it);
        }
    }
}

bool isValidForPuz1(PasswordEntry entry)
{
    size_t n = count(entry.password.begin(), entry.password.end(), entry.specialChar);
    return n >= entry.val1 && n <= entry.val2;
}

bool isValidForPuz2(PasswordEntry entry)
{
    int index1 = entry.val1 - 1;
    int index2 = entry.val2 - 1;

    bool charIsInVal1Spot = entry.password[index1] == entry.specialChar;
    bool charIsInVal2Spot = entry.password[index2] == entry.specialChar;

    return !(charIsInVal1Spot && charIsInVal2Spot) && (charIsInVal1Spot || charIsInVal2Spot);
}

vector<PasswordEntry> parsePasswordEntries(string path)
{
    string line;
    vector<PasswordEntry> entries;
    ifstream file(path);
    if (file.is_open())
    {
        while (getline(file, line))
        {
            string temp, numRule, password;
            char specialChar;
            int step = 0;

            for (string::iterator it = line.begin(); it != line.end(); ++it)
            {
                if (*it == ' ')
                {
                    switch (step)
                    {
                    case 0:
                        numRule = temp;
                        break;
                    case 1:
                        specialChar = temp[0];
                        break;
                    default:
                        cout << "Shouldn't get here!";
                    }

                    temp = "";
                    step++;
                }
                else
                {
                    temp += *it;
                }
            }

            password = temp;

            size_t dashLocation = numRule.find('-');
            string val1string = numRule.substr(0, dashLocation);
            string val2string = numRule.substr(dashLocation + 1);
            
            int val1 = stoi(val1string);
            int val2 = stoi(val2string);

            PasswordEntry pe;
            pe.specialChar = specialChar;
            pe.val1 = val1;
            pe.val2 = val2;
            pe.password = password;

            entries.push_back(pe);
        }
        file.close();
    }
    else
    {
        cout << "Unable to open file";
    }

    return entries;
}

vector<int> parseListOfInts(string path)
{
    string line;
    vector<int> nums;
    ifstream file(path);
    if (file.is_open())
    {
        while (getline(file, line))
        {
            int num = stoi(line);
            nums.push_back(num);
        }
        file.close();
    }
    else 
    {
        cout << "Unable to open file";
    }

    return nums;
}

void getNumsThatAddToVal(int &a, int &b, int val, vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        int aTemp = nums[i];

        for (int j = 0; j < nums.size(); j++)
        {
            if (j == i)
            {
                continue;
            }

            int bTemp = nums[j];

            if (aTemp + bTemp == val)
            {
                a = aTemp;
                b = bTemp;
                return;
            }
        }
    }
}

void getNumsThatAddToVal(int &a, int &b, int &c, int val, vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        int aTemp = nums[i];

        for (int j = 0; j < nums.size(); j++)
        {
            if (j == i)
            {
                continue;
            }

            int bTemp = nums[j];

            for (int k = 0; k < nums.size(); k++)
            {
                if (k == j)
                {
                    continue;
                }

                int cTemp = nums[k];

                if (aTemp + bTemp + cTemp == val)
                {
                    a = aTemp;
                    b = bTemp;
                    c = cTemp;
                    return;
                }
            }
        }
    }
}
