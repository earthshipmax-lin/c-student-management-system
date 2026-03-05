#ifndef LIST_H
#define LIST_H

#include "student.h"

// 链表节点结构
typedef struct Node {
    Student data;
    struct Node* next;
} Node;

// 链表基本操作
Node* initList();
void insertHead(Node* head, Student s);
void printList(Node* head);
int getLength(Node* head);
int deleteById(Node* head, int id);
Node* findById(Node* head, int id);
void updateStudent(Node* head);
void sortByScore(Node* head);
void statistics(Node* head);
void clearList(Node* head);

#endif