#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 비밀번호를 입력
// 맞는 경우에는 비밀 읽기를 읽어서 보여주고 계속 작성
// 틀린 경우 경고 메세지

# define MAX 10000

int main()
{
	//fgets, fputs 활용
	char line[MAX]; // 파일에서 불러온 내용을 저장할 변수
	char contents[MAX]; // 일기장에 입력할 내용
	char password[20]; // 비밀번호 입력
	char c; // 비밀번호 입력 할 때 키값 확인용

	printf("====================비밀일기====================\n");
	printf("비밀번호 입력 : ");

	//getchar() : 엔터를 입력받아야 동작
	//getch() : 키 입력 시 바로바로 동작
	int i = 0;
	while (1)
	{
		c = getch();
		if (c == 13) // Enter를 뜻하는 아스키코드
		{
			password[i] = '\0';
			break;
		}
		else
		{
			printf("*");
			password[i] = c;
		}
		i++;
	}

		// 비밀번호 : skehzheld
		printf("\n\n==========비밀번호 확인 중...==========");
		if (strcmp(password, "skehzheld") == 0) // strcmp(비교대상, 비교대상) / 동일하면 0, 다르면 1이나 -1
		{
			printf(" === 비밀번호 확인 완료 === \n\n");
			char* fileName = "C:\\Users\\qwerg\\OneDrive\\Desktop\\diary.txt";
			FILE * file = fopen(fileName, "a+b"); // 파일이 없으면 생성, 파일이 있으면 append (뒤에서부터)

			if (file == NULL)
			{
				printf("파일 열기 실패\n");
				return 1;
			}

			while (fgets(line, MAX, file) != NULL)
			{
				printf("%s", line);
			}

			printf("\n\n 내용을 계속 작성하세요! 종료하려면 EXIT를 입력하세요. \n\n");

			while (1)
			{
				scanf("%[^\n]", contents); // %[^\n] : 줄바꿈(\n)이 나오기 전까지 읽음 (한 문장 씩)
				getchar(); // Enter 입력 (\n) Flush 처리

				if (strcmp(contents, "EXIT") == 0)
				{
					printf("비밀일기 입력을 종료 \n\n");
					break;
				}
				fputs(contents, file);
				fputs("\n", file); // Enter를 위에서 무시하였으므로 처리
			}
			fclose(file);
				
		}
		else
		{
			printf ("\n\n===========비밀번호가 틀렸습니다.========== \n\n");

		}
	



	return 0;
}