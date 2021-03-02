#include <stdio.h>
#include <time.h>

int level;
int arrayFish[6];
int* cursor;
void initData();
void printfFishes();
void decreaseWater(long preTime);
int checkFishAlive();

int main_pointer() {

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
			printf("%d번 어항은 이미 말라버렸다...\n", num);
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
