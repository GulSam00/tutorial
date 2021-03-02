/*
// 문제1
#include <stdio.h>

int magicbox(int num)
{
	return num + 4;
}

int main()
{
	int num;
	printf("input the number : ");
	scanf_s("%d", &num);
	// magicbox(num);
	num = magicbox(num);
	printf("sum : %d", num);

	return 0;
}
*/

/*

//문제 2
#include <stdio.h>
int slave(int total_money, int earned_money)
{
	total_money += earned_money;
	return total_money;
}
int main()
{
	int total_money = 0;
	int earned_money;
	printf("input today income \n");
	while(1)
	{

	scanf_s("%d", &earned_money);
	if (earned_money == 0) break;
	total_money = slave(total_money, earned_money);
	printf("earned_money : %d \n total money : %d \n", earned_money, total_money);
	}
	return 0;
}
*/

/*
#include <stdio.h>
// 문제 3
int sum_n(int n)
{
	int sum = 1;
	for (int i = 1; i <= n; i++)
	{
		sum *= i;
	}
	return sum;
}

int main()
{
	int n = 0;
	scanf_s("%d", &n);
	printf("sum = %d", sum_n(n));
	return 0;
}
*/

/*

#include <stdio.h>
// 문제 4
int num_n(int n)
{
	int array[100] = {2, 3};
	int count = 2;
	int check = 1;
	for (int i = 4; i <= n; i++)
	{
		for (int j = 0; j < count; j++)	if (i % array[j] == 0) check = 0;

		if (check)
		{
			array[count] = i;
			count++;
		}
		check = 1;
	}

	for (int i = 0; i < count; i++) printf("소수 : %d \n", array[i]);

	return 0;
}

int main()
{
	int n = 0;
	scanf_s("%d", &n);
	num_n(n);
	return 0;
}
*/


/*

// 올바른 swap 함수 
#include <stdio.h>
int swap(int* a, int* b) {
	int temp = *a;

	*a = *b;
	*b = temp;

	return 0;
}

int main()
{
	int i, j;

	i = 3;
	j = 5;

	printf("스왑 전 : i : %d, j : %d \n", i, j);
	swap(&i, &j);
	printf("스왑 후 : i : %d, j : %d \n", i, j);

	return 0;

}
*/

/*
#include <stdio.h>

int add_number(int* parr);

int main()
{
	int arr[3];
	int i;

	for (i = 0; i < 3; i++)
	{
		scanf_s("%d", &arr[i]);
	}

	add_number(arr);

	printf("배열의 각 원소 : %d %d %d", arr[0], arr[1], arr[2]);

	return 0;
}

int add_number(int* parr)
{
	int i;
	for (i = 0; i < 3; i++)
	{
		parr[i]++;
		// *(parr0+i)++;
	}
	return 0;
}

*/

/*

// 눈 돌아가는 예제. 포인터가 가리키는 변수를 서로 바꾼다. 
#include <stdio.h>

int pswap(int** pa, int** pb);
int main() {
	int a, b;
	int* pa, * pb;

	pa = &a;
	pb = &b;

	printf("pa 가 가리키는 변수의 주소값 : %p \n", pa);
	printf("pa 의 주소값 : %p \n \n", &pa);
	printf("pb 가 가리키는 변수의 주소값 : %p \n", pb);
	printf("pb 의 주소값 : %p \n", &pb);

	printf(" ------------- 호출 -------------- \n");
	pswap(&pa, &pb);
	printf(" ------------- 호출끝 -------------- \n");

	printf("pa 가 가리키는 변수의 주소값 : %p \n", pa);
	printf("pa 의 주소값 : %p \n \n", &pa);
	printf("pb 가 가리키는 변수의 주소값 : %p \n", pb);
	printf("pb 의 주소값 : %p \n", &pb);
	return 0;
}
int pswap(int** ppa, int** ppb) {
	int* temp = *ppa;

	printf("ppa 가 가리키는 변수의 주소값 : %p \n", ppa);
	printf("ppb 가 가리키는 변수의 주소값 : %p \n", ppb);

	*ppa = *ppb;
	*ppb = temp;

	return 0;
}
*/

/* 2 차원 배열의 각 원소를 1 씩 증가시키는 함수 
#include <stdio.h>
/* 열의 개수가 2 개인 이차원 배열과, 총 행의 수를 인자로 받는다. 
int add1_element(int(*arr)[2], int row);
int main() {
	int arr[3][2];
	int i, j;

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 2; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	add1_element(arr, 3);

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 2; j++) {
			printf("arr[%d][%d] : %d \n", i, j, arr[i][j]);
		}
	}
	return 0;
}
int add1_element(int(*arr)[2], int row) {
	int i, j;
	for (i = 0; i < row; i++) {
		for (j = 0; j < 2; j++) {
			arr[i][j]++;
		}
	}

	return 0;
}
*/

/*

// 상수를 인자로 받아들이기
#include <stdio.h>
int read_val(const int val);
int main() {
	int a;
	scanf("%d", &a);
	read_val(a);
	return 0;
}
int read_val(const int val) {
	val = 5;  // 허용되지 않는다.
	return 0;
}
*/

/* 
//함수 포인터 
#include <stdio.h>

int max(int a, int b);
int main() {
	int a, b;
	int (*pmax)(int, int);
	pmax = max;

	scanf("%d %d", &a, &b);
	printf("max(a,b) : %d \n", max(a, b));
	printf("pmax(a,b) : %d \n", pmax(a, b));

	return 0;
}
int max(int a, int b) {
	if (a > b)
		return a;
	else
		return b;

	return 0;
}
*/

/*

#include <stdio.h>


void input_score(int* grade);
void print_score(int* grade, int ave);
int main()
{
	int grade[5];
	int ave= 0;
	input_score(grade);

	for (int i = 0; i < 5; i++)
	{
		ave += grade[i];
	}
	ave /= 5;

	print_score(grade,ave);

	return 0;
}

void input_score(int* grade)
{
	for (int i = 0; i < 5; i++)
	{
		scanf_s("%d", &grade[i]);
		//printf("%d \n", grade[i]);
	}
}

void print_score(int* grade, int ave)
{
	int tmp;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (grade[i] > grade[j])
			{
				tmp = grade[i];
				grade[i] = grade[j];
				grade[j] = tmp;
			}
		}
	}
	for (int k = 0; k < 5; k++)
	{
		if (grade[k] >= ave) printf("합격 - ");
		else printf("불합격 - ");

		printf("%d \n", grade[k]);
	}
}

*/


/* 
//샘플 코드 
#include <stdio.h>

int main() {
	int arr[10];
	int i;

	for (i = 0; i < 10; i++) {
		scanf("%d", &arr[i]);
	}
	for (i = 0; i <= 10; i++) {
		printf("%d \n", arr[i]);
	}
	return 0;
}
*/

/*

#include <stdio.h>
int cmp(char* s1, char* s2);
int length(char* s);
int main(void)
{
	char str1[500];
	char str2[500];
	scanf("%[^\n]", str1);
	getchar();
	scanf("%[^\n]", str2);
	printf("%d\n", cmp(str1, str2));
}
int cmp(char* s1, char* s2)
{
	int i;
	if (length(s1) != length(s2)) {
		return 0;
	}
	else {
		for (i = 0; i < length(s1); i++) {
			if (s1[i] == s2[i]) {
				continue;
			}
			else {
				return 0;
			}
		}
		return 1;
	}
}
int length(char* s)
{
	int i = 0;
	while (s[i]) {
		i++;
	}
	return i;
}
*/

/*


#include <stdio.h>


int append_book(char(*book_name)[30], char(*auth_name)[30],
	char(*publ_name)[30], int* borrowed, int* num_total_book);
int search_book(char(*book_name)[30], char(*auth_name)[30],
	char(*publ_name)[30], int num_total_book);
int compare(char* str1, char* str2);
int borrow_book(char* book_list, int book_amount, char* borrowed_book);
int return_book(char* book_list, int book_amount, char* borrowed_book);
int main()
{

	char book_name[100][30], auth_name[100][30], publ_name[100][30];
	int num_total_book = 0;
	int select = 0;
	int borrowed[100];

	// 1 : 책 추가 - 제목, 저자, 출판사
	// 2 : 검색 - 제목 검색, 저자 검색, 출판사 검색
	// 3 : 대출
	// 4 : 반납
	while (select != 5)
	{
		select = 0;
		printf("도서 관리 프로그램 \n");
		printf("메뉴를 선택하세요 \n");
		printf("1. 책을 새로 추가하기 \n");
		printf("2. 책을 검색하기 \n");
		printf("3. 책을 빌리기 \n");
		printf("4. 책을 반납하기 \n");
		printf("5. 프로그램 종료 \n");

		printf("당신의 선택은 : ");
		scanf("%d", &select);

		if (select == 1) 
			/* 책을 새로 추가하는 함수 호출 
append_book(book_name, auth_name, publ_name, borrowed, &num_total_book);
		}
		else if (select == 2
		/* 책을 검색하는 함수 호출 
		search_book(book_name, auth_name, publ_name, num_total_book);
		}
		else if (select == 3) {
		/* 책을 빌리는 함수 호출 
		}
		else if (select == 4) {
		/* 책을 반납하는 함수 호출 
		}
		else if (select == 5) {
		/* 프로그램을 종료한다. 
		break;
		}
	}

	return 0;
}

// 1. 책 추가
int append_book(char(*book_name)[30], char(*auth_name)[30],
	char(*publ_name)[30], int* borrowed, int* num_total_book)
{
	printf("추가할 책의 제목 : ");
	scanf("%s", book_name[*num_total_book]);

	printf("추가할 책의 저자 : ");
	scanf("%s", auth_name[*num_total_book]);

	printf("추가할 책의 출판사 : ");
	scanf("%s", publ_name[*num_total_book]);

	borrowed[*num_total_book] = 0; 
	printf("추가 완료! \n");
	(*num_total_book)++;

	return 0;
}
int search_book(char(*book_name)[30], char(*auth_name)[30],
	char(*publ_name)[30], int num_total_book)
{
	int user_input, i;
	char user_search[30];
	printf("%d, %p", num_total_book, num_total_book);

	printf("검색 방식\n");
	printf("1. 책 제목 \n");
	printf("2. 지은이 \n");
	printf("3. 출판사 \n");
	scanf("%d", &user_input);
	printf("검색어 입력 : ");
	scanf("%s", user_search);

	if (user_input == 1)
	{
		for (i = 0; i < num_total_book; i++)
		{
			if (compare(book_name[i], user_search))
			{
				printf("번호 : %d // 책 이름  : %s // 지은이 : %s // 출판사 : %s \n",
					i, book_name[i], auth_name[i], publ_name[i]);
			}
		}
	}


	else if (user_input == 2)
	{
		for (i = 0; i < num_total_book; i++)
		{
			if (compare(auth_name[i], user_search))
			{
				printf("번호 : %d // 책 이름  : %s // 지은이 : %s // 출판사 : %s \n",
					i, book_name[i], auth_name[i], publ_name[i]);
			}
		}
	}

	else if (user_input == 3)
	{
		for (i = 0; i < num_total_book; i++)
		{
			if (compare(publ_name[i], user_search))
			{
				printf("번호 : %d // 책 이름  : %s // 지은이 : %s // 출판사 : %s \n",
					i, book_name[i], auth_name[i], publ_name[i]);
			}
		}
	}

	return 0;
}
int compare(char* str1, char* str2) {
	while (*str1) {
		if (*str1 != *str2) {
			return 0;
		}

		str1++;
		str2++;
	}

	if (*str2 == '\0') return 1;

	return 0;
}
*/