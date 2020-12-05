#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <cstring>

using namespace std;

// day 1
void getNumsThatAddToVal(int &a, int &b, int val, vector<int> &nums);
void getNumsThatAddToVal(int &a, int &b, int &c, int val, vector<int> &nums);

// day 2
struct PasswordEntry
{
    char specialChar;
    int val1;
    int val2;
    string password;
};

void removeInvalidEntries(vector<PasswordEntry> &entries, bool validation (PasswordEntry));
vector<int> parseListOfInts(string path);
vector<PasswordEntry> parsePasswordEntries(string path);
bool isValidForPuz1(PasswordEntry entry);
bool isValidForPuz2(PasswordEntry entry);

// day 3
const int DAY3_COURSE_WIDTH = 31;

typedef vector<vector<char>> Course;

Course getCourseTemplate(string path);
Course courseTemplate;
Course course;
void expandCourseIfNeeded(int horizontalIndex, Course& course, const Course& courseTemplate);
void printCourse(const Course &course);
void traverseCourse(int startX, int startY, int ruleX, int ruleY, int &numTrees, Course& course, const Course& courseTemplate);

// day 4
const string DAY4_BYR = "byr";
const string DAY4_IYR = "iyr";
const string DAY4_EYR = "eyr";
const string DAY4_HGT = "hgt";
const string DAY4_HCL = "hcl";
const string DAY4_ECL = "ecl";
const string DAY4_PID = "pid";
const string DAY4_CID = "cid";

typedef unordered_map<string, string> PassportData;

vector<string> splitString(string s, string delimiter);
vector<PassportData> parsePassportData(string path);
bool isPassportValid(PassportData p, bool validateFields);
bool entryExists(PassportData p, string key);
void printPassport(PassportData p, bool validateFields);

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

    // Day 3 Puzzle 1
    courseTemplate = getCourseTemplate("data/day3.txt");
    expandCourseIfNeeded(DAY3_COURSE_WIDTH * 4, course, courseTemplate);

    int numTreesPuz1 = 0;
    traverseCourse(0, 0, 3, 1, numTreesPuz1, course, courseTemplate);

    cout << "Day 3 Puzzle 1: number of trees = " << numTreesPuz1 << endl;

    int numTrees1 = 0; 
    traverseCourse(0, 0, 1, 1, numTrees1, course, courseTemplate);

    int numTrees2 = 0;
    traverseCourse(0, 0, 3, 1, numTrees2, course, courseTemplate);

    int numTrees3 = 0;
    traverseCourse(0, 0, 5, 1, numTrees3, course, courseTemplate);

    int numTrees4 = 0;
    traverseCourse(0, 0, 7, 1, numTrees4, course, courseTemplate);

    int numTrees5 = 0;
    traverseCourse(0, 0, 1, 2, numTrees5, course, courseTemplate);

    long long numTreesMultPuz2 = (long long)numTrees1 * numTrees2 * numTrees3 * numTrees4 * numTrees5;

    cout << "Day 3 Puzzle 2: " << numTrees1 << " * " << numTrees2 << " * " << numTrees3 << " * " << numTrees4 << " * " << numTrees5 << " = " << numTreesMultPuz2 << endl;
    
    // Day 4 Puzzle 1
    vector<PassportData> passports = parsePassportData("data/day4.txt");
    int numValidPassports = 0;
    
    for (int i = 0; i < passports.size(); i++)
    {
        if (isPassportValid(passports[i], false))
        {
            numValidPassports++;
        }
    }
    cout << "Day 4 Puzzle 1: number of valid passports = " << numValidPassports << endl;

    numValidPassports = 0;
    for (int i = 0; i < passports.size(); i++)
    {
        if (isPassportValid(passports[i], true))
        {
            numValidPassports++;
        }
        //printPassport(passports[i], true);
    }
    cout << "Day 4 Puzzle 2: number of valid passports = " << numValidPassports << endl;
    return 0;
}

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

void traverseCourse(int startX, int startY, int ruleX, int ruleY, int &numTrees, Course& course, const Course &courseTemplate)
{
    if (ruleX == 0 || ruleY == 0)
    {
        cout << "x and y rules must be over 0" << endl;
    }

    int height = course.size();

    expandCourseIfNeeded(startX, course, courseTemplate);
    if (course[startY][startX] == '#')
    {
        numTrees++;
    }

    int newX = startX + ruleX;
    int newY = startY + ruleY;

    if (newY >= height)
    {
        return;
    }
    else
    {
        traverseCourse(newX, newY, ruleX, ruleY, numTrees, course, courseTemplate);
    }
}

void printCourse(const Course& course)
{
    for (int i = 0; i < course.size(); i++)
    {
        string line(course[i].begin(), course[i].end());
        cout << line << endl;
    }
}

void expandCourseIfNeeded(int horizontalIndex, Course &course, const Course& courseTemplate)
{
    if (course.size() == 0)
    {
        course = courseTemplate;
    }

    int targetWidth = DAY3_COURSE_WIDTH * (horizontalIndex / DAY3_COURSE_WIDTH + 1);
    
    while (course[0].size() < targetWidth)
    {
        for (int i = 0; i < course.size(); i++)
        {
            const vector<char> lineTemplate = courseTemplate[i];
            course[i].insert(course[i].end(), lineTemplate.begin(), lineTemplate.end());
        }
    }
}

Course getCourseTemplate(string path)
{
    string line;
    ifstream file(path);
    Course courseTemplate;
    if (file.is_open())
    {
        while (getline(file, line))
        {
            vector<char> lineVect(line.begin(), line.end());
            courseTemplate.push_back(lineVect);
        }
    }

    return courseTemplate;
}

void printCourse(Course course)
{
    for (int i = 0; i < course.size(); i++)
    {
        string line(course[i].begin(), course[i].end());
        cout << line << endl;
    }
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
