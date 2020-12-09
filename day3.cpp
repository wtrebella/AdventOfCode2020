#include "day3.h"

using namespace std;

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

void traverseCourse(int startX, int startY, int ruleX, int ruleY, int &numTrees, Course& course, const Course &courseTemplate)
{
    if (ruleX == 0 || ruleY == 0)
    {
        cout << "x and y rules must be over 0" << endl;
    }

    int height = (int)course.size();

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
    for (int i = 0; i < (int)course.size(); i++)
    {
        string line(course[i].begin(), course[i].end());
        cout << line << endl;
    }
}

void expandCourseIfNeeded(int horizontalIndex, Course &course, const Course& courseTemplate)
{
    if ((int)course.size() == 0)
    {
        course = courseTemplate;
    }

    int targetWidth = DAY3_COURSE_WIDTH * (horizontalIndex / DAY3_COURSE_WIDTH + 1);
    
    while ((int)course[0].size() < targetWidth)
    {
        for (int i = 0; i < (int)course.size(); i++)
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
    for (int i = 0; i < (int)course.size(); i++)
    {
        string line(course[i].begin(), course[i].end());
        cout << line << endl;
    }
}

