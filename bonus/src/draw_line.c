/*
** draw_line.c for visu_hex in /home/leandre/Games/Lemin
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Mon May  1 16:40:42 2017 Léandre Blanchard
** Last update Mon May  1 17:12:51 2017 Léandre Blanchard
*/

#include "visuhex.h"

int		put_pixel(sfUint8 *pixels, int x, int y, sfColor color)
{
  if (x < 0 || y < 0)
    return (-1);
  if (x > 1280 || y > 720)
    return (-1);
  pixels[(1280 * y + x) * 4 + 0] = color.r;
  pixels[(1280 * y + x) * 4 + 1] = color.g;
  pixels[(1280 * y + x) * 4 + 2] = color.b;
  pixels[(1280 * y + x) * 4 + 3] = color.a;
  return (0);
}

void		my_put_square(sfUint8 *pixels, sfVector2i pos, int size,
			      sfColor color)
{
  int		i;
  int		j;

  i = 0;
  while (pos.y + i < pos.y + size)
    {
      j = 0;
      while (pos.x + j < pos.x + size)
	put_pixel(pixels, pos.x + j++, pos.y + i, color);
      i++;
    }
}

void            x_lines(sfUint8 *pixels, sfVector2f
			from, sfVector2f to, sfColor color)
{
  float         b;
  float         a;
  int           x;
  int           y;

  if (from.x >= to.x)
    x = to.x;
  else
    x = from.x;
  y = from.y;
  a = (to.y - from.y) / (to.x - from.x);
  b = from.y - (a * from.x);
  while ((x < to.x || x < from.x) && (to.x != from.x) && x < 1280 && x > 0)
    {
      y = (a * x + b) / 1;
      (y >= 0 && y <= 720) ? my_put_square(pixels, XY(x, y), L, color) : 0;
      x = x + 1;
    }
  y = from.y;
  while ((to.x == from.x) && (y != to.y) && y >= 0)
    {
      (y >= 0 && y <= 720) ? my_put_square(pixels, XY(x, y), L, color) : 0;
      y = y + 1;
    }
}

void            y_lines(sfUint8 *pixels, sfVector2f
			from, sfVector2f to, sfColor color)
{
  float         b;
  float         a;
  int           x;
  int           y;

  if (from.y >= to.y)
    y = to.y;
  else
    y = from.y;
  x = from.x;
  a = (to.x - from.x) / (to.y - from.y);
  b = from.x - a * from.y;
  while ((y < to.y || y < from.y) && (to.y != from.y) && x < 1280 && x > 0)
    {
      x = (a * y + b) / 1;
      (y >= 0 && y <= 720) ? my_put_square(pixels, XY(x, y), L, color) : 0;
      y = y + 1;
    }
  while ((to.y == from.y) && (x != to.x))
    {
      (y >= 0 && y <= 720) ? my_put_square(pixels, XY(x, y), L, color) : 0;
      y = (y >= to.x) ? y - 1 : y + 1;
    }
}

void            my_draw_line(sfUint8 *pixels, sfVector2f
			     from, sfVector2f to, sfColor color)
{
  float         a;
  sfVector2f    swap;

  if (from.y >= to.y)
    {
      swap = to;
      to = from;
      from = swap;
    }
  a = (to.x - from.x) / (to.y - from.y);
  if (a < (-1) || a > (1))
    x_lines(pixels, from, to, color);
  else
    y_lines(pixels, from, to, color);
}
