/*
** zeros.c for zeros in /home/leandre/Prog_elem/CPE_2016_corewar_bootstrap
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Mon Feb 27 14:30:19 2017 Léandre Blanchard
** Last update Sun Apr 30 17:27:20 2017 Léandre Blanchard
*/

#include <stdlib.h>

int		zeros(char *ptr, int size)
{
  int		i;

  i = 0;
  if (ptr == NULL)
    return (-1);
  while (i != size)
    ptr[i++] = 0;
  return (0);
}
