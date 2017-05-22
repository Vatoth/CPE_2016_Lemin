/*
** clear.c for clear in /home/leandre/Rushs/scroller
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Sun Apr  2 22:15:29 2017 Léandre Blanchard
** Last update Sun Apr  2 22:17:39 2017 Léandre Blanchard
*/

#include "my.h"

void		my_clear()
{
  int		i;
  int		size;

  i = 0;
  size = term_width();
  while (i != size)
    {
      my_printf(" ");
      i++;
    }
  my_printf("\r");
}
