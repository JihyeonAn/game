#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

void intro_game(void);
void game_control(void);
void two_game_control(void);
int computer_number(int i, int com_array[]);
int user_number(int i, int user_array[]);
void number_display(int i, int com_array[], int user_array[], int sum);
void conclusion(int win);
void gotoxy(int x, int y);
void press_any_key(void);
int a,b,c;



int main(void)
{
	srand(time(NULL));
	intro_game();
	
	return 0;
}


void intro_game(void)
{
	int a;
	system("cls");
	printf("������ �����Ͻÿ�\n");
	printf("1. 100�� �Ѿ�� ����\n"); 
	printf("2. ���� ����� ����\n");
	printf("������ ���� : ");
	scanf("%d",&a);
	switch(a){
		case 1:
			printf("100�� �Ѿ�� ����\n\n");
			printf("��ǻ�Ϳ� ����ڰ� �����ư���\n");
			printf("���ڸ� �Է��ϵ� 1~10������ \n");
			printf("�ߺ����� �ʴ� ���ڸ� �Է��Ͽ� \n\n");
			printf("���ʷ� 100�� �ѱ�� ���ڰ� �˴ϴ�. \n\n");
			printf("��ǻ�Ͱ� ���� �����մϴ�. \n");
			printf("�ƹ�Ű�� ������ �����մϴ�.\n");
			getch();
			game_control(); 
			break;
		case 2:
			printf("������ ������ ����\n\n");
			printf("��ǻ�Ϳ� ����ڰ� �����ư���\n");
			printf("���ڸ� �Է��ϵ� 1~10������ \n");
			printf("�ߺ����� �ʴ� ���ڸ� �Է��Ͽ� \n\n");
			printf("���ʷ� ������ ����� ���ڰ� �˴ϴ�. \n\n");
			printf("��ǻ�Ͱ� ���� �����մϴ�. \n");
			printf("�ƹ�Ű�� ������ �����մϴ�.\n");
			getch();
			two_game_control();
			break;
		default:
			printf("�߸� �Է��ϼ̽��ϴ�. ������ �����մϴ�.");
			
	}
	

}

int computer_number(int i, int com_array[])
{
	int j, number;
	again:;
	number=rand()%10+1;
	for(j=0;j<i;j+=1)
		if (com_array[j]==number)
			goto again;
	com_array[i]=number;
	return com_array[i];
}

int user_number(int i, int user_array[])
{
	int j, number;
	again:;
	gotoxy(1, 7);
	printf("����� ���� �Է��� Enter>");
	scanf("%d", &number);
	for(j=0;j<i;j+=1)
		if (user_array[j]==number)
		{
			gotoxy(1, 8);
			printf("�ߺ��� ���ڸ� �Է��߽��ϴ�. \n");
			goto again;
		}
	user_array[i]=number;
	return user_array[i];
}

void number_display(int i, int com_array[], int user_array[], int sum)
{
	int j;
	gotoxy(1, 2);
	printf("��ǻ�� ���� : ");
	for(j=0;j<=i;j+=1)
		printf("%2d ", com_array[j]);
	gotoxy(1, 3);
	printf("����� ���� : ");
	for(j=0;j<=i;j+=1)
		if (user_array[j]==0)
			continue;
		else
			printf("%2d ", user_array[j]);
	gotoxy(1, 5);
	printf("���� �հ� : %3d\n", sum);
}

void conclusion(int check)
{
	if (check==1)
		printf("��ǻ�Ͱ� �̰���ϴ�. \n");
	else
		printf("����ڰ� �̰���ϴ�. \n");
}

void press_any_key(void)
{
	gotoxy(1, 10);
	printf("�ƹ�Ű�� �����ÿ�..");
	getch();
}

void game_control(void)
{
	int a; 
	int max=100;
	printf("���̵� ����: 1~3�ܰ�\n");
	scanf("%d",&a);
	switch(a){
		case 1 :
			max=50;
			break;
		case 2 :
			max=70;
			break;
		case 3:
			max=100;
			break;
		default :
			printf("�ڵ����� 100���� ���۵˴ϴ�.\n");
			break; 
	}
	
	int com_array[10]={0}, user_array[10]={0}, number;
	int i, sum=0, win; 
	for(i=0;i<10;i+=1)
	{
		system("cls");
		number=computer_number(i, com_array);
		sum+=number;
		number_display(i, com_array, user_array, sum);
		if (max<sum)
		{
			win=1;
			break;
		}
		number=user_number(i, user_array);
		sum+=number;
		number_display(i, com_array, user_array, sum);
		if (max<sum)
		{
			win=2;
			break;
		}
		press_any_key();
	}
	conclusion(win);
}

void two_game_control()
{
	int a; 
	int min=0;
	int sum=100;
	printf("���̵� ����: 1~3�ܰ�\n");
	scanf("%d",&a);
	switch(a){
		case 1 :
			sum=50;
			break;
		case 2 :
			sum=70;
			break;
		case 3:
			sum=100;
			break;
		default :
			printf("�ڵ����� 100���� ���۵˴ϴ�.\n");
			break; 
	}
	
	int com_array[10]={0}, user_array[10]={0}, number;
	int i,win; 
	for(i=0;i<10;i+=1)
	{
		system("cls");
		number=computer_number(i, com_array);
		sum-=number;
		number_display(i, com_array, user_array, sum);
		if (min>sum)
		{
			win=1;
			break;
		}
		number=user_number(i, user_array);
		sum-=number;
		number_display(i, com_array, user_array, sum);
		if (min>sum)
		{
			win=2;
			break;
		}
		press_any_key();
	}
	conclusion(win);
}

void gotoxy(int x, int y)
{
   COORD Pos = {x - 1, y - 1};
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
