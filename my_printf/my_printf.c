/*
** my_printf.c for my_printf.c in /home/Vatoth/PSU_2016_my_printf
** 
** Made by Quentin Sonnefraud
** Login   <Vatoth@epitech.net>
** 
** Started on  Tue Nov  8 15:26:20 2016 Quentin Sonnefraud
** Last update Thu Mar 23 18:01:29 2017 Quentin Sonnefraud
*/

#include "my.h"

static void     my_flag(const char flag, va_list ap,
			const char *tab)
{
  void		(*foncs[11]) (va_list, const char);
  int		i;

  i = 0;
  foncs[0] = my_put_nbr_pointer;
  foncs[1] = my_put_nbr_pointer;
  foncs[2] = my_put_long_pointer;
  foncs[3] = my_putchar_pointer;
  foncs[4] = my_putstr_pointer;
  foncs[5] = my_base_pointer;
  foncs[6] = my_base_pointer;
  foncs[7] = my_base_pointer;
  foncs[8] = my_printable_pointer;
  foncs[9] = my_put_pointers;
  foncs[10] = my_put_unsigned_pointer;
  while (i != 10)
    {
      if (flag == '%')
	my_putchar('%');
      if (flag == tab[i])
	foncs[i](ap, flag);
      i++;
    }
}

int		my_printf(const char *flag, ...)
{
  va_list	ap;
  int		i;

  i = 0;
  va_start(ap, flag);
  if (flag == NULL)
    return (0);
  else
    while (flag[i] != '\0')
      {
	while (flag[i] == '%')
	  {
	    i++;
	    my_flag(flag[i++], ap, "dilcsboxSpy");
	  }
	if (flag[i] == '\0')
	  return (0);
	else if (flag[i] != '%')
	  my_putchar(flag[i]);
	i++;
      }
  return (0);
}
