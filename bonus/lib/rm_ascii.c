/*
** rm_ascii.c for rm_ascii in /home/leandre/System_unix/PSU_2016_minishell2
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Mon Apr 10 01:33:51 2017 Léandre Blanchard
** Last update Mon Apr 10 01:56:29 2017 Léandre Blanchard
*/

#include "my.h"

int		rm_ascii(char *s)
{
  int		i;

  i = 0;
  if (s == NULL)
    return (-1);
  while (s[i] != 0)
    {
      if (s[i] < 6 || s[i] > 127 || (s[i] > 6 && s[i] < 32))
	{
	  s[i] = 0;
	  return (0);
	}
      i++;
    }
  return (0);
}
