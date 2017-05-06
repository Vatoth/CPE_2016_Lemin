/*
** my_str_to_wordtab.c for asm in /home/Vatoth/Epitech/CPE_2016_corewar
** 
** Made by Quentin Sonnefraud
** Login   <quentin.sonnefraud@epitech.eu>
** 
** Started on  Fri Mar 31 11:47:37 2017 Quentin Sonnefraud
** Last update Fri Mar 31 14:09:37 2017 Quentin Sonnefraud
*/

#include <stdlib.h>
#include "my_str_to_wordtab.h"

static int	count_words(const char *str, char const separator)
{
  int		i;
  int		nb;

  i = 0;
  nb = 0;
  while (str[i])
    {
      while (str[i] && str[i] != separator)
	i++;
      nb++;
      while (str[i] && str[i] == separator)
	i++;
    }
  nb++;
  return (nb);
}

char    **my_str_to_wordtab(char *str, const char s)
{
  t_tab	tab;

  tab.i = 0;
  tab.y = 0;
  tab.k = 0;
  if ((tab.array = malloc(sizeof(*tab.array) * count_words(str, s))) == NULL)
    return (NULL);
  tab.nb = 0;
  while (str[tab.i])
    {
      tab.nb = tab.i;
      while (str[tab.nb] && str[tab.nb] != s && str[tab.nb])
	tab.nb++;
      if ((tab.array[tab.k] = malloc(sizeof(tab.array) * tab.nb)) == NULL)
	return (NULL);
      tab.nb = 0;
      tab.y = 0;
      while (str[tab.i] && str[tab.i] != s)
	tab.array[tab.k][tab.y++] = str[tab.i++];
      tab.array[tab.k++][tab.y] = '\0';
      while (str[tab.i] && str[tab.i] == s)
	tab.i++;
    }
  tab.array[tab.k] = NULL;
  return (tab.array);
}
