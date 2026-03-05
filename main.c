#include <stdio.h>
#include <stdlib.h>
#include "student.h"
#include "list.h"
#include "file.h"

// 学生结构体




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
            saveToFile(head);
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