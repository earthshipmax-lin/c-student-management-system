#include "student.h"
#include <stdio.h>

// 打印学生信息
void printStudent(Student s) {
    printf("ID: %d, Name: %s, Score: %.2f\n", s.id, s.name, s.score);
}

// 这里可以实现更多学生相关函数，比如修改成绩、查找等