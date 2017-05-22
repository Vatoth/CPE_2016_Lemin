/*
** my_catalloc.c for my_catalloc in /home/leandre/System_unix/PSU_2016_minishell2
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Mon Apr  3 19:27:11 2017 Léandre Blanchard
** Last update Mon Apr 10 01:06:27 2017 Léandre Blanchard
*/

#include "my.h"

char		*my_catalloc(const char *s, const char *s_2)
{
  char		*out;

  if (s == NULL || s_2 == NULL)
    return (NULL);
  if ((out = my_calloc(my_strlen(s) + my_strlen(s_2) + 1)) == NULL)
    return (NULL);
  my_strcat(out, s);
  my_strcat(out, s_2);
  return (out);
}
