#include "utils.h"

using namespace std;

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

int stringToBinary(std::string s)
{
    if ((int)s.size() > 8)
    {
        cout << "Strings greater than 8 digits unsupported" << endl;
    }

    int b = 0;
    int width = (int)s.size();
    for (int i = 0; i < width; i++)
    {
        if (s[i] == '1')
        {
            int shiftAmt = width - i - 1;
            b |= (1 << shiftAmt);
        }
    }

    return b;
}

string intToBinaryString(int num)
{
    int lostData = 4294967295 - 255; //11111111111111111111111100000000

    if ((lostData & num) != 0)
    {
        num &= ~lostData;
        cout << "The input value is using more than 8 bits; this extra data will be lost. Remaining value: " << num << endl;
    }

    string s(8, ' ');

    for (int i = 7; i >= 0; i--)
    {
        int cIndex = 8 - i - 1;

        s[cIndex] = (1 << i) & num ? '1' : '0';
    }

    return s;
}