#include "day1.h"

using namespace std;

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

void getNumsThatAddToVal(int &a, int &b, int val, vector<int> &nums)
{
    for (int i = 0; i < (int)nums.size(); i++)
    {
        int aTemp = nums[i];

        for (int j = 0; j < (int)nums.size(); j++)
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
    for (int i = 0; i < (int)nums.size(); i++)
    {
        int aTemp = nums[i];

        for (int j = 0; j < (int)nums.size(); j++)
        {
            if (j == i)
            {
                continue;
            }

            int bTemp = nums[j];

            for (int k = 0; k < (int)nums.size(); k++)
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