/*
** my_strdup.c for my_strdup in /home/lblanchard/CPool_Day08
** 
** Made by Leandre Blanchard
** Login   <lblanchard@epitech.net>
** 
** Started on  Wed Oct 12 09:15:56 2016 Leandre Blanchard
** Last update Thu Apr 27 21:30:16 2017 Léandre Blanchard
*/

#include <stdlib.h>

#include "my.h"

char	*my_strdup(const char *src)
{
  char	*dest;

  if (src == NULL)
    return (NULL);
  if ((dest = malloc(sizeof(char) * (my_strlen(src) + 10))) == NULL)
    return (NULL);
  my_strcpy(dest, src);
  return (dest);
}
