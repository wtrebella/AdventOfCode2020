#include "main.h"
#include "day1.h"
#include "day2.h"
#include "day3.h"
#include "day4.h"
#include "day5.h"

using namespace std;

const string DAY1_PATH = "data/day1.txt";
const string DAY2_PATH = "data/day2.txt";
const string DAY3_PATH = "data/day3.txt";
const string DAY4_PATH = "data/day4.txt";

int main()
{
    runDay1();
    runDay2();
    runDay3();
    runDay4();
    
    return 0;
}

void runDay1()
{
    vector<int> nums = parseListOfInts(DAY1_PATH);

   // puzzle 1
   int a = -1;
   int b = -1;
   int c = -1;

   getNumsThatAddToVal(a, b, 2020, nums);

   cout << "Day 1" << endl;
   cout << "=================================================" << endl;
   cout << "  Puzzle 1" << endl;
   cout << "    a = " << a << ", b = " << b << ", a + b = " << (a + b) << ", a * b = " << (a * b) << endl;

   // puzzle 2
   getNumsThatAddToVal(a, b, c, 2020, nums);

   cout << "  Puzzle 2" << endl;
   cout << "    a = " << a << ", b = " << b << ", c = " << c << ", a + b + c = " << (a + b + c) << ", a * b * c = " << (a * b * c) << endl;
   cout << "=================================================" << endl;
   cout << endl;
}

void runDay2()
{
    // puzzle 1
    vector <PasswordEntry> passwordEntries = parsePasswordEntries(DAY2_PATH);
    vector <PasswordEntry> puz1validEntries = passwordEntries;

    removeInvalidEntries(puz1validEntries, isValidForPuz1);

    cout << "Day 2" << endl;
    cout << "=================================================" << endl;
    cout << "  Puzzle 1" << endl;
    cout << "    number of valid passwords = " << puz1validEntries.size() << endl;

    // puzzle 2
    vector <PasswordEntry> puz2validEntries = passwordEntries;
    
    removeInvalidEntries(puz2validEntries, isValidForPuz2);

    cout << "  Puzzle 2" << endl;
    cout << "    number of valid passwords = " << puz2validEntries.size() << endl;
    cout << "=================================================" << endl;
    cout << endl;
}

void runDay3()
{
    // puzzle 1
    Course courseTemplate = getCourseTemplate(DAY3_PATH);
    Course course;
    
    expandCourseIfNeeded(DAY3_COURSE_WIDTH * 4, course, courseTemplate);

    int numTreesPuz1 = 0;
    traverseCourse(0, 0, 3, 1, numTreesPuz1, course, courseTemplate);

    cout << "Day 3" << endl;
    cout << "=================================================" << endl;
    cout << "  Puzzle 1" << endl;
    cout << "    number of trees = " << numTreesPuz1 << endl;

    // puzzle 2
    
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

    cout << "  Puzzle 2" << endl;
    cout << "    " << numTrees1 << " * " << numTrees2 << " * " << numTrees3 << " * " << numTrees4 << " * " << numTrees5 << " = " << numTreesMultPuz2 << endl;
    cout << "=================================================" << endl;
    cout << endl;
}

void runDay4()
{
    // puzzle 1
    
    vector<PassportData> passports = parsePassportData(DAY4_PATH);
    int numValidPassports = 0;
    
    for (int i = 0; i < passports.size(); i++)
    {
        if (isPassportValid(passports[i], false))
        {
            numValidPassports++;
        }
    }
    
    cout << "Day 4" << endl;
    cout << "=================================================" << endl;
    cout << "  Puzzle 1" << endl;
    cout << "    number of valid passports = " << numValidPassports << endl;

    // puzzle 2
    
    numValidPassports = 0;
    for (int i = 0; i < passports.size(); i++)
    {
        if (isPassportValid(passports[i], true))
        {
            numValidPassports++;
        }
    }
    cout << "  Puzzle 2" << endl;
    cout << "    number of valid passports = " << numValidPassports << endl;
    cout << "=================================================" << endl;
    cout << endl;
}
