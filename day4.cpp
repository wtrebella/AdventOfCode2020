#include "day4.h"

using namespace std;

void printPassport(PassportData p, bool validateFields)
{
    string validity;
    if (isPassportValid(p, validateFields))
    {
        validity = "Valid: ";
    }
    else
    {
        validity = "Invalid: ";
    }

    cout <<
        validity <<
        DAY4_BYR << ":" << entryExists(p, DAY4_BYR) << " " <<
        DAY4_IYR << ":" << entryExists(p, DAY4_IYR) << " " <<
        DAY4_EYR << ":" << entryExists(p, DAY4_EYR) << " " <<
        DAY4_HGT << ":" << entryExists(p, DAY4_HGT) << " " <<
        DAY4_HCL << ":" << entryExists(p, DAY4_HCL) << " " <<
        DAY4_ECL << ":" << entryExists(p, DAY4_ECL) << " " <<
        DAY4_PID << ":" << entryExists(p, DAY4_PID) << " " <<
        DAY4_CID << ":" << entryExists(p, DAY4_CID) << endl;
}

bool isPassportValid(PassportData p, bool validateFields)
{
    // validate overall
    bool hasRequiredFields =
        entryExists(p, DAY4_BYR) &&
        entryExists(p, DAY4_IYR) &&
        entryExists(p, DAY4_EYR) &&
        entryExists(p, DAY4_HGT) &&
        entryExists(p, DAY4_HCL) &&
        entryExists(p, DAY4_ECL) &&
        entryExists(p, DAY4_PID);

    if (!hasRequiredFields)
    {
        return false;
    }

    if (!validateFields)
    {
        return hasRequiredFields;
    }

    // validate birth year
    string byr = p[DAY4_BYR];
    if (byr.length() != 4)
    {
        return false;
    }

    int byrInt = stoi(byr);
    if (byrInt < 1920 || byrInt > 2002)
    {
        return false;
    }

    // validate issue year
    string iyr = p[DAY4_IYR];
    if (iyr.length() != 4)
    {
        return false;
    }
    
    int iyrInt = stoi(iyr);
    if (iyrInt < 2010 || iyrInt > 2020)
    {
        return false;
    }

    // validate expiration year
    string eyr = p[DAY4_EYR];
    if (eyr.length() != 4)
    {
        return false;
    }
    int eyrInt = stoi(eyr);
    if (eyrInt < 2020 || eyrInt > 2030)
    {
        return false;
    }

    // validate height
    string hgt = p[DAY4_HGT];
    auto cmIt = hgt.find("cm");
    auto inIt = hgt.find("in");
    if (cmIt != string::npos)
    {
        hgt.erase(cmIt, 2);
        int hgtInt = stoi(hgt);
        if (hgtInt < 150 || hgtInt > 193)
        {
            return false;
        }
    }
    else if (inIt != string::npos)
    {
        hgt.erase(inIt, 2);
        int hgtInt = stoi(hgt);
        if (hgtInt < 59 || hgtInt > 76)
        {
            return false;
        }
    }
    else
    {
        return false;
    }

    // validate hair color
    string hcl = p[DAY4_HCL];
    if (hcl[0] != '#')
    {
        return false;
    }

    if (hcl.length() != 7)
    {
        return false;
    }

    for (int i = 1; i < 7; i++)
    {
        char c = hcl[i];
        if (
            c != '0' &&
            c != '1' &&
            c != '2' &&
            c != '3' &&
            c != '4' &&
            c != '5' &&
            c != '6' &&
            c != '7' &&
            c != '8' &&
            c != '9' &&
            c != 'a' &&
            c != 'b' &&
            c != 'c' &&
            c != 'd' &&
            c != 'e' &&
            c != 'f'
            )
        {
            return false;
        }
    }

    // validate eye color
    string ecl = p[DAY4_ECL];
    const char* eclCStr = ecl.c_str();
    if (
        strcmp(eclCStr, "amb") != 0 &&
        strcmp(eclCStr, "blu") != 0 &&
        strcmp(eclCStr, "brn") != 0 &&
        strcmp(eclCStr, "gry") != 0 &&
        strcmp(eclCStr, "grn") != 0 &&
        strcmp(eclCStr, "hzl") != 0 &&
        strcmp(eclCStr, "oth")
        )
    {
        return false;
    }

    // validate passport id
    string pid = p[DAY4_PID];
    if (pid.length() != 9)
    {
        return false;
    }

    return true;
}

bool entryExists(PassportData p, string key)
{
    return p.find(key) != p.end();
}

vector<string> splitString(string s, string delimiter)
{
    vector<string> v;

    size_t pos = 0;
    string token;
    while ((pos = s.find(delimiter)) != string::npos)
    {
        token = s.substr(0, pos);
        s.erase(0, pos + delimiter.length());
        v.push_back(token);
    }
    if (!s.empty())
    {
        v.push_back(s);
    }

    return v;
}

vector<PassportData> parsePassportData(string path)
{
    vector<PassportData> v;

    ifstream file(path);
    string line;
    PassportData curPassportData;

    if (file.is_open())
    {
        while (getline(file, line))
        {
            if (line.empty())
            {
                v.push_back(curPassportData);
                curPassportData = PassportData();
            }
            else
            {
                vector<string> tokens = splitString(line, " ");
                for (int i = 0; i < tokens.size(); i++)
                {
                    string t = tokens[i];
                    vector<string> kvp = splitString(t, ":");
                    curPassportData[kvp[0]] = kvp[1];
                }
            }
        }
        v.push_back(curPassportData);
    }

    return v;
}

