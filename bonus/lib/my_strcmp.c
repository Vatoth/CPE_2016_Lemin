/*
** my_strcmp.c for my_strcmp in /home/lblanchard/CPool_Day06
**
** Made by Leandre Blanchard
** Login   <lblanchard@epitech.net>
**
** Started on  Thu Oct  6 11:19:22 2016 Leandre Blanchard
** Last update Mon Apr 10 00:59:06 2017 Léandre Blanchard
*/

#include <stdlib.h>

int	my_strcmp(char *s_1, char *s_2)
{
  int   i;

  i = 0;
  if (s_1 == NULL || s_2 == NULL)
    return (0);
  while (s_1[i] == s_2[i] && s_1[i] != '\0' && s_2[i] != '\0')
    i = i + 1;
  return (s_1[i] - s_2[i]);
}

