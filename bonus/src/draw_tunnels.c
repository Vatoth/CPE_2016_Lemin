/*
** draw_tunnels.c for visu-hex in /home/leandre/Games/Lemin
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Mon May  1 16:51:47 2017 Léandre Blanchard
** Last update Mon May  1 17:08:59 2017 Léandre Blanchard
*/

#include "visuhex.h"

int		draw_tunnels(t_all *all, t_window *window)
{
  int		i;
  sfVector2f	from;
  sfVector2f	to;
  int		no;

  i = 0;
  while (i < all->nb_tunnel)
    {
      no = all->tunnels[i].x;
      from = xy_vectorf((float)all->rooms[no].pos.x * 10 + 80,
			(float)all->rooms[no].pos.y * 5 + 64);
      no = all->tunnels[i].y;
      to = xy_vectorf((float)all->rooms[no].pos.x * 10 + 80,
		      (float)all->rooms[no].pos.y * 5 + 64);
      my_draw_line(window->pixels, from, to,
		   sfColor_fromRGBA(200, 200, 200, 200));
      i++;
    }
  return (0);
}
