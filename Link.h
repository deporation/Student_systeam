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
/*�����µĽ��*/
struct LINK_NODE *creat(struct LINK_NODE *head)
{
	char s[10];
	struct LINK_NODE *p1 = NULL, *p2 = head;
	p1 = (struct LINK_NODE *)malloc(sizeof(struct LINK_NODE));     //��̬���루���䣩�ڴ棬���������µĽ��
	if (!head)     //���ͷ���ָ���Ƿ�Ϊ��
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
		printf("������ѧ�ţ�");
		scanf(" %d", &(p1->id));
		getchar();
		printf("������������");
		gets(p1->name);
		printf("�������꼶��");
		scanf(" %d", &(p1->grade));
		printf("�������һ���ɼ���");
		scanf(" %f", &(p1->score1));
		printf("������ڶ����ɼ���");
		scanf(" %f", &(p1->score2));
		printf("������������ɼ���");
		scanf(" %f", &(p1->score3));
	}
	return head;
}
void Display_Node(struct LINK_NODE *head)
{
	int i = 1;     //�ر�ͷ��㣨����ӡͷ��㣩
	struct LINK_NODE *p = head;
	if (head == NULL)     //��������������ͷָ��Ϊ NULL�������������ж�
	{
		printf("\n�û���δ¼���κ�����!!\n");
	}
	else if (p->next == NULL)
	{
		printf("��ϵͳ��δ�ҵ��κ�����!!\n");
	}
	else
	{
		system("cls");
		printf("��ǰȫ��ѧ����Ϣ���£�\n");
		do     //1������������ͷָ�벻Ϊ NULL���򰤸���ӡ��ֱ��β���
		{
			p = p->next;
			printf("\t%d------------------------\n", i);
			printf("\t ѧ�ţ�%d\n", p->id);
			printf("\t ������%s\n", p->name);
			printf("\t �꼶��%d\n", p->grade);
			printf("\t ��һ���ɼ���%.2f\n", p->score1);
			printf("\t �ڶ����ɼ���%.2f\n", p->score2);
			printf("\t �������ɼ���%.2f\n", p->score3);
			i++;
		} while (p->next);
	}
}
/*������*/
int Count_Node(struct LINK_NODE *head)
{
	int i = 1;     //�������1��ʼ������Ϊͷ��㲻¼������
	struct LINK_NODE *p = head;
	do
	{
		p = p->next;
		++i;
	} while (p->next != NULL);      //ֱ��ָ��ָ�����һ�����ʱ��ֹͣ�ƶ�
	return i;     //���ؽ�����������
}

/*ɾ����ĳ�����*/
void Delete_Node_Num(struct LINK_NODE *head)
{
	int i, Count;
	int a = 1;
	struct LINK_NODE *p1 = head, *p2 = NULL;
	system("cls");
	Display_Node(head);
	Count = Count_Node(head);
	printf("\n��������Ҫɾ���ڼ���������Ϣ��");
	scanf(" %d", &i);     //%dǰ�ӿո�
	if (i <= 0)     //ͷ��㲻����ɾ������ɾ����Ӱ�����������
	{
		printf("ͷ��㲻��ɾ��!!\n");
	}
	else if (i >= Count)     //��Ҫɾ���Ľ���������Դ�������ĳ���
	{
		printf("������������!!\n");
	}
	else if (i == Count)     //��ɾ������β��㣬�򽫵����ڶ����� next ��ֵΪ NULL
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
		free(p1);     //ɾ�������ͷ�֮ǰ��ռ�õ��ڴ�
	}
	else     //��ɾ���Ľ���������У����׷�β��
	{
		while (!(i == a))
		{
			p1 = p1->next;
			++a;
		}
		p2 = p1->next;				//p1 p2
		p1->next = p2->next;
		free(p2);     //ɾ�������ͷ�֮ǰ��ռ�õ��ڴ�
	}
	printf("�����ɹ�!!\n");
	Display_Node(head);
	system("pause");
}

/*������ɾ�����*/   //����δ������ȫ������BUG
void Delete_Node_Data(struct LINK_NODE *head)
{
	int num = 0, i = -1;
	struct LINK_NODE *p1 = head, *p2 = NULL;
	printf("\n������Ҫɾ�������ݣ�");
	scanf(" %d", &num);
	if (head->next == NULL)
	{
		printf("\n�����в������κ�����!!\n");
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
		printf("\n������û����Ҫɾ��������!!\n");
		exit(0);
	}
	p1->next = p2->next;
	free(p2);     //���ɾ����Ҫ�ͷŵ���ɾ�����ռ�õ��ڴ�ռ䣬�ﵽ��Լ�ڴ��Ŀ��
}

/*������*/
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
		printf("�ڴ�ռ䲻�����޷�����µ����ݣ���\n");
		exit(0);
	}
	else
	{
		printf("�����ݲ��뵽�ڼ�������");
		scanf(" %d", &n);
		printf("������ѧ�ţ�");
		scanf(" %d", &i);
		p2->id = i;
		getchar();
		printf("������������");
		gets(p2->name);
		printf("�������꼶��");
		scanf("%d", &grade);
		p2->grade = grade;
		printf("�������һ���ɼ���");
		scanf(" %f", &score1);
		p2->score1 = score1;
		printf("������ڶ����ɼ���");
		scanf(" %f", &score2);
		p2->score2 = score2;
		printf("������������ɼ���");
		scanf(" %f", &score3);
		p2->score3 = score3;
	//	printf("�����ݲ��뵽�ڼ�������");
	//	scanf(" %d", &n);
		if (n <= 0)
		{
			printf("�˴����ɲ������ݣ���\n");
			exit(0);
		}
		else if (n > Count)
		{
			printf("�˴����ɲ������ݣ���\n");
			exit(0);
		}
		for (i = 0; i <= Count;)
		{
			i++;
			if (i == n)				//p1�����p2
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
		printf("�����ɹ�!!\n");
		Display_Node(head);
	}
}

/*��ʾ��ǰ�Ľ������*/

void Count_Grade(struct LINK_NODE *head)
{
	int num[3] = { 0, 0, 0 };
	int i = 1;     //�ر�ͷ��㣨����ӡͷ��㣩
	struct LINK_NODE *p = head;
	if (head == NULL)     //��������������ͷָ��Ϊ NULL�������������ж�
	{
		printf("\n�û���δ¼���κ�����!!\n");
	}
	else if (p->next == NULL)
	{
		printf("��ϵͳ��δ�ҵ��κ�����!!\n");
	}
	else
	{
		system("cls");
		printf("��ǰȫ��ѧ����Ϣ���£�\n");
		do     //1������������ͷָ�벻Ϊ NULL���򰤸���ӡ��ֱ��β���
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
		printf("��%d���꼶��%d����\n", i + 1, num[i]);
	}

}
void Find_bystu(struct LINK_NODE *head,int num)
{
	int i = 1;     //�ر�ͷ��㣨����ӡͷ��㣩
	struct LINK_NODE *p = head;
	if (head == NULL)     //��������������ͷָ��Ϊ NULL�������������ж�
	{
		printf("\n�û���δ¼���κ�����!!\n");
	}
	else if (p->next == NULL)
	{
		printf("��ϵͳ��δ�ҵ��κ�����!!\n");
	}
	else
	{
		system("cls");
		printf("��ǰȫ��ѧ����Ϣ���£�\n");
		do     //1������������ͷָ�벻Ϊ NULL���򰤸���ӡ��ֱ��β���
		{
			p = p->next;
			if (p->id == num)
			{
				printf("ѧ�����Ϊ%d\n",i);
				printf("\t%d------------------------\n", i);
				printf("\t ѧ�ţ�%d\n", p->id);
				printf("\t ������%s\n", p->name);
				printf("\t �꼶��%d\n", p->grade);
				printf("\t ��һ���ɼ���%.2f\n", p->score1);
				printf("\t �ڶ����ɼ���%.2f\n", p->score2);
				printf("\t �������ɼ���%.2f\n", p->score3);
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
	if (head == NULL)     //��������������ͷָ��Ϊ NULL�������������ж�
	{
		printf("\n�û���δ¼���κ�����!!\n");
	}
	else if (p->next == NULL)
	{
		printf("��ϵͳ��δ�ҵ��κ�����!!\n");
	}
	else
	{
		system("cls");
		printf("��ǰȫ��ѧ����Ϣ���£�\n");
		do
		{
			p = p->next;
			fprintf(fp,"%s\t%d\t%f\t%f\t%f\t%d\n",p->name,p->id,p->score1,p->score2,p->score3,p->grade);
		} while (p->next);
	}
	printf("�����Ѿ�����ɹ�\n");
	fclose(fp);
	return 1;
}
double List_avg(struct LINK_NODE *head,int choice)
{
	struct LINK_NODE *p = head;
	double sum = 0;
	int Count = Count_Node(head);
	if (head == NULL)     //��������������ͷָ��Ϊ NULL�������������ж�
	{
		printf("\n�û���δ¼���κ�����!!\n");
	}
	else if (p->next == NULL)
	{
		printf("��ϵͳ��δ�ҵ��κ�����!!\n");
	}
	else
	{
		system("cls");
		printf("��%d��ƽ���ɼ����£�\n",choice);
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
		if (head == NULL)     //��������������ͷָ��Ϊ NULL�������������ж�
		{
			printf("\n�û���δ¼���κ�����!!\n");
		}
		else if (p->next == NULL)
		{
			printf("��ϵͳ��δ�ҵ��κ�����!!\n");
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
			printf("ѧ�����Ϊ%d\n", i+1);
			printf("\t%d------------------------\n", i+1);
			printf("\t ѧ�ţ�%d\n", copy[i].id);
			printf("\t ������%s\n", copy[i].name);
			printf("\t �꼶��%d\n", copy[i].grade);
			printf("\t ��һ���ɼ���%.2f\n", copy[i].score1);
			printf("\t �ڶ����ɼ���%.2f\n", copy[i].score2);
			printf("\t �������ɼ���%.2f\n", copy[i].score3);
		}
		free(copy);
		copy = NULL;
}