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
int main_m_array()
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


		if (foundAllAnimals() == 1)
		{
			printf("게임 클리어!");
			printf("총 %d 번 틀렸습니다.", failCount);
			exit(0);
		}

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
	strAnimal[3] = "고양이";
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