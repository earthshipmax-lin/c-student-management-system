#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

// 单链表结点

// 初始化链表（带头结点）
Node* initList() {
    Node* head = (Node*)malloc(sizeof(Node));
    if (head == NULL) {
        printf("内存分配失败\n");
        exit(1);
    }
    head->next = NULL;
    return head;
}

//头插法插入学生
void insertHead(Node* head, Student s) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("内存分配失败\n");
        return;
    }

    newNode->data = s;
    newNode->next = head->next;
    head->next = newNode;

}

//遍历链表
void printList(Node* head) {
    Node* p = head->next;

    while (p != NULL) {
        printf("ID: %d, Name: %s, Score: %.1f\n",
                p->data.id,
                p->data.name,
                p->data.score);
        p = p->next;
    }
}

//求表长
int getLength(Node* head) {
    int count = 0;
    Node* p = head->next;

    while (p !=NULL) {
        count++;
        p = p->next;
    }

    return count;
}

//删除函数
int deleteById(Node* head, int id) {
    Node* p = head;

    while (p->next != NULL) {
        if (p->next->data.id == id) {
            Node* temp = p->next;
            p->next = temp->next;
            free(temp);
            return 1; //删除成功
        }
        p = p->next;
    }

    return 0; //没找到
}

Node* findById(Node* head, int id) {
    Node* p = head->next;

    while (p != NULL) {
        if (p->data.id == id) {
            return p;
        }
        p = p->next;
    }

    return NULL;
}

//修改学生信息
void updateStudent(Node* head) {
    int id;
    printf("请输入要修改的学号: ");
    scanf("%d", &id);

    Node* p =findById(head, id); //调用已有函数查找学生
    if (!p) {
        printf("未找到该学生!\n");
        return;
    }

    printf("请输入新姓名: ");
    scanf("%s", p->data.name);

    printf("请输入新成绩: ");
    scanf("%f", &p->data.score);

    printf("修改成功!\n");
}

//排序函数
void sortByScore(Node* head) {
    if (!head->next || !head->next->next) return; // 空链表或只有一个节点无需排序

    Node *p, *q;
    Student temp;

    for (p = head->next; p != NULL; p = p->next) {
        for (q = p->next; q != NULL; q = q->next) {
            if (p->data.score < q->data.score) { //降序
                temp = p->data;
                p->data = q->data;
                q->data = temp;
            }
        }
    }

    printf("已按成绩排序（降序）\n");
}

//学生成绩统计
void statistics(Node* head) {
    Node* p = head->next;
    if (!p) {
        printf("没有学生数据!\n");
        return;
    }

    int count = 0;
    float sum = 0;
    float max, min; 

    //用第一个学生初始化max和min
    max = min = p->data.score;

    while (p != NULL) {
        count++;
        sum += p->data.score;
        if (p->data.score > max) max = p->data.score;
        if (p->data.score < min) min = p->data.score;
        
        p = p->next;
    }

    printf("学生总数: %d\n", count);
    printf("平均分: %.2f\n", sum / count);
    printf("最高分: %.1f\n", max);
    printf("最低分: %.1f\n", min);
}

//导出学生数据到CSV文件
void saveToCSV(Node* head) {
    FILE* fp = fopen("student.csv", "w");
    if (!fp) {
        printf("文件打开失败!\n");
        return;
    }

//写表头
fprintf(fp, "ID,Name,Score\n");

Node* p = head->next;
while (p != NULL) {
    fprintf(fp, "%d,%s,%.1f\n", p->data.id, p->data.name, p->data.score);
    p = p->next;
}
    fclose(fp);
    printf("已导出 student.csv 文件\n");
}

//清空链表
void clearList(Node* head) {
    Node* p = head->next;
    Node* temp;

    while (p !=NULL) {
        temp = p;
        p = p->next;
        free(temp);
    }

    head->next = NULL;
}