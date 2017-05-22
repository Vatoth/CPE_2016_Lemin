/*
** full_read.c for full_read in /home/leandre/TEST_FOLDER
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Thu Apr 27 00:31:02 2017 Léandre Blanchard
** Last update Thu Apr 27 01:05:34 2017 Léandre Blanchard
*/

#include "my.h"

char            *complete_read_lseek(int fd)
{
  char          *s;
  int           cur;
  int           size;

  cur = lseek(fd, 0, SEEK_CUR);
  size = lseek(fd, 0, SEEK_END);
  lseek(fd, cur, 0);
  my_printf("current : %d, size : %d\n", cur, size);
  if ((s = my_calloc(size + 2)) == NULL)
    return (NULL);
  if ((read(fd, s, size)) == -1)
    return (NULL);
  return (s);
}
