
/*
#include <stdio.h>
#include <stdlib.h>

int     main(void)
{
    char *pc;
    int i = 0;
    pc = (char *)malloc(sizeof(char)*50);
    for (i = 0; i < 26; i++)
    {
        pc[i] = 'a' + i;
    }
    pc[i] = 0;
    printf ("%s\n",pc);
    free(pc);
}
*/
/*
#include <stdio.h>
#include <stdlib.h>

int     main(void)
{
    int *pi, i;
    pi = (int*)malloc(5 * sizeof(int));
    if (pi == NULL)
    {
        printf ("동적 메모리 할당에 실패 \n");
        exit(1);
    }
    pi[0] = 100;
    pi[1] = 200;
    pi[2] = 300;
    pi[3] = 400;
    pi[4] = 500;
    for (i = 0; i < 5; i++)
    {
        printf("%d\n", pi[i]);
    }
        for (i = 0; i < 5; i++)
    {
        printf("%d\n", *(pi+i));
    }
    free(pi);
}
*/
/*
#include <stdio.h>
#include <stdlib.h>

struct BOOK
{
    int number;
    char title[100];
};

void showBook(struct Book *p, int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        printf("번호 %d : %s\n", (p+i)->number, (p+1)->title);
    }
}
int     main(void)
{
    struct Book *p;
    p = (struct Book *)malloc(2 * sizeof(struct Book));
    if (p == NULL)
    {
        printf("동적 메모리 할당 실패 \n");
        exit(1);
    }
    p->number = 1;
    strcpy(p->title, "C Programming");

    (p + 1)->number = 2;
    strcpy((p + 1)->title, "C Data");
    showbook(p, 2);
    
}
*/
#include <stdio.h>
#include <stdlib.h>

int     print_array(int **array)
{
    int i, j;
    printf ("pointer array by argument in function\n");
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 6; j++)
        {
            printf ("value : %d address : %p\n", *array[i], array[i]);
            array[i]++;
        }
    }
}

int     main(void)
{
    int i,j;
    int **pptr = (int **)malloc(sizeof(int*) * 8);
    int **array;
    for (i = 0; i < 8; i++)
    {
        printf ("%p\n", pptr[i]);
        *(pptr + i) = (int *)malloc(sizeof(int) * 6);
    }
    /*
    printf ("before input\n");
    for (i = 0; i < 8; i++)
    {
            printf ("%p\n",pptr[i]);
        for (j = 0; j < 6; j++)
        {
            printf ("%p\n",pptr[i][j]);
        }
    }
    */
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 6; j++)
        {
            pptr[i][j] = i * 6 + j;
        }
    }
    array = pptr;
    printf ("after input - wrong\n");
    for (i = 0; i < 8; i++)
    {
            printf ("%p\n",pptr[i]);
        for (j = 0; j < 6; j++)
        {
			printf ("value : %d address : %p\n", pptr[i][j], pptr[i][j]);
        }
        // %p - pptr[i][j] -> just print value of pptr[i][j] by pointer form.
    }
    printf ("after input - correct\n");
    for (i = 0; i < 8; i++)
    {
            printf ("%p\n",pptr[i]);
        for (j = 0; j < 6; j++)
        {
            printf ("value : %d address : %p\n", pptr[i][j], &pptr[i][j]);
            // why increcsing pointer 12?
        }
    }
        for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 6; j++)
        {
            printf ("%3d",*(*(pptr + i)+j));
        }
        printf("\n");
    }
    
    print_array(pptr);

   printf ("this is not [][]array\n");
        for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 6; j++)
        {
            printf ("%d\n",*pptr);
            pptr++;
        }
    }

    for (i = 0; i <8; i++)
    {
        free(*(pptr + i));
    }
    return 0;

}