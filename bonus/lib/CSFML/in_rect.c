/*
** in_rect.c for CSFML in /home/leandre/C_graphical_prog/tekadventure
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Thu Apr 20 09:14:16 2017 Léandre Blanchard
** Last update Sat Apr 22 16:48:17 2017 Léandre Blanchard
*/

#include "csfml.h"

int		is_in_rect(t_window *window, sfVector2f origin, sfVector2f size)
{
  pos_mouse(window);
  if (window->mouse.x >= origin.x && window->mouse.x <= (origin.x + size.x)
      && window->mouse.y >= origin.y && window->mouse.y <= (origin.y + size.y))
    return (0);
  return (1);
}
