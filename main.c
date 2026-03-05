#include <stdio.h>
#include <stdlib.h>

// 学生结构体
typedef struct {
    int id;
    char name[50];
    float score;
} Student;

// 单链表结点
typedef struct Node {
    Student data;
    struct Node *next;
} Node;

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
        if (p->data.score < max) min = p->data.score;
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

int main() {
    Node* head = initList();
    loadFromFile(head);
    int choice;

    while(1) {
        printf("\n===== 学生管理系统 =====\n");
        printf("1. 添加学生\n");
        printf("2. 删除学生\n");
        printf("3. 显示所有学生\n");
        printf("4. 查询学生\n");
        printf("5. 修改学生\n");    // 新增选项
        printf("6. 按成绩排序\n");  //新增
        printf("7. 统计信息\n"); // 新增统计功能
        printf("8. 导出 CSV\n"); // 新增 CSV 导出
        printf("0. 退出\n");
        printf("请选择: ");
        char line[100];
        if (!fgets(line, sizeof(line), stdin)) continue; //读取失败就重新循环
        if (sscanf(line, "%d", &choice) != 1) {
            printf("输入无效，请输入数字!\n");
            continue;
        }

        

       if (choice == 1){
            // 添加学生
            Student s;

            printf("请输入学号: ");
            scanf("%d", &s.id);

            if (findById(head, s.id) != NULL) {
                printf("学号已存在，添加失败!\n");
                continue;
            }

            printf("请输入姓名: ");
            scanf("%s", s.name);

            printf("请输入成绩: ");
            scanf("%f", &s.score);

            insertHead(head, s);
            printf("添加成功! \n");
       } 

       else if (choice == 2) {
            // 删除学生
            int id;
            printf("请输入要删除的学号: ");
            scanf("%d", &id);

            if (deleteById(head, id)) {
                printf("删除成功!\n");
            } else {
                printf("未找到该学生，删除失败!\n");
            }
       }
       else if (choice == 3) {

            printList(head);
       }
       else if (choice == 4) {
            // 查询学生
            int id;
            printf("请输入要查询的学号：");
            scanf("%d", &id);
            
            Node* result = findById(head, id);

            if (result == NULL) {
                printf("未找到该学生! \n");
            } else {
                printf("找到学生: \n");
                printf("ID: %d, Name: %s, Score: %.1f\n",
                        result->data.id,
                        result->data.name,
                        result->data.score);
            }
       }

       else if (choice == 5) {
            updateStudent(head);
       }

       else if (choice == 6) {
            sortByScore(head);
       }

       else if (choice == 7) {
            statistics(head);
       }

       else if (choice == 8) {
            saveToCSV(head);
       }

       else if (choice == 0) {
            saveToFile(head);
            printf("数据已保存，退出系统\n");
            break;
       }
       else {
            printf("输入错误\n");
       }
    }

    clearList(head);
    free(head);
    return 0;
}