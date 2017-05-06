/*
** my_put_long.c for my_put_long.c in /home/Vatoth/PSU_2016_my_printf
** 
** Made by Quentin Sonnefraud
** Login   <Vatoth@epitech.net>
** 
** Started on  Wed Nov  9 11:43:59 2016 Quentin Sonnefraud
** Last update Thu Mar 23 16:59:50 2017 Quentin Sonnefraud
*/

#include "my.h"

static long	my_put_long(long nb)
{
  long		modulo;

  if (nb < 0)
    {
      my_putchar('-');
      nb = nb * -1;
    }
  if (nb > 0)
    {
      if (nb > 9)
	{
	  modulo = nb % 10;
	  nb = (nb - modulo) / 10;
	  my_put_long(nb);
	  my_putchar(48 + modulo);
	}
      else
	my_putchar(nb + 48);
    }
  return (0);
}

void	my_put_long_pointer(va_list ap, char flag)
{
  (void) flag;
  my_put_long(va_arg(ap, long));
}
