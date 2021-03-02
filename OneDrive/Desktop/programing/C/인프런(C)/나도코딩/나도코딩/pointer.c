#include <stdio.h>
#include <time.h>

/*
int main()
{
	int a = 1;
	int b = 2;
	int c = 3;

	int* ad;
	int* bd;

	ad = &a;
	bd = &a;

	printf("%p \n", ad);
	printf("%d \n", *ad);

	*ad += 3;

	printf("%p \n", ad);
	printf("%d \n", a);
	printf("%d \n", *ad);

	bd = &c;
	*bd -= 2;

	printf("%p \n", &c);
	printf("%d \n", *bd);

	printf("%p \n", &bd);

	return 0;
}
*/

/*

int main()
{
	int arr[3] = {10, 20, 30};
	int* ptr = &arr;
	for (int i = 0; i < 3; i++)
	{
		printf("배열 arr[%d]의 값 : %d \n", i, arr[i]);
	}

	for (int i = 0; i < 3; i++)
	{
		printf("포인터 ptr[%d]의 값 : %d \n", i, ptr[i]);
	}

	ptr[0] = 100;
	ptr[1] = 200;

	for (int i = 0; i < 3; i++)
	{
		//printf("배열 arr[%d]의 값 : %d \n", i, arr[i]);
		printf("배열 arr[%d]의 값 : %d \n", i, *(arr + i));

	}

	for (int i = 0; i < 3; i++)
	{
		//printf("포인터 ptr[%d]의 값 : %d \n", i, ptr[i]);
		printf("포인터 ptr[%d]의 값 : %d \n", i, *(ptr + i));
		printf("포인터 ptr[%d]의 주소값 : %p \n", i, ptr + i);

	}
	// *(arr + i) == arr[i]
	// 배열의 주소 == 배열의 0번째(첫번째) 주소

	printf("arr 자체의 값 : %p\n", arr);
	printf("arr[0]의 주소 : %p\n", &arr[0]);

	printf("arr 자체의 값이 가지는 주소의 실제 값 : %d \n", *arr); // *(arr + 0)
	printf("arr[0]의 실제 값 : %d \n", arr[0]);


	// *&는 아무것도 것는 것과 같다. &는 주소, *은 주소의 값
	// *& 붙어있으면 서로 상쇄.

	return 0;
}
*/

/*
void swap(int a, int b);
void swap_addr(int *a, int *b);
int main() {
	int a = 10;
	int b = 20;
	printf("a의 주소 : %p \n", &a);
	printf("b의 주소 : %p \n", &b);
	printf("SWAP 함수 전 -> a : %d, b : %d \n", a, b);
	swap(a, b);
	printf("SWAP 함수 후 -> a : %d, b : %d \n", a, b);

	printf("\n\n");
	// 값에 의한 복사 (Call by Value) -> 변수가 아닌 값만 복사, 지역함수 개념?

	// 메모리 공간의 주소값 자체를 넘기면?
	printf("a의 주소 : %p \n", &a);
	printf("b의 주소 : %p \n", &b);
	printf("SWAP_ADDR 함수 전 -> a : %d, b : %d \n", a, b);
	swap_addr(&a, &b);
	printf("SWAP_ADDR 함수 후 -> a : %d, b : %d \n", a, b);
	return 0;
}

void swap(int a, int b)
{
	printf("a의 주소 : %p \n", &a);
	printf("b의 주소 : %p \n", &b);
	int temp = a;
	a = b;
	b = temp;
	printf("SWAP 함수 내부 -> a : %d, b : %d \n", a, b);
}

void swap_addr(int *a, int *b)
{
	printf("a의 주소 : %p \n", &a);
	printf("b의 주소 : %p \n", &b);
	int temp = *a;
	*a = *b;
	*b = temp;
	printf("SWAP_ADDR 함수 내부 -> a : %d, b : %d \n", *a, *b);
}


*/

/* 

void change_array(int* ptr);

int main() {
	int arr[3] = { 10, 20, 30 };
	//change_array(arr);
	change_array(&arr[0]);

	for (int i = 0; i < 3; i++) {
		printf("%d \n", arr[i]);
	}
}

void change_array(int* ptr)
{
	ptr[2] = 50;
}
*/


/*

void test();
int arr[3];
int main()
{
	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 3;

	printf("%d %d %d \n", arr[0], arr[1], arr[2]);
	test(arr);
	printf("%d %d %d \n", arr[0], arr[1], arr[2]);
}

void test()
{
	arr[0] = 10;
	arr[1] = 20;
	arr[2] = 30;
	printf("%d %d %d \n", arr[0], arr[1], arr[2]);
}


*/