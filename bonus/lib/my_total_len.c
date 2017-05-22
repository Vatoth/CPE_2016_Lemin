/*
** my_total_len.c for my_total_len in /home/leandre/libmy
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Thu Mar 23 22:35:06 2017 Léandre Blanchard
** Last update Sun Apr 30 17:24:37 2017 Léandre Blanchard
*/

#include "my.h"

int		my_total_len(char **tab)
{
  int		len;
  int		i;

  i = 0;
  len = 0;
  while (tab[i] != NULL)
    len += my_strlen(tab[i++]);
  return (len);
}

char		*my_tab_to_str(char **tab)
{
  char		*str;
  int		i;
  int		len;

  len = my_total_len(tab);
  i = 0;
  if ((str = malloc(sizeof(char) * len + 1)) == NULL)
    return (NULL);
  zeros(str, len + 1);
  while (tab[i] != NULL)
    my_strcat(str, tab[i++]);
  return (str);
}
