/*
** my.h for my.h in /home/Vatoth/PSU_2016_my_printf/include
** 
** Made by Quentin Sonnefraud
** Login   <Vatoth@epitech.net>
** 
** Started on  Wed Nov  9 10:40:56 2016 Quentin Sonnefraud
** Last update Thu Mar 23 17:26:38 2017 Quentin Sonnefraud
*/

#ifndef MY_H_
# define MY_H_

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

int	my_put_nbr(int nb);
void	my_putstr(const char *s);
int     my_base(int nb, const char *base);
int	my_strlen(const char *s);
void	my_putchar(char c);
int	my_printf(const char *flag, ...);
void    my_put_nbr_pointer(va_list ap, const char flag);
void	my_put_pointers(va_list ap, const char flag);
void    my_put_unsigned_pointer(va_list ap, const char flag);
void	my_putchar_pointer(va_list ap, const char flag);
void    my_put_long_pointer(va_list ap, const char flag);
void    my_putstr_pointer(va_list ap, const char flag);
void    my_base_pointer(va_list ap, const char flag);
void    my_printable_pointer(va_list ap, const char flag);

#endif /* !MY_H_ */
