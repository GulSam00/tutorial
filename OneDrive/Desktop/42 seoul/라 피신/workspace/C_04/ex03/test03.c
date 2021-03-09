/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 12:01:00 by marvin            #+#    #+#             */
/*   Updated: 2021/03/01 12:01:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>  // C++ 에서는 <cctype>
#include <stdio.h>
#include <stdlib.h>

int ato(char s[]) {
  int i, n, sign;
  for (i = 0; isspace(s[i]); i++)
    ; /* skip white space */
  sign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '+' || s[i] == '-') /* skip sign */
    i++;
  for (n = 0; isdigit(s[i]); i++) n = 10 * n + (s[i] - '0');
  return sign * n;
}
/*
int main() {
  int i;
  char szInput[256];
  printf("Enter a number: ");
  fgets(szInput, 256, stdin);
  i = ato(szInput);
  printf("The value entered is %d. The double is %d.\n", i, i * 2);
  return 0;
}
*/