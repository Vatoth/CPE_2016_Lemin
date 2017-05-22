/*
** put_square.c for my_put_square.c in /home/leandre/Rushs/scroller/lib/CSFML
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Fri Mar 31 13:58:02 2017 Léandre Blanchard
** Last update Sun Apr  2 16:04:29 2017 Léandre Blanchard
*/

#include "csfml.h"

void            put_square(sfVector2i pos, sfColor color,
			   t_window *window, int size)
{
  int           i;
  int           j;

  i = 0;
  j = 0;
  while (i != size)
    {
      my_put_pixel(window, pos.x + i, pos.y + j, color);
      j++;
      if (j == size)
	{
	  i++;
	  j = 0;
	}
    }
}
