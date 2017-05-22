/*
** my_tablen.c for tablen in /home/leandre
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Fri Feb 24 16:24:34 2017 Léandre Blanchard
** Last update Mon Apr 10 01:16:48 2017 Léandre Blanchard
*/

#include "my.h"

int		my_tablen(char **tab)
{
  int		i;

  i = 0;
  if (tab == NULL)
    return (0);
  while (tab[i] != NULL)
    i++;
  return (i);
}
