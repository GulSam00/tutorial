#include <stdio.h>

char *return_char(char* ar1, char* ar2)
{
	
	char temp;
	while (*ar1 && *ar2)
	{
		printf("going to change %c and %c\n", *ar1,*ar2);
		temp = *ar1;
		*ar1 = *ar2;
		*ar2 = temp;
		printf("has changed %c and %c\n", *(ar1++),*(ar2++));
		printf ("left string : \nar1 : %s\nar2 : %s\n", ar1,ar2);
	}
	return (ar1);
}

int main()
{
	char ar1[]="1234";
	char ar2[]="gas man";
	char *p;
	p = return_char(ar1, ar2);
	printf ("left string from *ar1 pointer : %s\n", p);
	// there is nothing to print, because already pointer p pointing "NULL" of ar1, that is pointer p pointing ar2[4](NULL), now are ar1[4](NULL)
	// p -= 4;
	p = ar1;
	printf ("whole ar1 from start : %s\n", p);
	printf ("\n%s\n%s", ar1,ar2);
}
