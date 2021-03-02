#include <stdio.h>
#include <time.h>
/*

int main()
{
	int subway[3] = {10, 20, 30};

	for (int i = 0; i < 3; i++) {
		printf("지하철 %d호차에 타고 있는 승객 : %d \n", i + 1, subway[i]);
	}

	int arr[10] = { 10 };
	for (int i = 0; i < 9; i++) {
		printf("%p \n", arr[i]);
	}
	printf("%p %p\n", arr, arr[0]);

	return 0;
}
*/

/* 

int main()
{

	char df[] = "cdignd";
	for (int i = 0; i < sizeof(df); i++) printf("%c\n", df[i]);

	char str[] = "coding";
	printf ("%d", sizeof(str));
	printf("%s", str);

	char c_array[9] = { 'c','d','s','\0'};
	for (int i = 0; i < sizeof(c_array); i++)
	{
		printf("\n %d", c_array[i]);
	}

	printf("%c \n", 'a');
	printf("%d \n", 'a');
	return 0;

*/

/*

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

*/