#ifndef day3_hpp
#define day3_hpp

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

const int DAY3_COURSE_WIDTH = 31;

typedef std::vector<std::vector<char>> Course;

Course getCourseTemplate(std::string path);
void expandCourseIfNeeded(int horizontalIndex, Course& course, const Course& courseTemplate);
void printCourse(const Course &course);
void traverseCourse(int startX, int startY, int ruleX, int ruleY, int &numTrees, Course& course, const Course& courseTemplate);

#endif
