#include <stdio.h>

struct GameInfo
{
	char* name;
	int year;
	int price;
	char* company;

	struct GameInfo * friendGame;
};

typedef struct GameInfomation {
	char* name;
	int year;
	int price;
	char* company;
	struct GameInfo* friendGame;
} GAME_INFO;

int main_struct()
{
	//게임 출시

	struct GameInfo gameInfo1;
	
		gameInfo1.name = "나도게임";
		gameInfo1.year = 2017;
		gameInfo1.price = 50;
		gameInfo1.company = "나도회사";

	

		printf("게임 출시 정보 \n");
		printf("  게임명 : %s\n", gameInfo1.name);
		printf("  게임명 : %d\n", gameInfo1.year);
		printf("  게임명 : %d\n", gameInfo1.price);
		printf("  게임명 : %s\n", gameInfo1.company);

		struct GameInfo gameInfo2 = { "게임게임", 2020, 100, "나거히소" };


	printf("게임 출시 정보 \n");
	printf("  게임명 : %s\n", gameInfo2.name);
	printf("  게임명 : %d\n", gameInfo2.year);
	printf("  게임명 : %d\n", gameInfo2.price);
	printf("  게임명 : %s\n", gameInfo2.company);

	struct GameInfo gameArray[2] = { 
	{ "게임게임", 2020, 100, "나거히소" },
	{ "게게게임임", 2018, 190, "메피비즘" }
	};
	printf("포인터 \n");
	printf("  게임명 : %s\n", gameArray[1].name);
	printf("  게임명 : %d\n", gameArray[1].year);
	printf("  게임명 : %d\n", gameArray[1].price);
	printf("  게임명 : %s\n", gameArray[1].company);


	struct GameInfo *gamePtr;
	gamePtr = &gameInfo1;
	printf("포인터 \n");
	/*
	printf("  게임명 : %s\n", (*gamePtr).name);
	printf("  게임명 : %d\n", (*gamePtr).year);
	printf("  게임명 : %d\n", (*gamePtr).price);
	printf("  게임명 : %s\n", (*gamePtr).company);
	*/
	printf("  게임명 : %s\n", gamePtr->name);
	printf("  게임명 : %d\n", gamePtr->year);
	printf("  게임명 : %d\n", gamePtr->price);
	printf("  게임명 : %s\n", gamePtr->company);


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
	printf("%s %d \n", game1.name, game1.year);


	GAME_INFO game2;
	game2.name = "한글 겡미2";
	game2.year = 3213;
	printf("%s %d \n", game2.name, game2.year);



	return 0;


}