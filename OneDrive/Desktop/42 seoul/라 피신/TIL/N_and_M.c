/*

int N = 4;
int M = 3;
int arr[10];
int isused[10];


void func(int k)
{
    printf ("==current k : %d ==\n", k);
    for (int i = 0; i < M; i++)
        {
            printf ("%d", arr[i]);
        }
    printf ("\n");
    if (k == M)
    {
        printf ("success!\n");
        for (int i = 0; i < M; i++)
        {
            printf ("%d", arr[i]);
        }
        printf ("\n");
        return ;

    }
    int i;
    i = 1;
    while (i <= N)
    {
        if (!isused[i])
        {
            arr[k] = i;
            isused[i] = 1;
            printf ("<<currne i = %d>>\n", i);
            func(k+1);
            printf ("**return isused[%d] to 0 | k = %d**\n", i, k);
            isused[i] = 0;
        }
        i++;
    }
}

int     main(void)
{
    func(0);
}
*/

/*

#include <stdio.h>

int arr[10];
int isused[10];
int N = 7;
int M = 3;

void    func(int k)
{
    int i;
    if (k == M + 1)
    {
        for (int j = 1; j <= M; j++)
        {
            printf ("%d", arr[j]);
        }
        printf ("\n");
        return ;
    }
    i = 0;
    while (i <= N)
    {
        if (!isused[i] && arr[k - 1] < i)
        {
            arr[k] = i;
            isused[i] = 1;
            func(k+1);
            isused[i] = 0;
        }
        i++;
    }
}

int main(void)
{
    func(1);
}
*/
/*

#include <stdio.h>
int arr[10];
int isused[10];
int N = 3;
int M = 3;

void     func(int k)
{
    int i;

    if (k == M)
    {
        int j;

        j = 0;
        while (j < M)
        {
            printf ("%d", arr[j]);
            j++;
        }
        printf ("\n");
        return ;
    }
    i = 1;
    while (i <= N)
    {
        arr[k] = i;
        func(k + 1);
        arr[k] = 0;
        i++;
    }
}

int main(void)
{
    func(0);
}
*/

#include <stdio.h>

int arr[10];
int N = 3;
int M = 3;

int     check(int k, int i)
{
    int j = 0;
    printf ("k : %d, i = %d\n", k, i);
    while (j < M)
    {   
        if (arr[j])
            if (i < arr[j])
            {
                printf ("j : %d\n", j);
                printf ("%d < %d\n", i, arr[j]);                
                return (0);
            }

        j++;
    }
    return (1);
}

void    func(int k)
{
    int i;
    
    i = 1;
    if (k == M)
    {
        for (int j = 0; j < M; j++)
            printf ("%d", arr[j]);
        printf ("\n");
        return ;
    }
    while (i <= N)
    {
        if (check(k, i))
        {
            arr[k] = i;
            func(k + 1);
            arr[k] = 0;
        }
        i++;
    }
}

int     main(void)
{
    func(0);
}