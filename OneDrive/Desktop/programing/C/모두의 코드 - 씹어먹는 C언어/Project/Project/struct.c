
/*

#include <stdio.h>

struct  Human {
	int age;
	int height;
	int weight;
};

int main()
{
	struct  Human Psi;
		Psi.age = 99;
		Psi.height = 100;
		Psi.weight = 80;
		printf("정보 \n");
		printf("나이 : %4d \n", Psi.age);
		printf("키 : %4d \n", Psi.height);
		printf("몸무게 : %4d\n", Psi.weight);
		return 0;
}


*/

/*

// 구조체 예제 2 
#include <stdio.h>
char copy_str(char* dest, const char* src);
struct Books {
	/* 책 이름 
	char name[30];
	/* 저자 이름 
	char auth[30];
	/* 출판사 이름 
	char publ[30];
	/* 빌려 졌나요? 
	int borrowed;
};
int main() {
	struct Books Harry_Potter;

	copy_str(Harry_Potter.name, "Harry Potter");
	copy_str(Harry_Potter.auth, "J.K. Rolling");
	copy_str(Harry_Potter.publ, "Scholastic");
	Harry_Potter.borrowed = 0;

	printf("책 이름 : %s \n", Harry_Potter.name);
	printf("저자 이름 : %s \n", Harry_Potter.auth);
	printf("출판사 이름 : %s \n", Harry_Potter.publ);

	return 0;
}
char copy_str(char* dest, const char* src) {
	while (*src) {
		*dest = *src;
		src++;
		dest++;
	}

	*dest = '\0';

	return 1;
}
*/

/* 포인터 갖고 놀기 
/* 헷갈림 
#include <stdio.h>
struct TEST {
  int c;
  int *pointer;
};
int main() {
  struct TEST t;
  struct TEST *pt = &t;
  int i = 0;

  /* t 의 멤버 pointer 는 i 를 가리키게 된다
  t.pointer = &i;

  /* t 의 멤버 pointer 가 가리키는 변수의 값을 3 으로 만든다
  *t.pointer = 3;


  printf("i : %d \n", i);

  /*

  -> 가 * 보다 우선순위가 높으므로 먼저 해석하게 된다.
  즉,
  (pt 가 가리키는 구조체 변수의 pointer 멤버) 가 가리키는 변수의 값을 4 로
  바꾼다. 라는 뜻이다/

 
  *pt->pointer = 4;
  printf("i : %d \n", i);

  pt->c = 5;
  printf("i : %d \n", i);

  return 0;
}
*/

/*
#include <stdio.h>
char copy_str(char* dest, char* src);
struct TEST {
	int i;
	char str[20];
	int b;
};

int main() {
	struct TEST a, b;

	b.i = 3;
	copy_str(b.str, "hello, world");

	a = b;

	printf("a.str : %s \n", a.str);
	printf("a.i : %d \n", a.i);

	return 0;
}
char copy_str(char* dest, char* src) {
	while (*src) {
		printf("%c \n", *src);
		printf("%p \n", src);
		printf("%p \n", dest);
		*dest = *src;
		src++;
		dest++;
	}

	*dest = '\0';

	return 1;
}

*/
/*구조체를 인자로 전달하기 */

/*

#include <stdio.h>
struct TEST {
	int age;
	int gender;
	char name[20];
};
int set_human(struct TEST *a, int old, int sex, const char *name);
char copy_str(char* dest, const char* src);
int main() {
	struct TEST human;
	struct TEST* pt = &human;

	set_human(pt, 10, 1, "Lee");
	printf("AGE : %d // Gender : %d // Name : %s \n", pt->age, pt->gender, pt->name);
	return 0;
}
int set_human(struct TEST *a, int old, int sex, const char *name) {
	a->age = old;
	a->gender = sex;
	copy_str(a->name, name);
	
	return 0;
}

char copy_str(char* dest, const char* src)
{
	while (*src) {
		*dest = *src;
		src++;
		dest++;
	}

	*dest = '\0';

	return 1;

}
*/

/*

#include <stdio.h>

int print_num(int *num);

struct BigNum {
	int i_digit[100];   // 정수 부분
	int d_digit[100];   // 소수 부분
	int i_total_digit;  // 전체 사용되고 있는 정수부분 자리수
	int d_total_digit;  // 전체 사용되고 있는 소수부분 자리수
	char sign;  // 부호, 0 이면 양수, 1 이면 음수. 0 은 양수로 간주한다.
};

int main_str()
{
	struct BigNum num1;
	struct BigNum num2;
	printf("1 정수 입력 :");
	scanf("%s", num1.i_digit);
	printf("1 소수 입력 :");
	scanf("%s", num1.d_digit);

	/*
	printf("2 정수 입력 :");
	scanf("%s", num2.i_digit);
	printf("2 소수 입력 :");
	scanf("%s", num2.d_digit);
	

	print_num(num1.i_digit);

	return 0;
}

int print_num(int* num)
{
	while (*num)
	{
		printf("%d", *num);
		num++;
	}
	
}/* 공용체 
#include <stdio.h>
union A {
	int i;
	char j;
};
int main() {
	union A a;
	a.i = 0x12345678;
	printf("%x", a.j);
	return 0;
}

*/

/* 열거형의 도입 
#include <stdio.h>
enum { RED, BLUE, WHITE, BLACK };
int main_struct() {
	int palette = RED;
	switch (palette) {
	case RED:
		printf("palette : RED \n");
		break;
	case BLUE:
		printf("palette : BLUE \n");
		break;

	case WHITE:
		printf("palette : WHITE \n");
		break;
	case BLACK:
		printf("palette : BLACK \n");
		break;
	}
}
*/