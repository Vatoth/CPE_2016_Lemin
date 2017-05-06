/*
** algo_fcts.c for algo_fcts in /home/homegan/projects/CPE_2016_Lemin
** 
** Made by Antoine
** Login   <antoine.le-du@epitech.eu>
** 
** Started on  Thu Apr 27 18:33:06 2017 Antoine
** Last update Thu Apr 27 18:35:21 2017 Antoine
*/

#include "lemin.h"
#include "graph.h"

int      is_end(t_ant *ants, t_anthill *anthill)
{
  int	i;

  if (!ants || !anthill)
    return (TRUE);
  i = 0;
  while (i < anthill->entry->ants)
    {
      if (ants[i].now != anthill->exit)
	return (FALSE);
      i += 1;
    }
  return (TRUE);
}

int      is_empty(t_ant *ants, t_room *room, int nb, t_anthill *anthill)
{
  int	i;

  if (!ants || !room)
    return (TRUE);
  if (room == anthill->exit)
    return (TRUE);
  i = 0;
  while (i < nb)
    {
      if (ants[i].now == room)
	return (FALSE);
      i += 1;
    }
  return (TRUE);
}

int      nb_in_next(t_ant *ants, t_room *room, int nb)
{
  int	i;
  int	nb_in_next;

  if (!ants || !room)
    return (-1);
  i = 0;
  nb_in_next = 0;
  while (i < nb)
    {
      if (ants[i].next == room)
	nb_in_next++;
      i += 1;
    }
  return (nb_in_next);
}
