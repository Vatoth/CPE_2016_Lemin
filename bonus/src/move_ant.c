/*
** move_ant.c for visu-hex in /home/leandre/Games/Lemin
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Sun Apr 30 21:56:19 2017 Léandre Blanchard
** Last update Mon May  1 17:52:48 2017 Léandre Blanchard
*/

#include "visuhex.h"

static int	init_pos(t_all *all)
{
  int		i;

  i = 0;
  while (i < all->nb_ants)
    {
      all->ants[i].pos.x = all->rooms[all->start].pos.x;
      all->ants[i].pos.y = all->rooms[all->start].pos.y;
      i++;
    }
  return (0);
}

int		move_ants(t_all *all)
{
  int		i;
  int		j;
  int		room;
  int		ant;

  i = 0;
  init_pos(all);
  while (all->moves[i] != NULL)
    {
      j = 0;
      while (all->moves[i][j].no != -1)
	{
	  usleep(500000);
	  room = all->moves[i][j].room;
	  ant = all->moves[i][j].no - 1;
	  all->ants[ant].pos = xy_vectorf(all->rooms[room].pos.x,
					  all->rooms[room].pos.y);
	  my_clear();
	  if (room != all->start && room != all->end)
	    my_printf("ant n°%d -> room (%d)\r", ant + 1, room);
	  if (room == all->start)
	    my_printf("ant n°%d -> [start]\r", ant + 1);
	  if (room == all->end)
	    my_printf("and n°%d -> [end]\r", ant + 1);
	  j++;
	}
      i++;
    }
  return (0);
}
