#include <stdio.h>  /* printf, scanf, NULL */
#include <stdlib.h> /* malloc, free*/

/* 
int main() {
  int i, n;
  int* buffer;

  printf("How long do you want the string? ");
  scanf("%d", &i);

  buffer = (int*)malloc(i);
  if (buffer == NULL) exit(1);

  for (n = 0; n < i; n++) 
  {
        buffer[n] = rand() % 100;
        printf("Random string: %d\n", buffer[n]);
  }
  
  free(buffer);

  return 0;
}
*/

/*
int main(int argc, char **argv)
{
    int student;
    int i, input;
    int *score;
    int sum = 0;

    printf ("how many student? :");
    scanf ("%d", &student);

    score = (int *)malloc(student * sizeof(int));

    for (i = 0; i < student; i++)
    {
        printf ("student %d's score : ", i);
        scanf ("%d", &input);
    
        score[i] = input;
    }

    for (i = 0; i < student; i++)
    {
        sum += score[i];
    }

    printf ("sum score : %d\n", sum / student);
    free(score);
    return 0;
}
*/

/*
#include <stdio.h>
#include <stdlib.h>

int main() {
  int width, height;
  printf("배열 행 크기 : ");
  scanf("%d", &width);
  printf("배열 열 크기 : ");
  scanf("%d", &height);

  int(*arr)[width] = (int(*)[width])malloc(height * width * sizeof(int));
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      int data;
      scanf("%d", &data);
      arr[i][j] = data;
    }
  }
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }

  free(arr);
}
*/