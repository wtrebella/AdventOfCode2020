#include "day2.h"

using namespace std;

void runDay2()
{
    // puzzle 1
    vector <PasswordEntry> passwordEntries = parsePasswordEntries(DAY2_PATH);
    vector <PasswordEntry> puz1validEntries = passwordEntries;

    removeInvalidEntries(puz1validEntries, isValidForPuz1);

    cout << "Day 2" << endl;
    cout << "=================================================" << endl;
    cout << "  Puzzle 1" << endl;
    cout << "    number of valid passwords = " << (int)puz1validEntries.size() << endl;

    // puzzle 2
    vector <PasswordEntry> puz2validEntries = passwordEntries;

    removeInvalidEntries(puz2validEntries, isValidForPuz2);

    cout << "  Puzzle 2" << endl;
    cout << "    number of valid passwords = " << (int)puz2validEntries.size() << endl;
    cout << "=================================================" << endl;
    cout << endl;
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
    return n >= (size_t)entry.val1 && n <= (size_t)entry.val2;
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
            char specialChar = ' ';
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