#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
#include<mmsystem.h>
#define MAX 100
typedef struct Student
{
	char id[20];//ѧ��
	char name[20];//����
	char sex[20];//�Ա�
	char pwd[20];//����
}Student;

typedef struct Score
{
	char id[20];//ѧ��
	float chinese;//���ĳɼ�
	float math;//��ѧ�ɼ�
}Score;

//���ѧ����Ϣ��˳���
Student s[MAX];
int temp_number = 0;
Score score[MAX];
int number = 0;



//����Ա��¼
int teacher_login()
{
	char s_id[20];
	char s_password[20];
	int temp = 0;
	printf("�������ʦ�˺ţ�\n");
	scanf("%s", s_id);
	printf("�������ʦ���룺\n");
	scanf("%s", s_password);


	if (!strcmp(s_id, "admin") && !strcmp(s_password, "123"))
	{
		temp++;
		printf("��¼�ɹ���\n");
		return 1;

	}

	if (temp == 0)
	{
		printf("�˺Ż���������󣬵�¼ʧ�ܣ�\n");
		return 0;
	}

}
//������Ϣ
void add()
{
	printf("==========������Ϣ=========\n");

	printf("������ѧ�ţ�\n");
	scanf("%s", s[temp_number].id);
	for(int i = 0; i < temp_number; i++)
	{
		if (!strcmp(s[temp_number].id, s[i].id))
		{
			printf("���ڸ�ѧ�ţ����ʧ�ܣ�\n");
			return;
		}
	}
	printf("������������\n");
	scanf("%s", s[temp_number].name);
	printf("�������Ա�\n");
	scanf("%s", s[temp_number].sex);
	printf("���������룺\n");
	scanf("%s", s[temp_number].pwd);
	temp_number++;
	printf("=======�����Ϣ�ɹ�======\n");
}
//���ӳɼ�
void add_score()
{

	int temp = 0;
	printf("������ѧ�ţ�\n");
	scanf("%s", score[number].id);
	for(int i = 0; i < temp_number; i++)
	{
		if (!strcmp(score[number].id, s[i].id))
		{
			temp++;
		}
	}

	if (temp == 0)
	{
		printf("�����ڸ���Ϣ�����ʧ��\n");
		return;
	}

	for(int i = 0; i < number; i++)
	{
		if (!strcmp(score[number].id, score[i].id))
		{
			printf("�Ѿ���Ӹ�ѧ���ɼ���Ϣ�����ʧ�ܣ�\n");
			return;
		}
	}

	printf("���������ĳɼ���\n");
	scanf("%f", &score[number].chinese);
	printf("��������ѧ�ɼ���\n");
	scanf("%f", &score[number].math);
	number++;
	printf("=======�����Ϣ�ɹ�======\n");
}
//��ʾ��Ϣ
void showAll()
{
	printf("==========��ʾ��Ϣ=========\n");
	for (int i = 0; i < temp_number; i++)
	{
		printf("ѧ�ţ�%s\t", s[i].id);
		printf("������%s\t", s[i].name);
		printf("�Ա�%s\t", s[i].sex);
		printf("���룺%s\t", s[i].pwd);
	}
	printf("=======��ʾ��Ϣ����======\n");
}
//������
int main()
{

	int chioce;

	while (1)
	{
		one:
		main_menu();
		int ch;
		printf("���������ѡ��\n");
		scanf("%d", &ch);
		if (ch == 1)
		{
			teacher_do_menu();
			printf("���������ѡ��\n");
			scanf("%d", &ch);
			if (ch == 1)
			{
				int flag = teacher_login();
				if (flag == 1)
				{
					while (1)
					{
						teacher_menu();
						printf("���������ѡ��0-9��:\n");
						scanf("%d", &chioce);
						if (chioce < 0 || chioce>9)
						{
							printf("�����������������룡\n");
						}
						else
						{
							switch (chioce)
							{
							case 1:
								add();
								break;
							case 2:
								del();
								break;
							case 3:
								modify();
								break;
							case 4:
								showAll();
								break;
							case 5:
								countList();
								break;
							case 6:
								readList();
								break;
							case 7:
								saveList();
								break;
							case 8:
								search();
								break;
							case 9:
								sort();
								break;
							case 0:
								goto one;
								break;
							}
						}

					}
				}
			}
			else if(ch==2)
			{
				int flag = teacher_login();
				if (flag == 1)
				{
					while (1)
					{
						score_menu();
						printf("���������ѡ��0-9��:\n");
						scanf("%d", &chioce);
						if (chioce < 0 || chioce>9)
						{
							printf("�����������������룡\n");
						}
						else
						{
							switch (chioce)
							{
							case 1:
								add_score();
								break;
							case 2:
								del_score();
								break;
							case 3:
								modify_score();
								break;
							case 4:
								show_score();
								break;
							case 5:
								countList();
								break;
							case 6:
								read_score();
								break;
							case 7:
								save_score();
								break;
							case 8:
								search_score();
								break;
							case 9:
								sort();
								break;
							case 0:
								goto one;
								break;
							}
						}

					}
				}
			}
			else if (ch == 0)
			{
				goto one;
			}
			else
			{
				printf("��������\n");
			}



		}
		else if (ch == 2)
		{
			int index = stu_login();
			if (index != -1)
			{
				while (1)
				{
					student_menu();
					printf("���������ѡ��0-4��:\n");
					scanf("%d", &chioce);
					if (chioce < 0 || chioce>4)
					{
						printf("�����������������룡\n");
					}
					else
					{
						switch (chioce)
						{
						case 1:
							show_self(index);
							break;
						case 2:
							show_self_score(index);
							break;
						case 3:
							update_self(index);
							break;
						case 0:
							printf("��ӭ�´�ʹ�ã�\n");
							goto one;
							break;
						}
					}

				}
			}


		}
		else if (ch == 0)
		{
			printf("��ӭ�´�ʹ�ã�\n");
			exit(0);
		}
		else
		{
			printf("��������\n");
		}
	}


	return 0;
}
