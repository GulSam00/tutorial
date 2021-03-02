#include <stdio.h>
#include <time.h>

/* 

int p(int num);

int main()
{
	/*

	char str[256];
	scanf("%s", str, sizeof(str));
	printf("%s", str);
	return 0;
	*/

	/*

	char name[256];
	printf("이름 ");
	scanf("%s", name, sizeof(name));

	int age;
	printf("나이 ");
	scanf("%d", &age);

	float weight;
	printf("몸무게 ");
	scanf("%f", &weight);

	double height;
	printf("키 ");
	scanf("%lf", &height);


	printf(" \n \n --- 범죄자 정보 --- \n \n");
	printf("이름 : %s \n ", name);
	printf("나이 : %d \n", age);
	printf("몸무게 : %.2f \n", weight);
	printf("키 : %.2lf \n", height);

	return 0;

	*/

	/*
	// 피라미드

	int floor;
	printf("몇 층?");
	scanf("%d", &floor);

	for (int i = 0; i < floor; i++) {
		for (int j = i; j < floor - 1; j++) printf(" ");

		for (int k = 0; k < i * 2 + 1; k++) printf("*");

		printf("\n");
	}

	return 0;
	*/

	/*

	srand(time(NULL));
	int i = rand() % 3; // 0 ~ 2 사이
	if (i == 0) printf("가위");
	else if (i == 1) printf("바위");
	else printf("보");

	int age = 10;
	switch (age)
	{
	case 2:
		case 9:
		case 10:
			case 11: printf("오하"); break;
		case 12:
		case 13:
		case 14:
		case 15:
			case 16: printf("항러"); break;
			case 17: printf("ㅎ하"); break;
		}
		return 0;
	*/
	/*
	srand(time(NULL));
	int num = rand() % 100 + 1; // 1 ~ 100
	printf("%d \n", num);
	int answer;
	int chance = 5;
	while (1) {
		answer = 0;
		printf("남은 기회 : %d \n", chance--);
		scanf("%d", &answer);

		if (num < answer)
		{
			printf("높아! \n");
		}
		else if (num > answer)
		{
			printf("낮아! \n");
		}
		else if (num == answer)
		{
			printf("정답! \n");
			break;
		}
		else {
			printf("뭘 입력한거야...? \n");
		}

		if (chance == 0) {
			printf("실패! \n");
			break;
		}

	}

	return 0;

int num = 2;
num = p(num);
printf("%d", num);

return 0;

}

// 함수 정의
int p(int num)
{
	num += 4;
	return num;
}
*/

