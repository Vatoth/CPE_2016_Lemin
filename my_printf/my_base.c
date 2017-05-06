/*
** my_base.c for my_base.c in /home/Vatoth/PSU_2016_my_printf
** 
** Made by Quentin Sonnefraud
** Login   <Vatoth@epitech.net>
** 
** Started on  Tue Nov 15 12:08:39 2016 Quentin Sonnefraud
** Last update Mon May  1 01:13:49 2017 Antoine
*/

#include "my.h"

int	my_base(int nb, const char *base)
{
  int	result;
  int	modulo;

  if (nb < 0)
    {
      my_putchar('-');
      nb = nb * -1;
    }
  result = nb / my_strlen(base);
  modulo = nb % my_strlen(base);
  if (result > 0)
    my_base(result, base);
  my_putchar(base[modulo]);
  return (0);
}

void	my_base_pointer(va_list ap, char flag)
{
  if ('x' == flag)
    my_base(va_arg(ap, int), "0123456789abcdef");
  else if ('o' == flag)
    my_base(va_arg(ap, int), "01234567");
  else
    my_base(va_arg(ap, int), "01");
}
