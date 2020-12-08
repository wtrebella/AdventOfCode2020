#include "day3.h"

using namespace std;

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

