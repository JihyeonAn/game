숫자 만들기 게임
===============

**수정 사항**

> 1.선택항목 추가
```cpp
printf("게임을 선택하시오\n");
printf("1. 100을 넘어라 게임\n"); 
printf("2. 음수 만들기 게임\n");
 ```

> 2.최초로 음수를 만들면 이기도록 룰 변경
```cpp
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
```

> 3.난이도 선택할수 있도록 함
```cpp
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
```

> 4.난이도에 따라 50,70,100으로 되도록함
```
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
```

**주소**

[github.io 주소]
