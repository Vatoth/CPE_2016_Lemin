/*
** my_strcat.c for my_strcat in /home/lblanchard/CPool_Day07
** 
** Made by Leandre Blanchard
** Login   <lblanchard@epitech.net>
** 
** Started on  Tue Oct 11 09:27:45 2016 Leandre Blanchard
** Last update Sun Apr 30 17:22:22 2017 Léandre Blanchard
*/

#include "my.h"

char	*my_strcat(char *dest, const char *src)
{
  char	*ret;

  if (dest == NULL || src == NULL)
    return (NULL);
  ret = dest;
  while (*dest)
    dest++;
  while (*dest++ = *src++);
  return (ret);
}
