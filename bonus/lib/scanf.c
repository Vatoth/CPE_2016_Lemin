/*
** scanf.c for scanf in /home/leandre/Prog_elem/my_scanf
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Tue Jan 17 11:18:27 2017 Léandre Blanchard
** Last update Sun Apr 30 17:26:31 2017 Léandre Blanchard
*/

#include "scanf.h"
#include "get_next_line.h"
#include "my.h"

char            *my_scanf(const char *str)
{
  my_printf(str);
  return (get_next_line(0));
}
