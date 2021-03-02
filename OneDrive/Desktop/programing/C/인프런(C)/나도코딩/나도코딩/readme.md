### 함수

* 반환값이 없으면 선언 시 void, 있다면 해당 자료형으로 선언.

```c
// 토이 프로젝트


#include <stdio.h>
int add(int num1, int num2);
int sub(int num1, int num2);
int mul(int num1, int num2);
int div(int num1, int num2);
int input_num(int num);

int main_function() {
	int num1 = 0;
	int num2 = 0;
	int select = 0;
	printf("ㄴㅇㄹ");
	while (select < 5) {
		select = 0;
		num1 = input_num(num1);
		num2 = input_num(num2);
		printf("1. 더하기 \n 2. 빼기 \n 3. 곱하기 \n 4. 나누기 \n 5. 나가기\n 입력 :");
		scanf_s("%d", &select);
		switch (select)
		{
		case 1: 
		{
			printf("값 : %d", add(num1, num2)); 
			continue;
		}
		case 2: 
		{
			printf("값 : %d", sub(num1, num2)); 
			continue;
		}
			
		case 3: 
		{
			printf("값 : %d", mul(num1, num2)); 
			continue;
		}
			
		case 4: 
		{
			printf("값 : %d", div(num1, num2)); 
			continue;
		}
			
		default: 
		{
			printf("안녕히");
		}
		}

	}
	return 0;

}

int add(int num1, int num2)
{
	return num1 + num2;
}
int sub(int num1, int num2)
{
	return num1 - num2;
}
int mul(int num1, int num2)
{
	return num1 * num2;
}
int div(int num1, int num2)
{
	return num1 / num2;
}
int input_num(int num)
{
	printf("숫자를 입력하세요. \n");
	scanf_s("%d", &num);
	printf("\n 입력한 숫자 = %d \n", num);
	return num;
}

```
### 배열

* sizeof로 배열의 크기를 계산하면 문자열보다 1만큼 크게 나옴.
* 문자열의 마지막에는 끝을 의미하는 NULL 문자인 `\0`이 포함되어야 함.
	- 마지막 공간에 자동으로 입력됨.
	- 문자열에 딱 맞게 배열을 설정하면 오류 발생.
* 영어는 글자당 1 바이트, 한글은 글자당 2 바이트.
* char 자료형의 크기는 1 바이트.

* char를 %d로 출력하면 아스키 코드가 출력됨.
	- 0과 1밖에 모르는 컴퓨터가 문자를 출력할 수 있는 이유.

* null은 아스키 코드로 0

```c
// 프로젝트

#include <stdio.h>
#include <time.h>

int main_array()
{
	srand(time(NULL));
	printf(" \n\n ======= 대머리 ====== \n\n");
	int answer;
	int treatment = rand() % 4; // 0 ~ 3 중 랜덤

	int cur_show = 0;
	int pre_show = 0;

	for (int i = 1; i <= 3; i++) {
		int bottle[4] = { 0, 0, 0, 0 };
			do {
				cur_show = (rand() % 2) + 2; // 2 or 3
			} while (cur_show == pre_show);

			pre_show = cur_show;
			int is_included = 0;
			printf(" > %d 번째 시도 : ", i);

			for (int j = 0; j < cur_show; j++)
			{
				int rand_bottle = rand() % 4; // 0 ~ 3

				if (bottle[rand_bottle] == 0) {
					bottle[rand_bottle] = 1;
					if (rand_bottle == treatment) is_included = 1;
				}
				else j--;
			}

			for (int k = 0; k < 4; k++)
			{
				if (bottle[k] == 1)	printf("%d ", k + 1);

			}
			printf(" 물약을 머리에 바릅니다. \n\n");
				if (is_included == 1) printf("자라나라 머리머리! \n");
				else printf("실패!  \n");
				printf("아무 키나 누르세요...");
				getchar();

			}


	printf("발모제는 몇 번?");
	scanf("%d", &answer);
	if (answer == treatment + 1) printf("정답!");
	else printf("오답! 답은 %d였습니다.", treatment + 1);



	return 0;

```


### 배열

```c
#include <stdio.h>
int main()
{
	int arr[3] = {10, 20, 30};
	int* ptr = &arr;
	for (int i = 0; i < 3; i++)
	{
		printf("배열 arr[%d]의 값 : %d \n", i, arr[i]);
	}

	for (int i = 0; i < 3; i++)
	{
		printf("포인터 ptr[%d]의 값 : %d \n", i, ptr[i]);
	}

	ptr[0] = 100;
	ptr[1] = 200;

	for (int i = 0; i < 3; i++)
	{
		//printf("배열 arr[%d]의 값 : %d \n", i, arr[i]);
		printf("배열 arr[%d]의 값 : %d \n", i, *(arr + i));

	}

	for (int i = 0; i < 3; i++)
	{
		//printf("포인터 ptr[%d]의 값 : %d \n", i, ptr[i]);
		printf("포인터 ptr[%d]의 값 : %d \n", i, *(ptr + i));
		printf("포인터 ptr[%d]의 주소값 : %p \n", i, ptr + i);

	}
	// *(arr + i) == arr[i]
	// 배열의 주소 == 배열의 0번째(첫번째) 주소

	printf("arr 자체의 값 : %p\n", arr);
	printf("arr[0]의 주소 : %p\n", &arr[0]);

	printf("arr 자체의 값이 가지는 주소의 실제 값 : %d \n", *arr); // *(arr + 0)
	printf("arr[0]의 실제 값 : %d \n", arr[0]);


	// *&는 아무것도 것는 것과 같다. &는 주소, *은 주소의 값
	// *& 붙어있으면 서로 상쇄.

	return 0;
}
```

* 배열의 주소값을 포인터에 대입하니 `*`없이 포인터 변수 만으로도 인덱싱으로 원소의 값에 접근이 가능.
* 포인터로 대응하는 주소의 배열의 원소값에 `*` 없이 접근 및 수정이 가능.
* 포인터가 배열에 대응?
* 배열(arr)의 주소값과 값은 `배열[0]`의 주소값과 값과 똑같다.

#### SWAP
```c
#include <stdio.h>
void swap(int a, int b);
void swap_addr(int *a, int *b);
int main() {
	int a = 10;
	int b = 20;
	printf("a의 주소 : %p \n", &a);
	printf("b의 주소 : %p \n", &b);
	printf("SWAP 함수 전 -> a : %d, b : %d \n", a, b);
	swap(a, b);
	printf("SWAP 함수 후 -> a : %d, b : %d \n", a, b);

	printf("\n\n");
	// 값에 의한 복사 (Call by Value) -> 변수가 아닌 값만 복사, 지역함수 개념?

	// 메모리 공간의 주소값 자체를 넘기면?
	printf("a의 주소 : %p \n", &a);
	printf("b의 주소 : %p \n", &b);
	printf("SWAP_ADDR 함수 전 -> a : %d, b : %d \n", a, b);
	swap_addr(&a, &b);
	printf("SWAP_ADDR 함수 후 -> a : %d, b : %d \n", a, b);
	return 0;
}

void swap(int a, int b)
{
	printf("a의 주소 : %p \n", &a);
	printf("b의 주소 : %p \n", &b);
	int temp = a;
	a = b;
	b = temp;
	printf("SWAP 함수 내부 -> a : %d, b : %d \n", a, b);
}

void swap_addr(int *a, int *b)
{
	printf("a의 주소 : %p \n", &a);
	printf("b의 주소 : %p \n", &b);
	int temp = *a;
	*a = *b;
	*b = temp;
	printf("SWAP_ADDR 함수 내부 -> a : %d, b : %d \n", *a, *b);
}
```

* 함수에서 파라미터를 변경해도 아규먼트로 보낸 원래 변수의 값은 변하지 않는다.
* 파라미터를 포인터 변수로 지정하고 아규먼트 변수 앞에 &를 붙일 수 있다.
	- 함수 내부에서 값을 수정하면 원래 변수의 주소값에 해당하는 값을 변경하는 것이기에 함수 밖 변수도 영향을 받는다.

```c
# include <stdio.h>

void change_array(int* ptr);

int main() {
	int arr[3] = { 10, 20, 30 };
	//change_array(arr);
	change_array(&arr[0]);
	
	for (int i = 0; i < 3; i++) {
		printf("%d \n", arr[i]);
	}
}

void change_array(int* ptr)
{
	ptr[2] = 50;
}
```

* 배열은 변수 자체가 주소값(배열[0])을 가지기 때문에 *를 붙이지 않아도 연동이 된다.
* `change_array(arr) == change_array(&arr[0])`

```c

// 프로젝트

#include <stdio.h>
#include <time.h>


int level;
int arrayFish[6];
int* cursor;
void initData();
void printfFishes();
void decreaseWater(long preTime);
int checkFishAlive();

int main() {

	long startTime = 0; // 시작 시간
	long totalTime = 0; // 총 시간
	long preTime = 0; // 직전 경과 시간

	int num; // 몇 번 어항에 물을 줄건지 입력
	initData();


	cursor = arrayFish; // cursor[0] = arrayFish[0]

	startTime = clock(); // 현재 시간을 1000분의 1초 수준으로 반환

	printf("%d %d %d %d \n", cursor[0], cursor[1], cursor[2], cursor[3]);

	while (1)
	{
		printfFishes();
		printf(" 몇 번 어항에 물을 줄래?");
		scanf_s("%d", &num);


		// 입력값 체크
		if (num < 1 || num > 6)
		{
			printf("잘못 입력");
			continue;
		}

		// 총 경과 시간
		totalTime = (clock() - startTime) / CLOCKS_PER_SEC;
		printf("총 경과 시간 : %ld 초 \n", totalTime);

		// 직전 물 준 시간
		preTime = totalTime - preTime;
		printf("최근 경과 시간 : %ld 초 \n", preTime);

		// 어항의 물을 감소
		decreaseWater(preTime);

		// 입력한 어항에 물을 준다
			// 어항의 물이 없으면 줄 수 없다.
		if (cursor[num - 1] <= 0)
		{
			printf("%d번 어항은 이미 말라버렸다...\n",num);
		}
			// 물이 100 이하이다.
		else if (cursor[num - 1] + 5 >= 100)
		{
			printf("%d번 어항에 물이 넘칠 것 같다...\n", num);
		}
		else
		{
			printf("%d번 어항에 물을 준다. \n", num);
			cursor[num - 1] += 5;
		}


		// 레벨 업 여부
		if ((int)totalTime / 20 > level - 1)
		{
			level += 1;
			printf("레벨 업! \n");

			if (level == 6)
			{
				printf("게임 클리어! \n");
				exit(0);
			}
		}

		// 모든 물고기가 죽었는지 확인
		if (checkFishAlive() == 0)
		{
			printf("게임오버... \n");
			exit(0);
		}
		else {
			printf("화이팅!\n");

		}

		preTime = totalTime;

	}


	return 0;
}

void initData()
{
	level = 1; // 게임 레벨
	for (int i = 0; i < 6; i++)
	{
		arrayFish[i] = 100; // 물 높이
		//printf("물높이 : %d \n", arrayFish[i]);
	}
}

void printfFishes()
{
	for (int i = 0; i < 6; i++)
	{
		printf("%3d번 ", i + 1);
	}
	printf("\n");

	for (int i = 0; i < 6; i++)
	{
		printf(" %4d ", arrayFish[i]);
	}
	printf("\n\n");

}

void decreaseWater(long preTime)
{
	for (int i = 0; i < 6; i++)
	{
		arrayFish[i] -= (level * 3 * (int)preTime); // 줄어든 물의 양 처리
		if (arrayFish[i] < 0)
		{
			arrayFish[i] = 0;
		}
	}
}

int checkFishAlive()
{
	for (int i = 0; i < 6; i++)
	{
		if (arrayFish[i] > 0)
		{
			return 1;
		}
	}
	return 0;
}

```

### 다차원 배열

```c
int arr5[4][2];
	/* 
	 1 2
	1ㅁㅁ
	2ㅁㅁ
	3ㅁㅁ
	4ㅁㅁ

	[0,0][0,1]
	[1,0][1,1]
	[2,0][2,1]
	[3,0][3,1]
	
	*/

	int arr3[2][3][4];
	/*
	ㅁㅁㅁ ㅁㅁㅁ ㅁㅁㅁ ㅁㅁㅁ
	ㅁㅁㅁ ㅁㅁㅁ ㅁㅁㅁ ㅁㅁㅁ

	*/

	int arr_1[3][6] = { 
		{1,2,3,4,5},
		{3,4},
		{1} 
	};

	int arr_2[2][2][2] = {
		{
			{1, 2},
			{3, 4}
		},
		{
			{5, 6},
			{7}

		}
	};
```

* `getchar()` 사용자가 입력할 때까지 기다리는 함수.

```c
// 프로젝트

#include <stdio.h>
#include <time.h>

int arrayAnimal[4][5];
int ckeckAnimal[4][5];
char* strAnimal[10];

void initAnimalArray();
void initAnimalName();
void shuffleAnimal();
int getEmptyPostion();
int conv_pos_x(pos);
int conv_pos_y(pos);
void printAnimals();
void printQuestion();
int foundAllAnimals();
int main()
{
	srand(time(NULL));

	initAnimalArray();
	initAnimalName();
	shuffleAnimal();

	int failCount = 0;

	while (1) {
		int select1 = 0;
		int select2 = 0;

		printAnimals();
		printQuestion();
		printf("뒤집을 카드 2개 선택 : ");
		scanf_s("%d %d", &select1, &select2);

		if (select1 == select2) continue;

		int firstSelect_x = conv_pos_x(select1);
		int firstSelect_y = conv_pos_y(select1);

		int secondSelect_x = conv_pos_x(select2);
		int secondSelect_y = conv_pos_y(select2);

		if (ckeckAnimal[firstSelect_x][firstSelect_y] + ckeckAnimal[secondSelect_x][secondSelect_y] == 0
			&&
			arrayAnimal[firstSelect_x][firstSelect_y] == arrayAnimal[secondSelect_x][secondSelect_y])
		{
			printf("\n\n 빙고! : %s 발견 \n", strAnimal[arrayAnimal[firstSelect_x][firstSelect_y]]);
			ckeckAnimal[firstSelect_x][firstSelect_y] = 1;
			ckeckAnimal[secondSelect_x][secondSelect_y] = 1;
		}
		else if (ckeckAnimal[firstSelect_x][firstSelect_y] + ckeckAnimal[secondSelect_x][secondSelect_y] != 0)
		{
			printf("이미 뒤집힌 카드입니다. \n");
			failCount++;
		}

		else
		{
			printf("땡! \n");
			failCount++;
		}
		printf("%d : %s \n", select1, strAnimal[arrayAnimal[firstSelect_x][firstSelect_y]]);
		printf("%d : %s \n", select2, strAnimal[arrayAnimal[secondSelect_x][secondSelect_y]]);

	}

	if (foundAllAnimals())
	{
		printf("게임 클리어!");
		printf("총 %d 번 틀렸습니다.", failCount);
		exit(0);
	}

	return 0;
}


void initAnimalArray()
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
			arrayAnimal[i][j] = -1;
		}
	}
}

void initAnimalName()
{
	strAnimal[0] = "원숭이";
	strAnimal[1] = "하마";
	strAnimal[2] = "강아지";
	strAnimal[3] = "고양지";
	strAnimal[4] = "돼지";
	strAnimal[5] = "코끼리";
	strAnimal[6] = "기린";
	strAnimal[7] = "낙타";
	strAnimal[8] = "타조";
	strAnimal[9] = "호랑이";

}

void shuffleAnimal()
{
	// ㅁㅁㅁㅁㅁ
	// ㅁㅁㅁㅁㅁ
	// ㅁㅁㅁㅁㅁ
	// ㅁㅁㅁㅁㅁ
	// ㅁㅁㅁㅁㅁ
	for (int i = 0; i < 10; i++) // 동물 짝 설정
	{
		for (int j = 0; j < 2; j++)
		{
			int pos = getEmptyPostion();
			int x = conv_pos_x(pos);
			int y = conv_pos_y(pos);

			arrayAnimal[x][y] = i;
		}
	}
}

// 빈 공간 찾기
int getEmptyPostion()
{
	while (1)
	{
		int randPos = rand() % 20; // 0 ~ 19 사이의 숫자를 반환
		int x = conv_pos_x(randPos);
		int y = conv_pos_y(randPos);

		if (arrayAnimal[x][y] == -1)
		{
			return randPos;
		}
	}
	return 0;
}

int conv_pos_x(pos)
{
	int x = pos / 5;
	return x;
}

int conv_pos_y(pos)
{
	int y = pos % 5;
	return y;
}


void printAnimals()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("%8s", strAnimal[arrayAnimal[i][j]]);
		}
		printf("\n");
	}
	printf(" \n ===============정답================\n");
}


void printQuestion()
{
	printf("\n\n 문제 \n\n");
	int seq = 0;

	/*								//seq				/checkAnimal
		ㅁㅁㅁㅁㅁ				0 1 2 3 4				0 0 0 0 0
		ㅁㅁㅁㅁㅁ				돼지 6 7 8 9 돼지			1 0 0 0 1
		ㅁㅁㅁㅁㅁ
		ㅁㅁㅁㅁㅁ
		ㅁㅁㅁㅁㅁ

	*/


	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			// 카드를 뒤집어서 정답을 맞추면 "동물 이름"
			if (ckeckAnimal[i][j] != 0)
			{
				printf("%8s", strAnimal[arrayAnimal[i][j]]);
			}

			// 아직 못 맞혔다면 숫자
			else
			{
				printf("%8d", seq);
			}
			seq++;

		}
		printf("\n");
	}
}

int foundAllAnimals()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (ckeckAnimal[i][j] == 0)
			{
				return 0;
			}
		}
	}
	return 1;
}

```

* int형 배열은 초기 선언 시 자동으로 모든 값을 0으로 초기화한다.

### 구조체

```c

#include <stdio.h>

struct GameInfo
{
	char* name;
	int year;
	int price;
	char* company;
};

int main()
{
struct GameInfo gameInfo1;
	
	gameInfo1.name = "나도게임";
	gameInfo1.year = 2017;
	gameInfo1.price = 50;
	gameInfo1.company = "나도회사";

	struct GameInfo gameInfo2 = { "게임게임", 2020, 100, "나거히소" };

	return 0;
}
```

* struct를 사용해서 구조체 선언
* 파이썬 클래스와 비슷
* 구조체를 자료형(?)을 선언하고 중괄호 안에 값들을 넣으면 차례대로 초기화된다. 

```c
	struct GameInfo gameArray[2] = { 
	{ "게임게임", 2020, 100, "나거히소" },
	{ "게게게임임", 2018, 190, "메피비즘" }
	};
```

* 배열로도 구조체를 만들 수 있음.

```c
	struct GameInfo *gamePtr;
	gamePtr = &gameInfo1;
	printf("포인터 \n");
	printf("  게임명 : %s\n", (*gamePtr).name);
	printf("  게임명 : %d\n", (*gamePtr).year);
	printf("  게임명 : %d\n", (*gamePtr).price);
	printf("  게임명 : %s\n", (*gamePtr).company);

	printf("  게임명 : %s\n", gamePtr->name);
	printf("  게임명 : %d\n", gamePtr->year);
	printf("  게임명 : %d\n", gamePtr->price);
	printf("  게임명 : %s\n", gamePtr->company);



```

* 포인터로 구조체를 만들 수 있음.
* 주소값에 해당하는 자료(값)에 접근하기 위해서 `*`를 사용
	- 기존처럼 `*포인터변수.구조체변수`라고 쓰면 포인터변수.구조체변수의 주소값을 찾으려고 함.
	- `*`와 포인터변수를 괄호로 묶어놓아야만 정상 작용.
* `포인터변수 -> 구조체변수`같은 편리한 방식으로 접근 가능

```c
#include <stdio.h>

typedef struct //GameInfomation 
{
	char* name;
	int year;
	int price;
	char* company;
	struct GameInfo* friendGame;
} GAME_INFO;


int main()
{

	// 구조체의 구조체
	gameInfo1.friendGame = &gameInfo2;
	printf("구조체 안의 구조체\n");

	printf("  게임명 : %s\n", gameInfo1.friendGame->name);
	printf("  게임명 : %d\n", gameInfo1.friendGame->year);
	printf("  게임명 : %d\n", gameInfo1.friendGame->price);
	printf("  게임명 : %s\n", gameInfo1.friendGame->company);

	// typedef
	// 자료형에 이름 지정
	int i = 1;
	typedef int 정수;
	정수 j = 3;
	printf("%d, %d \n", i, j);

	typedef struct GameInfo 게임정보;
	게임정보 game1;
	game1.name = "한글게임1";
	game1.year = 4124;
	printf ("%d %d \n", game1.name, game1.year);

	
	GAME_INFO game2;
	game2.name = "한글 겡미2";
	game2.year = 3213;
	printf("%s %d \n", game2.name, game2.year);


	return 0;


}
```

* `typedef`
	- 자료형에 이름을 지정할 수 있게 된다.
	- `typedef` `바꾸고 싶은 자료형` `바꾸고 싶은 이름`
	- `struct 구조체 이름`같은 두 개 이상의 문장도 치환시키는 게 가능하다. 
	- 구조체를 선언할 때 앞에 `typedef`를 붙이고 중괄호 마지막에 치환할 이름을 적을 수 있다.
		- `typedef struct`처럼 구조체의 이름을 지워도 선언에는 문제 없지만 구조체 이름을 적은 코드는 에러가 난다.

---

### 파일 입출력

* fputs, fgets
*  fprintf, fscanf 