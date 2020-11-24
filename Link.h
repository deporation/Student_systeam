#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
struct LINK_NODE
{
	long id;
	char name[10];
	float score1;
	float score2;
	float score3;
	int grade;
	struct LINK_NODE *next;
};
/*创建新的结点*/
struct LINK_NODE *creat(struct LINK_NODE *head)
{
	char s[10];
	struct LINK_NODE *p1 = NULL, *p2 = head;
	p1 = (struct LINK_NODE *)malloc(sizeof(struct LINK_NODE));     //动态申请（分配）内存，用来建立新的结点
	if (!head)     //检查头结点指针是否为空
	{
		head = p1;
		head->next = NULL;
		return head;
	}
	else
	{
		while (p2->next != NULL)
		{
			p2 = p2->next;
		}
		p2->next = p1;
		p1->next = NULL;
		printf("请输入学号：");
		scanf(" %d", &(p1->id));
		getchar();
		printf("请输入姓名：");
		gets(p1->name);
		printf("请输入年级：");
		scanf(" %d", &(p1->grade));
		printf("请输入第一个成绩：");
		scanf(" %f", &(p1->score1));
		printf("请输入第二个成绩：");
		scanf(" %f", &(p1->score2));
		printf("请输入第三个成绩：");
		scanf(" %f", &(p1->score3));
	}
	return head;
}
void Display_Node(struct LINK_NODE *head)
{
	int i = 1;     //回避头结点（不打印头结点）
	struct LINK_NODE *p = head;
	if (head == NULL)     //若传进来的链表头指针为 NULL，则做出错误判断
	{
		printf("\n用户尚未录入任何数据!!\n");
	}
	else if (p->next == NULL)
	{
		printf("该系统内未找到任何数据!!\n");
	}
	else
	{
		system("cls");
		printf("当前全部学生信息如下：\n");
		do     //1传进来的链表头指针不为 NULL，则挨个打印，直到尾结点
		{
			p = p->next;
			printf("\t%d------------------------\n", i);
			printf("\t 学号：%d\n", p->id);
			printf("\t 姓名：%s\n", p->name);
			printf("\t 年级：%d\n", p->grade);
			printf("\t 第一个成绩：%.2f\n", p->score1);
			printf("\t 第二个成绩：%.2f\n", p->score2);
			printf("\t 第三个成绩：%.2f\n", p->score3);
			i++;
		} while (p->next);
	}
}
/*结点计数*/
int Count_Node(struct LINK_NODE *head)
{
	int i = 1;     //结点数从1开始，是因为头结点不录入数据
	struct LINK_NODE *p = head;
	do
	{
		p = p->next;
		++i;
	} while (p->next != NULL);      //直到指针指向最后一个结点时，停止移动
	return i;     //返回结点个数给函数
}

/*删除第某个结点*/
void Delete_Node_Num(struct LINK_NODE *head)
{
	int i, Count;
	int a = 1;
	struct LINK_NODE *p1 = head, *p2 = NULL;
	system("cls");
	Display_Node(head);
	Count = Count_Node(head);
	printf("\n请输入想要删除第几个数据信息：");
	scanf(" %d", &i);     //%d前加空格
	if (i <= 0)     //头结点不允许删除，若删除将影响接下来的链
	{
		printf("头结点不可删除!!\n");
	}
	else if (i >= Count)     //所要删除的结点数不可以大于链表的长度
	{
		printf("输入结点数有误!!\n");
	}
	else if (i == Count)     //若删除的是尾结点，则将倒数第二个的 next 赋值为 NULL
	{
		while (p1->next)
		{
			p1 = p1->next;
		}
		p2 = head;				//p2 p1
		while ((p2->next) != p1)
		{
			p2 = p2->next;
		}
		p2->next = NULL;
		free(p1);     //删除结点后，释放之前所占用的内存
	}
	else     //所删除的结点在链表中（非首非尾）
	{
		while (!(i == a))
		{
			p1 = p1->next;
			++a;
		}
		p2 = p1->next;				//p1 p2
		p1->next = p2->next;
		free(p2);     //删除结点后，释放之前所占用的内存
	}
	printf("操作成功!!\n");
	Display_Node(head);
	system("pause");
}

/*按数据删除结点*/   //功能未建设完全，存在BUG
void Delete_Node_Data(struct LINK_NODE *head)
{
	int num = 0, i = -1;
	struct LINK_NODE *p1 = head, *p2 = NULL;
	printf("\n请输入要删除的数据：");
	scanf(" %d", &num);
	if (head->next == NULL)
	{
		printf("\n链表中不存在任何数据!!\n");
		exit(0);
	}
	p2 = p1->next;
	while (p2->next != NULL)
	{
		p2 = p1->next;
		i = p2->id;
		if (p2->id == num)
		{
			break;
		}
	}
	if (i != num)
	{
		printf("\n链表中没有您要删除的数据!!\n");
		exit(0);
	}
	p1->next = p2->next;
	free(p2);     //结点删除后要释放掉所删除结点占用的内存空间，达到节约内存的目的
}

/*插入结点*/
void Cut_Node_In(struct LINK_NODE *head)
{
	int n = -1, i, Count = Count_Node(head), a, grade = 0;
	float score1, score2, score3;
	system("cls");
	Display_Node(head);
	struct LINK_NODE *p1 = head, *p2 = NULL;
	p2 = (struct LINK_NODE *)malloc(sizeof(struct LINK_NODE));
	if (p2 == NULL)
	{
		printf("内存空间不够，无法添加新的数据！！\n");
		exit(0);
	}
	else
	{
		printf("将数据插入到第几个数：");
		scanf(" %d", &n);
		printf("请输入学号：");
		scanf(" %d", &i);
		p2->id = i;
		getchar();
		printf("请输入姓名：");
		gets(p2->name);
		printf("请输入年级：");
		scanf("%d", &grade);
		p2->grade = grade;
		printf("请输入第一个成绩：");
		scanf(" %f", &score1);
		p2->score1 = score1;
		printf("请输入第二个成绩：");
		scanf(" %f", &score2);
		p2->score2 = score2;
		printf("请输入第三个成绩：");
		scanf(" %f", &score3);
		p2->score3 = score3;
	//	printf("将数据插入到第几个数：");
	//	scanf(" %d", &n);
		if (n <= 0)
		{
			printf("此处不可插入数据！！\n");
			exit(0);
		}
		else if (n > Count)
		{
			printf("此处不可插入数据！！\n");
			exit(0);
		}
		for (i = 0; i <= Count;)
		{
			i++;
			if (i == n)				//p1后插入p2
			{
				p2->next = p1->next;
				p1->next = p2;
				break;
			}
			else
			{
				p1 = p1->next;
			}
		}
		printf("操作成功!!\n");
		Display_Node(head);
	}
}

/*显示当前的结点内容*/

void Count_Grade(struct LINK_NODE *head)
{
	int num[3] = { 0, 0, 0 };
	int i = 1;     //回避头结点（不打印头结点）
	struct LINK_NODE *p = head;
	if (head == NULL)     //若传进来的链表头指针为 NULL，则做出错误判断
	{
		printf("\n用户尚未录入任何数据!!\n");
	}
	else if (p->next == NULL)
	{
		printf("该系统内未找到任何数据!!\n");
	}
	else
	{
		system("cls");
		printf("当前全部学生信息如下：\n");
		do     //1传进来的链表头指针不为 NULL，则挨个打印，直到尾结点
		{
			p = p->next;
			if (p->grade == 1)
				num[0]++;
			else if (p->grade == 2)
				num[1]++;
			else
				num[2]++;
		} while (p->next);
	}
	for ( i = 0; i < 3; i++)
	{
		printf("第%d个年级有%d个人\n", i + 1, num[i]);
	}

}
void Find_bystu(struct LINK_NODE *head,int num)
{
	int i = 1;     //回避头结点（不打印头结点）
	struct LINK_NODE *p = head;
	if (head == NULL)     //若传进来的链表头指针为 NULL，则做出错误判断
	{
		printf("\n用户尚未录入任何数据!!\n");
	}
	else if (p->next == NULL)
	{
		printf("该系统内未找到任何数据!!\n");
	}
	else
	{
		system("cls");
		printf("当前全部学生信息如下：\n");
		do     //1传进来的链表头指针不为 NULL，则挨个打印，直到尾结点
		{
			p = p->next;
			if (p->id == num)
			{
				printf("学生编号为%d\n",i);
				printf("\t%d------------------------\n", i);
				printf("\t 学号：%d\n", p->id);
				printf("\t 姓名：%s\n", p->name);
				printf("\t 年级：%d\n", p->grade);
				printf("\t 第一个成绩：%.2f\n", p->score1);
				printf("\t 第二个成绩：%.2f\n", p->score2);
				printf("\t 第三个成绩：%.2f\n", p->score3);
			}
			i++;
		} while (p->next);
	}
}
int Save_Node(struct LINK_NODE *head)
{
	FILE *fp;
	fp = fopen("name.txt","w+");
	struct LINK_NODE *p = head;
	if (head == NULL)     //若传进来的链表头指针为 NULL，则做出错误判断
	{
		printf("\n用户尚未录入任何数据!!\n");
	}
	else if (p->next == NULL)
	{
		printf("该系统内未找到任何数据!!\n");
	}
	else
	{
		system("cls");
		printf("当前全部学生信息如下：\n");
		do
		{
			p = p->next;
			fprintf(fp,"%s\t%d\t%f\t%f\t%f\t%d\n",p->name,p->id,p->score1,p->score2,p->score3,p->grade);
		} while (p->next);
	}
	printf("数据已经保存成功\n");
	fclose(fp);
	return 1;
}
double List_avg(struct LINK_NODE *head,int choice)
{
	struct LINK_NODE *p = head;
	double sum = 0;
	int Count = Count_Node(head);
	if (head == NULL)     //若传进来的链表头指针为 NULL，则做出错误判断
	{
		printf("\n用户尚未录入任何数据!!\n");
	}
	else if (p->next == NULL)
	{
		printf("该系统内未找到任何数据!!\n");
	}
	else
	{
		system("cls");
		printf("第%d门平均成绩如下：\n",choice);
		do
		{
			p = p->next;
			if (choice == 1)
				sum += p->score1;
			else if (choice == 2)
				sum += p->score2;
			else if (choice == 3)
				sum += p->score3;
			else
				exit(0);
		} while (p->next);
	}
	return (sum/(Count-1));
}
void Sort_Score(struct LINK_NODE *head, int choice)
{
		int i = 0;
		int j = 0;
		int index;
		struct LINK_NODE *p = head;
		LINK_NODE * copy = (LINK_NODE*)malloc(sizeof(LINK_NODE)*(Count_Node(head)-1));
		LINK_NODE temp;
		if (head == NULL)     //若传进来的链表头指针为 NULL，则做出错误判断
		{
			printf("\n用户尚未录入任何数据!!\n");
		}
		else if (p->next == NULL)
		{
			printf("该系统内未找到任何数据!!\n");
		}
		else
		{
			if(choice == 1)
			{
				for(i=0;i<Count_Node(head)-1;i++)
				{
					p=p->next;
					copy[i]=*p;
				}
				for(i=0;i<Count_Node(head)-2;i++)
				{
					index = i;
					for(j=i+1;j<Count_Node(head)-1;j++)
					{
						if(copy[j].score1>copy[index].score1)
							index=j;
						temp=copy[index];
						copy[index]=copy[i];
						copy[i]=temp;
					}
				}
			}

			else if(choice == 2)
			{
				for(i=0;i<Count_Node(head)-1;i++)
				{
					p=p->next;
					copy[i]=*p;
				}
				for(i=0;i<Count_Node(head)-2;i++)
				{
					index = i;
					for(j=i+1;j<Count_Node(head)-1;j++)
					{
						if(copy[j].score2>copy[index].score2)
							index=j;
						temp=copy[index];
						copy[index]=copy[i];
						copy[i]=temp;
					}
				}
			}

			else
			{
				for(i=0;i<Count_Node(head)-1;i++)
				{
					p=p->next;
					copy[i]=*p;
				}
				for(i=0;i<Count_Node(head)-2;i++)
				{
					index = i;
					for(j=i+1;j<Count_Node(head)-1;j++)
					{
						if(copy[j].score3>copy[index].score3)
							index=j;
						temp=copy[index];
						copy[index]=copy[i];
						copy[i]=temp;
					}
				}
			}
		}
		for (size_t i = 0; i < Count_Node(head) - 1; i++)
		{
			printf("学生编号为%d\n", i+1);
			printf("\t%d------------------------\n", i+1);
			printf("\t 学号：%d\n", copy[i].id);
			printf("\t 姓名：%s\n", copy[i].name);
			printf("\t 年级：%d\n", copy[i].grade);
			printf("\t 第一个成绩：%.2f\n", copy[i].score1);
			printf("\t 第二个成绩：%.2f\n", copy[i].score2);
			printf("\t 第三个成绩：%.2f\n", copy[i].score3);
		}
		free(copy);
		copy = NULL;
}