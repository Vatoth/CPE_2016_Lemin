/*
** realloc.c for mnishell in /home/leandre/System_unix/PSU_2016_minishell1
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Sat Jan 21 17:29:08 2017 Léandre Blanchard
** Last update Thu Apr 27 12:54:35 2017 Léandre Blanchard
*/

#include "my.h"

char		**tab_realloc(char **src, int add)
{
  char		**tab;
  int		len;
  int		i;

  i = 0;
  len = my_tablen(src);
  if ((tab = malloc(sizeof(char *) * (len + add + 1))) == NULL)
    return (NULL);
  while (src[i] != NULL)
    tab[i] = src[i++];
  tab[i] = NULL;
  return (tab);
}

char            *my_realloc(const char *str, int size)
{
  char          *dest;
  int           i;

  i = 0;
  if (str == NULL)
    return (NULL);
  if ((dest = my_calloc(sizeof(char) * (my_strlen(str) + size))) == NULL)
    return (NULL);
  while (i != size)
    {
      dest[i] = 0;
      i = i + 1;
    }
  i = 0;
  while (str[i] != '\0')
    {
      dest[i] = str[i];
      i = i + 1;
    }
  return (dest);
}
