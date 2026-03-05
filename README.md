# C Student Management System

# 学生成绩管理系统

## 项目简介
这是一个基于 **C 语言** 的学生成绩管理系统项目，用于：
- **考研数据结构复习**：练习链表、文件操作、排序等基础知识  
- **企业面试演示**：展示基本项目结构、模块化设计和文件读写能力  

系统功能包括：
1. 添加学生信息（学号、姓名、成绩）  
2. 删除学生信息  
3. 显示所有学生  
4. 查询学生  
5. 修改学生  
6. 按成绩排序（降序）  
7. 学生成绩统计（总人数、平均分等）  
8. 导出 CSV 文件  

---

## 项目结构
c-student-management/
├── main.c // 主函数和菜单逻辑
├── list.c // 链表操作实现
├── list.h // 链表操作头文件
├── student.c // 学生相关函数实现
├── student.h // 学生结构体和函数声明
├── file.c // 文件读写实现
├── file.h // 文件操作头文件
├── student.txt // 保存的学生数据
├── student.csv // 导出的 CSV 文件
├── README.md // 项目说明


---

## 使用方法

1. 克隆仓库到本地：

```bash
git clone https://github.com/earthshipmax-lin/student-management-system.git
cd student-management-system

## Features
- Add student
- Delete student
- Search student
- Update student
- Sort by score
- Statistics
- File persistence
- CSV export

## How to Run
gcc main.c -o main
./main