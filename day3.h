#ifndef day3_h
#define day3_h

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

const int DAY3_COURSE_WIDTH = 31;
const std::string DAY3_PATH = "data/day3.txt";

typedef std::vector<std::vector<char>> Course;

Course getCourseTemplate(std::string path);
void runDay3();
void expandCourseIfNeeded(int horizontalIndex, Course& course, const Course& courseTemplate);
void printCourse(const Course &course);
void traverseCourse(int startX, int startY, int ruleX, int ruleY, int &numTrees, Course& course, const Course& courseTemplate);

#endif
