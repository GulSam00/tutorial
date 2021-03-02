#define _CPR_SECURE_NO_WARNINGS

#include <stdio.h>
#define MAX 10000 // MAX가 '10000'의 상수가 됨.

int main_file()
{
	// 파일 입출력
	// 파일에 데이터를 저장
	// 파일에 저장된 데이터를 불러오기

	// fputs, fgets 쌍 -> 문자열
	//char line[MAX]; // char line[10000]

	// 파일 쓰기
	/*
		FILE * file = fopen("C:\\Users\\qwerg\\OneDrive\\Desktop\\test1.txt", "wb"); // r : 읽기, w : 쓰기, a : 추가 (뒤에 쓰기) | t : 텍스트, b : 바이널 데이터
	if (file == NULL)
	{
		printf("열기 실패!");
		return 1;
	}
	fputs("fputs을 이용해서 글을 적습니다.\n", file);
	fputs("잘 적히는지 확인 \n", file);
	fclose(file);
	*/


	// 파일을 열고 나서 닫지 않은 상태에서 프로그램에 문제가 생길 수 있음.
	// 파일을 닫는 습관

	// 파일 읽기

	/*

	FILE* file = fopen("C:\\Users\\qwerg\\OneDrive\\Desktop\\test1.txt", "rb"); // r : 읽기, w : 쓰기, a : 추가 (뒤에 쓰기) | t : 텍스트, b : 바이널 데이터
	if (file == NULL)
	{
		printf("열기 실패!");
		return 1;
	}
	while (fgets(line, MAX, file) != NULL) // 저장될 곳, 사이즈, 파일 포인터
	{
		printf("%s", line);
	}
		fclose(file);
	*/


	// fprintf, fscanf 쌍 

	int num[6] = { 0,0,0,0,0,0 };
	int bonus = 0;
	char str1[MAX];
	char str2[MAX];
	/*
	FILE* file = fopen("C:\\Users\\qwerg\\OneDrive\\Desktop\\lottery.txt", "wb");
	if (file == NULL)
	{
		printf("파일 열기 실패\n");
		return 1;
	}
	fprintf(file, "%s %d %d %d %d %d %d\n", "추첨번호", 1, 2, 3, 4, 5, 6);
	fprintf(file, "%s %d \n", "보너스 번호 ", 7);

	fclose(file);
	*/

	FILE* file = fopen("C:\\Users\\qwerg\\OneDrive\\Desktop\\lottery.txt", "rb"); // r : 읽기, w : 쓰기, a : 추가 (뒤에 쓰기) | t : 텍스트, b : 바이널 데이터
	if (file == NULL)
	{
		printf("열기 실패!");
		return 1;
	}

	fscanf(file, "%s %d %d %d %d %d %d", str1, &num[0], &num[1], &num[2], &num[3], &num[4], &num[5]);
	printf("%s %d %d %d %d %d %d\n", str1,
		num[0], num[1], num[2], num[3], num[4], num[5]);

	fscanf(file, "%s %d", str2, &bonus);
	printf("%s %d\n", str2, bonus);

	fclose(file);

	return 0;
}