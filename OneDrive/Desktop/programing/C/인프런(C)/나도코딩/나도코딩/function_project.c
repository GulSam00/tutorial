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