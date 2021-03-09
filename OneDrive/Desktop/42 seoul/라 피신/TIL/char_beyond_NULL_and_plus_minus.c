#include <stdio.h>

int main()
{
	char arr[]="123456789";
	char *p = arr;
	arr[4] = '\0';
	printf ("there is NULL in arr[4] : %s\n",arr);
	while(*p)
	{
		printf ("%c", *(p++));
	}
	printf ("\n");
	printf ("%c", *++p);
	printf ("%c", ++*p);
	printf ("\n");
	for (int i =0; i<10; i++)
	{
		printf ("%c",arr[i]);
	}
}
