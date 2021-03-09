#include <string.h>
#include <stdio.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t dst_len;
	size_t result;
	int i;
	int j;

	dst_len = strlen(dst);
	result = strlen(src);
	i = 0;
	j = dst_len;
	while ((src[i] != '\0') && i < (int)(size - dst_len - 1))
	{
			dst[j] = src[i];
			i++;
			j++;
		}
	dst[j] = '\0';
	if (size < dst_len)
		result += size;
	else
		result += dst_len;
	return (result);
}

int main(void)
{
char arr1[] = "123456";
char arr2[] = "qwerty";
unsigned int n = ft_strlcat(arr1,arr2, 9);
printf ("%s\n%s\n%d", arr1,arr2, n);
}
