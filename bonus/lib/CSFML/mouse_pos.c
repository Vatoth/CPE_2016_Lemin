/*
** mouse_pos.c for mouse_pos in /home/leandre/Rushs/scroller/lib/CSFML
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Fri Mar 31 14:00:42 2017 Léandre Blanchard
** Last update Wed Apr  5 13:31:00 2017 Léandre Blanchard
*/

#include "csfml.h"

sfVector2i     	pos_mouse(t_window *window)
{
  window->mouse = sfMouse_getPositionRenderWindow(window->window);
  return (window->mouse);
}
