#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "student.h"
#include "file.h"


void saveToFile(Node* head) {
    FILE* fp = fopen("student.txt", "w");
    if (fp == NULL) {
        printf("文件打开失败! \n");
        return;
    }

    Node* p = head->next;
    while (p != NULL) {
        fprintf(fp, "%d %s %f\n",
                p->data.id,
                p->data.name,
                p->data.score);
            p = p->next;
    }

    fclose(fp);
}

void loadFromFile(Node* head) {
    FILE* fp = fopen("student.txt", "r");
    if (fp == NULL) {
        return;
    }

Student s;

while (fscanf(fp, "%d %s %f",
                &s.id,
                s.name,
                &s.score) == 3) {

    insertHead(head, s);
    }

    fclose(fp);
}