/*
** my_put_pointers.c for my_put_pointers in /home/Vatoth/PSU_2016_my_printf
**
** Made by Quentin Sonnefraud
** Login   <Vatoth@epitech.net>
**
** Started on  Tue Nov 15 15:06:23 2016 Quentin Sonnefraud
** Last update Thu Mar 23 17:11:23 2017 Quentin Sonnefraud
*/

#include "my.h"

static long	my_base_pointers(long nb, const char *base)
{
  long		result;
  long		modulo;

  if (nb < 0)
    {
      my_putchar('-');
      nb = -nb;
    }
  result = nb / my_strlen(base);
  modulo = nb % my_strlen(base);
  if (result > 0)
    my_base_pointers(result, base);
  my_putchar(base[modulo]);
  return (0);
}

void     my_put_pointers(va_list ap, const char flag)
{
  (void) flag;
  my_putstr("0x");
  my_base_pointers(va_arg(ap, long), "0123456789abdcef");
}
