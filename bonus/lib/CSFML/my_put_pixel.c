/*
** my_put_pixel.c for put_pixel in /home/leandre/Rushs/scroller/lib/CSFML
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Fri Mar 31 13:56:13 2017 Léandre Blanchard
** Last update Sun Apr 30 17:33:05 2017 Léandre Blanchard
*/

#include "csfml.h"

int		my_put_pixel(t_window *window, int x, int y, sfColor color)
{
  if (x < 0 || y < 0)
    return (-1);
  if (x > window->width || y > window->height)
    return (-1);
  window->pixels[(window->width * y + x) * 4 + 0] = color.r;
  window->pixels[(window->width * y + x) * 4 + 1] = color.g;
  window->pixels[(window->width * y + x) * 4 + 2] = color.b;
  window->pixels[(window->width * y + x) * 4 + 3] = color.a;
}
