/*
** get_next_line.c for gnl in /home/leandre/Prog_elem/CPE_2016_getnextline/new
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Mon Apr  3 16:40:21 2017 Léandre Blanchard
** Last update Thu Apr 27 21:33:15 2017 Léandre Blanchard
*/

#include "get_next_line.h"

static char	*my_free_realloc(char *s, int size)
{
  char		*out;

  if ((out = my_realloc(s, size)) == NULL)
    return (NULL);
  free(s);
  return (out);
}

static t_gnl	init_struct()
{
  t_gnl		tuple;

  tuple.i = 0;
  tuple.size = 2;
  tuple.s = my_calloc(tuple.size);
  return (tuple);
}

char		*get_next_line(int fd)
{
  t_gnl		all;
  static int	status;

  all = init_struct();
  if (all.s == NULL)
    return (NULL);
  if (status == -1 || all.s == NULL)
    return (NULL);
  while ((status = read(fd, &all.ch, 1)) > 0)
    {
      if (all.ch == '\n')
	return (all.s);
      all.s[all.i++] = all.ch;
      if ((all.s = my_free_realloc(all.s, ++all.size)) == NULL)
	return (NULL);
    }
  if (status == 0)
    {
      status = -1;
      return (all.s);
    }
  return (all.s);
}
