#include <stdio.h>
#include <time.h>

typedef struct {
	char* name;
	int age;
	char* character;
	int level;
}CAT;

// 현재까지 보유한 고양이
int collection[5] = { 0, 0,0,0,0 };

CAT cats[5];

void initCats(); // 정보 초기화
void printCat();
int checkCollection();

int main_struct_project()
{
	srand(time(NULL));

	initCats();
	while (1)
	{
		printf("아무키나 눌러서 확인.\n");
		getchar();

		int selected = rand() % 5;
		printCat(selected); // 뽑은 고양이 정보 출력
		// 고양이 뽑기 처리

		if (collection[selected] == 0)
		{
			printf("새로운 고양이!\n");
			collection[selected] = 1;
		}

		int collectAll = checkCollection();

		if (collectAll)
		{
			break;
		}
	}

	return 0;
}

void initCats()
{
	cats[0].name = "감미";
	cats[0].age = 5;
	cats[0].character = "온순";
	cats[0].level = 1;

	cats[1].name = "추노";
	cats[1].age = 3;
	cats[1].character = "괴팍";
	cats[1].level = 2;

	cats[2].name = "감꼬르";
	cats[2].age = 6;
	cats[2].character = "피곤";
	cats[2].level = 3;

	cats[3].name = "오소이";
	cats[3].age = 2;
	cats[3].character = "배고픔";
	cats[3].level = 4;

	cats[4].name = "감마러호";
	cats[4].age = 55;
	cats[4].character = "천재";
	cats[4].level = 5;
}

void printCat(int selected)
{
	printf("당신이 뽑은 고양이 \n");
	printf("이름 : %s \n", cats[selected].name);
	printf("나이 : %d \n", cats[selected].age);
	printf("성격 : %s \n", cats[selected].character);
	printf("레벨 :    "); 
	for (int i = 0; i < cats[selected].level; i++) printf("*");
	printf("\n");

}

int checkCollection()
{

	int collectAll = 1;
	printf("보유한 고양이 목록 \n");
	for (int i = 0; i < 5; i++)
	{
		if (collection[i] == 0)
		{
			printf("%10s", "(빈 박스)");
			collectAll = 0;
		}
		else 
		{
			printf("%10s", cats[i].name);
		}

	}
	printf("\n==================================\n");

	if (collectAll)
	{
		printf("축하합니다!\n");
	}

	return collectAll;
}