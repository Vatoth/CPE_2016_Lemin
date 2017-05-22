/*
** my_put_binary.c for my_printf in /home/leandre
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Wed Apr  5 12:37:13 2017 Léandre Blanchard
** Last update Sun Apr 30 17:10:47 2017 Léandre Blanchard
*/

#include "my.h"

void		my_put_binary(long long nb)
{
  int		i;

  i = 0;
  while (i < sizeof(long long) * 8)
    {
      if (nb & 1)
	my_putchar('1');
      else
	my_putchar('0');
      nb >> 1;
      i++;
    }
}
