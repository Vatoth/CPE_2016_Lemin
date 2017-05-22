/*
** my_put_tab.c for put_tab in /home/leandre
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Fri Feb 24 16:25:21 2017 Léandre Blanchard
** Last update Sun Apr 30 17:20:40 2017 Léandre Blanchard
*/

#include <unistd.h>
#include "my.h"

void		my_put_tab(char **tab)
{
  int		i;

  i = 0;
  if (tab != NULL)
    {
      while (tab[i] != NULL)
	my_printf("%s\n", tab[i++]);
    }
}

void		my_put_tabw(const char *start, char **tab, const char *end)
{
  int		i;

  i = 0;
  if (tab != NULL)
    {
      while (tab[i] != NULL)
	my_printf("%s%s%s", start, tab[i++], end);
    }
}
