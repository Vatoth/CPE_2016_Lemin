/*
** my_calloc.c for calloc in /home/leandre/Rushs/scroller
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Sun Apr  2 21:33:39 2017 Léandre Blanchard
** Last update Sun Apr  2 21:34:44 2017 Léandre Blanchard
*/

#include "my.h"

char		*my_calloc(int size)
{
  char		*s;

  if ((s = malloc(size)) == NULL)
    return (NULL);
  zeros(s, size);
  return (s);
}
