/*
** tools.c for asm in /home/Vatoth/Epitech/CPE_2016_corewar/ASM
**
** Made by Quentin Sonnefraud
** Login   <quentin.sonnefraud@epitech.eu>
**
** Started on  Wed Mar 22 13:55:03 2017 Quentin Sonnefraud
** Last update Tue Apr 11 16:35:22 2017 Antoine
*/

#include <unistd.h>
#include <stdlib.h>
#include "lemin.h"

int	my_putstr_error(const char *str)
{
  int	i;

  i = -1;
  while (str[++i])
    write(2, &str[i], i);
  return (ERROR);
}

int     my_strcmp(const char *s1, const char *s2)
{
  int   character;

  if (!s1 || !s2)
    return ((s1) ? 1 : (s2) ? -1 : 0);
  character = 0;
  while (s1[character] == s2[character] && s1[character] && s2[character])
    character = character + 1;
  if (s1[character] > s2[character])
    return (1);
  else if (s1[character] < s2[character])
    return (-1);
  else
    return (0);
}

char    *my_strdup(const char *src)
{
  char  *dest;
  int   i;
  int   n;

  i = 0;
  n = my_strlen(src);
  if ((dest = malloc(sizeof(char) * (n + 1))) == NULL)
    return (NULL);
  while (i < n)
    {
      dest[i] = src[i];
      ++i;
    }
  dest[i] = '\0';
  return (dest);
}

int     my_compare(char *s1, char *s2, int i)
{
  int	nb;

  nb = 0;
  while (i > 0 && s1[nb] != '\0' && s2[nb] != '\0')
    {
      if (s1[nb] != s2[nb])
	return (1);
      nb++;
      i--;
    }
  if (i == 0)
    return (0);
  if (my_strlen(s1) != my_strlen(s2))
    return (1);
  return (0);
}

int	count_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    i++;
  return (i);
}
