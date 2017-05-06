/*
** my_putchar.c for my_putchar in /home/Vatoth/CPool_Day07
** 
** Made by Quentin Sonnefraud
** Login   <Vatoth@epitech.net>
** 
** Started on  Wed Oct 12 08:01:01 2016 Quentin Sonnefraud
** Last update Thu Mar 23 17:26:11 2017 Quentin Sonnefraud
*/

#include "my.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void    my_putchar_pointer(va_list ap, const char flag)
{
  (void) flag;
  my_putchar(va_arg(ap, int));
}

