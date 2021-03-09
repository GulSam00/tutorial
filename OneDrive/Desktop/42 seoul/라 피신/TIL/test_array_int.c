#include <stdio.h>
#include <unistd.h>
// if write int array dont enough byte?

int main(void)
{
	int arr[]={122, 121, 120, 119};
	write(1, arr, 4);
	printf ("\n");
	write(1, arr, 3);
	printf ("\n");
	write(1, arr, 2);
	printf ("\n");
	write(1, arr, 1);
	printf ("\n");
	write(1, arr,16);
}
// result : print integer number (bigger than 9) is impossible. because write function only could print string data(not integer data) by ascII code. actually they trans ascII code to something that human can get it.
