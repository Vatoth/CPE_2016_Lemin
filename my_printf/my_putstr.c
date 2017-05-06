/*
** my_putstr.c for my_putstr in /home/Vatoth/CPool_Day04
** 
** Made by Quentin Sonnefraud
** Login   <Vatoth@epitech.net>
** 
** Started on  Thu Oct  6 16:03:08 2016 Quentin Sonnefraud
** Last update Thu Mar 23 17:00:35 2017 Quentin Sonnefraud
*/

#include "my.h"

void	my_putstr(const char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      my_putchar(str[i]);
      i++;
    }
}

void    my_putstr_pointer(va_list ap, char flag)
{
  (void) flag;
  my_putstr(va_arg(ap, char *));
}
