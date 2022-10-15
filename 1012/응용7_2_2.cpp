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
	printf("게임을 선택하시오\n");
	printf("1. 100을 넘어라 게임\n"); 
	printf("2. 음수 만들기 게임\n");
	printf("선택할 게임 : ");
	scanf("%d",&a);
	switch(a){
		case 1:
			printf("100을 넘어라 게임\n\n");
			printf("컴퓨터와 사용자가 번갈아가며\n");
			printf("숫자를 입력하되 1~10사이의 \n");
			printf("중복되지 않는 숫자를 입력하여 \n\n");
			printf("최초로 100을 넘기면 승자가 됩니다. \n\n");
			printf("컴퓨터가 먼저 시작합니다. \n");
			printf("아무키나 누르면 시작합니다.\n");
			getch();
			game_control(); 
			break;
		case 2:
			printf("음수를 만들어라 게임\n\n");
			printf("컴퓨터와 사용자가 번갈아가며\n");
			printf("숫자를 입력하되 1~10사이의 \n");
			printf("중복되지 않는 숫자를 입력하여 \n\n");
			printf("최초로 음수를 만들면 승자가 됩니다. \n\n");
			printf("컴퓨터가 먼저 시작합니다. \n");
			printf("아무키나 누르면 시작합니다.\n");
			getch();
			two_game_control();
			break;
		default:
			printf("잘못 입력하셨습니다. 게임을 종료합니다.");
			
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
	printf("사용자 숫자 입력후 Enter>");
	scanf("%d", &number);
	for(j=0;j<i;j+=1)
		if (user_array[j]==number)
		{
			gotoxy(1, 8);
			printf("중복된 숫자를 입력했습니다. \n");
			goto again;
		}
	user_array[i]=number;
	return user_array[i];
}

void number_display(int i, int com_array[], int user_array[], int sum)
{
	int j;
	gotoxy(1, 2);
	printf("컴퓨터 숫자 : ");
	for(j=0;j<=i;j+=1)
		printf("%2d ", com_array[j]);
	gotoxy(1, 3);
	printf("사용자 숫자 : ");
	for(j=0;j<=i;j+=1)
		if (user_array[j]==0)
			continue;
		else
			printf("%2d ", user_array[j]);
	gotoxy(1, 5);
	printf("현재 합계 : %3d\n", sum);
}

void conclusion(int check)
{
	if (check==1)
		printf("컴퓨터가 이겼습니다. \n");
	else
		printf("사용자가 이겼습니다. \n");
}

void press_any_key(void)
{
	gotoxy(1, 10);
	printf("아무키나 누르시오..");
	getch();
}

void game_control(void)
{
	int a; 
	int max=100;
	printf("난이도 선택: 1~3단계\n");
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
			printf("자동으로 100에서 시작됩니다.\n");
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
	printf("난이도 선택: 1~3단계\n");
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
			printf("자동으로 100에서 시작됩니다.\n");
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
