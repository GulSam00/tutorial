#include <unistd.h>

int main(void)
{
	int i = '0';
	i = 32;
	int arr[4] = {48, 49, 50, 51};
	write(1, &i, 4);
	write(1, arr, 16);
	write(1, arr, 14);
	write(1, arr, 11);
}
