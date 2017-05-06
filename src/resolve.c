/*
** resolve.c for lemin in /home/vatoth/Epitech/CPE_2016_Lemin
**
** Made by
** Login   <quentin.sonnefraud@epitech.eu>
**
** Started on  Fri Apr 14 13:31:49 2017
** Last update Sun Apr 30 12:34:02 2017 
*/

#include "graph.h"
#include "lemin.h"

void		explore(t_room *room, int i,
			t_anthill *anthill)
{
  t_edge	*edge;

  room->mark = TRUE;
  edge = room->edges;
  if (anthill->exit == room)
    room->distance = 0;
  while (edge)
    {
      if (i != -1 && (edge->connect->distance > i ||
		      edge->connect->distance == -1))
	edge->connect->distance = i;
      edge = edge->next;
    }
  edge = room->edges;
  while (edge)
    {
      if (edge->connect->mark == FALSE ||
	  edge->connect->distance >= i)
	{
	  edge->connect->mark = TRUE;
	  explore(edge->connect, i + 1, anthill);
	}
      edge = edge->next;
    }
}

int		check_graph(t_anthill *anthill)
{
  t_room	*room;

  room = anthill->exit;
  explore(room, 1, anthill);
  return (0);
}
