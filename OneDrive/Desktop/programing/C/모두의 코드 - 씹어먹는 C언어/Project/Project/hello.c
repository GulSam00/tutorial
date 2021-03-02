#include <stdio.h>
/*
 
/*
* 
* 
int main() {

	/* int a = 0xAF;  // 10101111
	int b = 0xB5;  // 10110101

	printf("%x \n", a & b);   // a & b = 10100101
	printf("%x \n", a | b);   // a | b =10111111
	printf("%x \n", a ^ b);   // a ^ b = 00011010
	printf("%x \n", ~a);      // ~a = 1....1 01010000
	printf("%x \n", a << 2);  // a << 2 = 1010111100
	printf("%x \n", b >> 3);  // b >> 3 = 00010110

	return 0; */

	/*
	int a = 2147483647;
	printf("a : %d \n", a);

	a++;
	printf("a : %d \n", a);
	*/

	/*
	char a;
	a = 'a';
	printf("a의 값과 문자. 값 : %d, 문자 : %c \n", a, a);
	return 0;
	*/

	/*
		double celsius;

	printf("섭씨 온도를 화씨 온도로 바꾼다. \n");
	printf("섭씨 온도 입력 \n");
	scanf_s("%lf", &celsius);

	printf("섭씨 %f 도는 화씨로 %f 도 이다. \n", celsius, 9 * celsius / 5 + 32);

	*/

	/*

	char ch;

	short sh;
	int i;
	long lo;

	float fl;
	double du;

	printf("char형 변수 입력 : ");
	scanf("%c", &ch);

	printf("short형 변수 입력 : ");
	scanf("%hd", &sh);
	printf("int형 변수 입력 : ");
	scanf("%d", &i);
	printf("long형 변수 입력 : ");
	scanf("%ld", &lo);

	printf("float형 변수 입력 :");
	scanf("%f", &fl);
	printf("double형 변수 입력");
	scanf("%lf", &du);

	printf("char : %c, short : %d, int : %d, ", ch, sh, i);
	printf("long : %ld, float : %f, double : %f \n", lo, fl, du);

	return 0;
	*/

	/*
	int money;
	float money_USA = 1105.54;


	printf("얼마나 환전하시겠습니까?");
	scanf("%d", &money);

	printf("%d원을 환전한 금액은 %.2f 달러입니다.", money, money / money_USA);

	return 0;
	*/

	// 조건문

	/*
	double i, j;
	printf("입력한 숫자 : ");
	scanf("%lf %lf", &i, &j);

	if (j == 0) {
		printf("0으로는 나눌 수 없다.");

		return 0;
	}

	printf("%lf 를 %lf 로 나눈 값. : %lf", i, j, i / j);

		return 0;
	*/

	/*

	int num;

	printf("숫자를 입력");
	scanf("%d", &num);

	if (num == 7) {
		printf("행운의 7!");
	}
	else {
		if (num == 1) {
			printf("첫번째 숫자군요.");
		}
		else {
			printf("입력한 숫자는 %d", num);
		}
	}
	return 0;
	*/

	/*

	int a;
	printf("아무 숫자 입력 : ");
	scanf("%d", &a);

	if (a >= 10) {

		printf("%d는 10보다 큰 수다. \n", a);

		if (a < 20) {
			printf("%d 는 10 이상, 20 미만의 수다. \n", a);
		}
	}
	else {
		printf("%d는 10보다 작은 수다. \n", a);
	}

	if (a >= 10 && a < 20) {
		printf(" %d는 10 이상, 20 미만의 수다.", a);
	}

	return 0;
	*/

	// 반복문

	/*
		int i;
	for (i = 0; i <= 20; i++) {
		printf("숫자 : %d \n", i);
	}
	return 0;
	*/


	/*

	int i;
	int subject, score;
	double sum_score = 0;

	printf("과목 개수 : ");
	scanf("%d", &subject);

	printf("\n 각 과목의 점수 \n");
	for (i = 1; i <=subject; i++) {
		printf("과목 %d : ", i);
		scanf("%d", &score);
		sum_score += score;
	}
	printf(" 평균 : %.2f \n", sum_score / subject);
	return 0;

	*/

	/*

	int usr_answer;

	printf("숫자 추측");
	for (;;) {
		scanf("%d", &usr_answer);
		if (usr_answer == 3) {
			printf("정답!");
			break;
		} else {
			printf("오답...");
		}
	}
	int i;

	for (i = 0; i < 100; i++) {

		if (i % 5 == 0) continue;

		if (i == 99) break;

		printf("%d ", i);
	}

	return 0;

	*/

	// 문제 7 - 소인수 분해
	/*
	int n, i = 2, div_n;

	scanf("%d", &n);
	div_n = n;

	printf("N = %d \n", n);
	printf("%d = ", n);

	while (div_n >= i) {
		if (div_n % i == 0) {
			printf("%d ", i);
			div_n /= i;
			i = 2;

			if (div_n >= i) printf("* ");
		}

		else i++;

	}
	return 0;
	*/

	/*
	int arr[100]; // 소수를 저장할 배열
	int guess = 4; // for문에서 돌릴 숫자
	int i;
	int max = 0;
	int check = 1;
	arr[0] = 2;

	while (arr[99] < 0) {

		if (guess % 2 == 1)
		{
			for (i = max; i > -1; i--)
			{
				if (guess % arr[i] == 0) check = 0;
			}

			if (check == 1)
			{
				printf("%d는 소수입니다. ", guess);
				printf("%d번째 소수로 등록합니다. \n", max+2);
				arr[max + 1] = guess;
				max++;
			}

		}

		check = 1;
		guess++;
	}


	return 0;
	*/



	/*

	int total = 5;
	int arr[4];
	int temp;
	int i, j, ave = 0;
	int grape;

	for (i = 0; i < total; i++) {
		printf("\n %d 번째 학생의 성적은? ", i + 1);
		scanf("%d", &arr[i]);
	}
	for (i = 0; i < total; i++) {
		ave = ave + arr[i];
	}

	ave = ave / total;
	printf("전체 학생의 평균은 : %d \n", ave);

	for (i = 0; i < total; i++) {
		printf("\n %d번 학생 : %d 점 | ", i + 1, arr[i]);
		grape = arr[i] / 4;
		for (j = 0; j < grape; j++) printf("ㅁ");
	}
	printf("\n 커트라인 : %d 점 | ", ave);
	grape = ave / 4;
	for (i = 0; i < grape; i++) printf("ㅁ");


	for (i = 0; i < total; i++) {
		printf("\n 학생 %d : ", i + 1);
		if (arr[i] >= ave)
			printf("합격 \n");
		else
			printf("불합격 \n");
	}


	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			if (arr[i] > arr[j]) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

	for (i = 0; i < 5; i++) printf("%d등 : %d 점 \n", i + 1, arr[i]);



	return 0;


	*/

	/*
	int score[3][2];
	int i, j;

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 2; j++) {
			if (j == 0) {
				printf("%d 번째 학생의 국어 점수 : ", i + 1);
				scanf("%d", &score[i][j]);
			}
			else {
				printf("%d 번째 학생의 수학 점수 : ", i + 1);
				scanf("%d", &score[i][j]);
			}
		}
	}


	for (i = 0; i < 3; i++) {
		printf("%d 번째 학생의 국어 점수 : %d, 수학 점수 : %d \n", i + 1, score[i][0], score[i][1]);
	}

	return 0;

	*/

	/*

	int arr1[][3] = { {4, 5, 6}, {7, 8, 9} }; // 가능
	int arr2[][2] = { {1, 2}, {3, 4}, {5, 6}, {7} }; // 가능
	int arr3[2][] = { {4, 5, 6}, {7, 8, 9} }; // 불가능

	*/

	/*
	int arr[10] = { 1, 2,3,4,5,6,7,8,9,10 };
	int* parr;
	int i;
	parr = &arr[0];


	for (int i = 0; i < 10; i++) {
		printf("arr[%d]의 주소값 : %p ", i, &arr[i]);
		printf("(parr + %d )의 값 : %p ", i, (parr + i));

		if (&arr[i] == (parr + i)) {
			printf(" --> 일치 \n");
		}
		else printf(" --> 불일치 \n");

	}


	return 0;
	*/

	/*

	int arr[3][3] = { 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int* rarr[3];

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf("arr[%p][%p]의 주소는 %p \n", &arr[i], &arr[j], &arr[i][j]);
		}
	}
	for (int i = 0; i < 3; i++) {
		printf("rarr[%d] : %p \n", i, rarr[i]);
	}


	return 0;

	*/

	/*

	int arrs[3][3] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int* rarr[3];

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf("arr[%p][%p]의 주소는 %p \n", &arrs[i], &arrs[j], &arrs[i][j]);
		}
	}
	for (int i = 0; i < 3; i++) {
		printf("rarr[%d] : %p \n", i, rarr[i]);
	}


	int arr[3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 };

	printf(" (arr+0) = %p \n", (arr + 0));
	printf("*(arr+0) = %p \n", *(arr + 0));
	printf("*(*(arr + 0) + 0) = %d \n", *(*(arr + 0) + 0));
	printf("*(arr+1) = %p \n", *(arr + 1));
	printf("*(*(arr + 1) + 0) = %d \n", *(*(arr + 1) + 0));
	printf("*(arr+2) = %p \n", *(arr + 2));
	printf("*(*(arr + 2) + 0) = %d \n", *(*(arr + 2) + 0));

	return 0;

	*/

	/*


	int arr[3] = { 1, 2, 3 };
	int* parr;

	parr = arr; // parr = &arr[0];

	printf("arr[1] : %d \n", arr[1]);
	printf("parr[1] : %d \n", parr[1]);
	printf("%p \n", parr);
	printf("%p \n", parr);

	return 0;


	*/


	/*

	int arr[10] = { 100, 98, 97, 95, 89, 76, 92, 96, 100, 99 };

	int* parr = arr;
	int sum = 0;

	while (parr - arr <= 9) {
		printf("%d\n", *parr);
		printf("%p\n", arr);
		sum += (*parr);
		parr++;
	}

	printf("내 시험 점수 평균 : %d \n", sum / 10);
	return 0;



	/*

	int a;
	int* pa;
	int** ppa;

	pa = &a;
	ppa = &pa;

	a = 3;

	printf("a : %d // *pa : %d // **ppa : %d \n", a, *pa, **ppa);
	printf("&a : %p // pa : %p // *ppa : %p \n", &a, pa, *ppa);
	printf("&pa : %p // ppa : %p \n", &pa, ppa);

	return 0;
	*/


	/*

	int arr[3] = { 1, 2, 3 };
	int(*parr)[3] = &arr;
	int pa = &arr;

	printf("arr[1] : %d \n", arr[1]);
	printf("parr[1] : %d \n", (*parr)[1]); // *(parr + 1)
	printf("%p", pa);

	return 0;

	*/
	/*
	int arr[2][3] = { {1, 2, 3}, {4, 5, 6} };
	int(*parr)[3];  // 괄호를 꼭 붙이세요

	parr = arr;  // parr 이 arr 을 가리키게 한다.

	printf("parr[1][2] : %d , arr[1][2] : %d \n", parr[1][2], arr[1][2]);

	return 0;

	/* (배열의 형) */ /* (포인터 이름) *//* 2 차원 배열의 열 개수 */
	// 예를 들어서
	/*
	int(*parr)[3];
	*/


	// `arr == &arr[0]`
	// `*arr == arr[0]`
	// ptr + 1 == ptr + sizeof(*ptr)

	/*

	int arr[2][3] = { {1,2,3}, {4,5,6} };

	int(*ptr)[3] = &arr[0]; // 원소를 3개 가지는 1차원 배열을 가리키는 포인터
							// arr의 첫번째 행 전체를 가리키는 포인터
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d", ptr[i][j]);
		}
		printf("\n");
	}

	return 0;

	*/

	/*
	int arr[2][3] = { {1,2,3}, {4,5,6}};
	for (int(*row)[3] = arr; row < arr + 2; row++)
	{
		for (int* col = *row; col < *row + 3; col++)
		{
			printf("%d \n", *col);
			printf("%p \n", col);
			printf("%d \n", *row[0]);
			printf("%p \n", row[0]);
		}
		printf("\n");
	}
	return 0;
	*/

	/*

		int arr[2][3] = { {1, 2, 3}, {4, 5, 6} };
	int* pa;
	int(*par)[3];

	pa = &par;
	par = arr;


	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{

				printf("%d \n", *(*(par+i)+j));
		}
	}

	return 0;
	*/



