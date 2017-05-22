/*
** total_name.c for total_name in /home/leandre/Prog_elem/CPE_2016_corewar
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Wed Mar  1 12:08:37 2017 Léandre Blanchard
** Last update Mon Apr 10 01:05:44 2017 Léandre Blanchard
*/

#include <stdlib.h>

int		total_name(char *str)
{
  int           i;
  int           nb;

  nb = 0;
  i = 0;
  if (str == NULL)
    return (0);
  while (str[i] != 0)
    nb += str[i++];
  return (nb);
}
