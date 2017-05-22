/*
** quit.c for csfml in /home/leandre/C_graphical_prog/tekadventure
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Tue Apr  4 22:01:01 2017 Léandre Blanchard
** Last update Thu Apr 27 21:03:22 2017 Léandre Blanchard
*/

#include "csfml.h"

void		close_win(t_window *win)
{
  sfVector2i    pos;

  pos = pos_mouse(win);
  if (pos.x >= win->width - 40 && pos.y <= 0 &&
      sfMouse_isButtonPressed(sfMouseLeft)
      && pos.x <= win->width && pos.y >= -40)
    sfRenderWindow_close(win->window);
  if (KP(sfKeyEscape))
    sfRenderWindow_close(win->window);
  sfRenderWindow_pollEvent(win->window, &win->event);
}
