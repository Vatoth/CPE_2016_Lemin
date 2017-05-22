/*
** my_revstr.c for my_revstr in /home/lblanchard/CPool_Day06
**
** Made by Leandre Blanchard
** Login   <lblanchard@epitech.eu
**
** Started on  Fri Oct  7 11:01:26 2016 Leandre Blanchard
** Last update Sun Apr 30 17:21:06 2017 Léandre Blanchard
*/

#include "my.h"

char	*my_revstr(char *str)
{
  int	i;
  char	c;

  i = 0;
  if (str == NULL)
    return (NULL);
  while (i < my_strlen(str) / 2)
    {
      c = *(str + i);
      *(str + i) = *(str + my_strlen(str) - i - 1);
      *(str + my_strlen(str) - i - 1) = c;
      i = i + 1;
    }
  return (str);
}
