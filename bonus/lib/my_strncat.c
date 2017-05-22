/*
** my_strncat.c for my_strncat in /home/lblanchard/CPool_Day07
** 
** Made by Leandre Blanchard
** Login   <lblanchard@epitech.net>
** 
** Started on  Tue Oct 11 11:09:15 2016 Leandre Blanchard
** Last update Sun Apr 30 17:22:35 2017 Léandre Blanchard
*/

#include "my.h"

char	*my_strncat(char *dest, const char *src, int nb)
{
  int	i;

  i = 0;
  while (src[i] != '\0' && nb > 0)
    {
      dest[my_strlen(dest) + i] = src[i];
      i = i + 1;
      nb = nb - 1;
    }
  dest[my_strlen(dest) + 1] = '\0';
  return dest;
}
