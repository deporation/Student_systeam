#define _CRT_SECURE_NO_DEPRECATE
#include "Link.h"
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
void fun();     /*综合功能函数*/
/*主函数*/
int main()
{
	fun();
	system("pause");
	return 0;
}

/*综合功能函数*/
void fun()
{
	int c,stu_num = 0,choice =0;
	char ch;
	struct LINK_NODE *head = NULL;
	system("cls");
	while (1)
	{
		printf("\n\t\t--\t      欢迎使用学生成绩管理系统        \t --\n");
		printf("\t\t---------------------------------------------------\n");
		printf("\t\t|\t\t  0.输入学生信息			 \t\t  |\n\n");
		printf("\t\t|\t\t  1.删除数据信息			 \t\t  |\n\n");
		printf("\t\t|\t\t  2.插入学生信息			 \t\t  |\n\n");
		printf("\t\t|\t\t  3.显示学生信息			 \t\t  |\n\n");
		printf("\t\t|\t\t  4.统计年纪人数			 \t\t  |\n\n");
		printf("\t\t|\t\t  5.根据学号返回信息		 \t\t  |\n\n");
		printf("\t\t|\t\t  6.将输入的学生信息写入文件\t\t  |\n\n");
		printf("\t\t|\t\t  7.求出平均成绩			 \t\t  |\n\n");
		printf("\t\t|\t\t  8.按照成绩进行排序		 \t\t  |\n\n");
		printf("\t\t|\t\t  9.--- 退出 ---\t\t  |\n");
		printf("\t\t---------------------------------------------------\n");
		printf("请选择栏目(输入序号)：");
		scanf(" %d", &c);
		getchar();
		switch (c)
		{
		case 0:
			system("cls");
			head = creat(head);
			printf("是否输入数据？（y/n)：");
			scanf(" %c", &ch);     //%c前加空格
			while (ch == 'y' || ch == 'Y')     //用于循环输入数据
			{
				head = creat(head);
				printf("是否输入数据？（y/n)：");
				scanf(" %c", &ch);     //%c前加空格
			}
			system("pause");
			system("cls");
			break;
		case 1:
			Delete_Node_Num(head);
			system("cls");
			break;
		case 2:
			Cut_Node_In(head);
			system("pause");
			system("cls");
			break;
		case 3:
			system("cls");
			Display_Node(head);
			system("pause");
			system("cls");
			break;
		case 4:
			system("cls");
			Count_Grade(head);
			system("pause");
			system("cls");
			break;
		case 5:
			system("cls");
			printf("请输入学号:");
			scanf("%d",&stu_num);
			Find_bystu(head, stu_num);
			system("pause");
			system("cls");
			break;
		case 6:
			system("cls");
			Save_Node(head);
			system("pause");
			system("cls");
			break;
		case 7:
			system("cls");
			printf("计算第几门的平均成绩:");
			scanf("%d",&choice);
			printf("%d",List_avg(head, choice));
			system("pause");
			system("cls");
			break;
		case 8:
			system("cls");
			printf("根据第几门成绩进行排序：");
			scanf("%d", &choice);
			Sort_Score(head,choice);
			system("pause");
			system("cls");
			break;
		case 9:
			system("cls");
			printf("\n\t感谢您的使用！\n\n");
			system("pause");
			exit(0);
		}
	}
}