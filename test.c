#define _CRT_SECURE_NO_DEPRECATE
#include "Link.h"
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
void fun();     /*�ۺϹ��ܺ���*/
/*������*/
int main()
{
	fun();
	system("pause");
	return 0;
}

/*�ۺϹ��ܺ���*/
void fun()
{
	int c,stu_num = 0,choice =0;
	char ch;
	struct LINK_NODE *head = NULL;
	system("cls");
	while (1)
	{
		printf("\n\t\t--\t      ��ӭʹ��ѧ���ɼ�����ϵͳ        \t --\n");
		printf("\t\t---------------------------------------------------\n");
		printf("\t\t|\t\t  0.����ѧ����Ϣ			 \t\t  |\n\n");
		printf("\t\t|\t\t  1.ɾ��������Ϣ			 \t\t  |\n\n");
		printf("\t\t|\t\t  2.����ѧ����Ϣ			 \t\t  |\n\n");
		printf("\t\t|\t\t  3.��ʾѧ����Ϣ			 \t\t  |\n\n");
		printf("\t\t|\t\t  4.ͳ���������			 \t\t  |\n\n");
		printf("\t\t|\t\t  5.����ѧ�ŷ�����Ϣ		 \t\t  |\n\n");
		printf("\t\t|\t\t  6.�������ѧ����Ϣд���ļ�\t\t  |\n\n");
		printf("\t\t|\t\t  7.���ƽ���ɼ�			 \t\t  |\n\n");
		printf("\t\t|\t\t  8.���ճɼ���������		 \t\t  |\n\n");
		printf("\t\t|\t\t  9.--- �˳� ---\t\t  |\n");
		printf("\t\t---------------------------------------------------\n");
		printf("��ѡ����Ŀ(�������)��");
		scanf(" %d", &c);
		getchar();
		switch (c)
		{
		case 0:
			system("cls");
			head = creat(head);
			printf("�Ƿ��������ݣ���y/n)��");
			scanf(" %c", &ch);     //%cǰ�ӿո�
			while (ch == 'y' || ch == 'Y')     //����ѭ����������
			{
				head = creat(head);
				printf("�Ƿ��������ݣ���y/n)��");
				scanf(" %c", &ch);     //%cǰ�ӿո�
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
			printf("������ѧ��:");
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
			printf("����ڼ��ŵ�ƽ���ɼ�:");
			scanf("%d",&choice);
			printf("%d",List_avg(head, choice));
			system("pause");
			system("cls");
			break;
		case 8:
			system("cls");
			printf("���ݵڼ��ųɼ���������");
			scanf("%d", &choice);
			Sort_Score(head,choice);
			system("pause");
			system("cls");
			break;
		case 9:
			system("cls");
			printf("\n\t��л����ʹ�ã�\n\n");
			system("pause");
			exit(0);
		}
	}
}