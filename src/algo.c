/*
** algo.c for lemin in /home/vatoth/Epitech/CPE_2016_Lemin
** 
** Made by 
** Login   <quentin.sonnefraud@epitech.eu>
** 
** Started on  Sat Apr 15 15:39:29 2017 
** Last update Mon May  1 01:15:37 2017 Antoine
*/

#include "lemin.h"
#include "graph.h"

static int     print_path(int is_beginning, int nb, char *name)
{
  if (name)
    {
      if (is_beginning == TRUE)
	{
	  is_beginning = FALSE;
	  my_printf("P%d-%s", nb, name);
	}
      else
	my_printf(" P%d-%s", nb, name);
    }
  return (is_beginning);
}

static int	nb_now_and__next(t_room *temp, t_ant *ants,
				 int nb_ants, t_anthill *anthill)
{
  int           nb;

  nb = 0;
  if (is_empty(ants, temp, nb_ants, anthill) == FALSE)
    nb++;
  nb = nb + nb_in_next(ants, temp, nb_ants);
  return (nb);
}

static t_room	*find_shortest(t_room *now, t_ant *ants,
			       int nb_ants, t_anthill *anthill)
{
  int           distance;
  t_room        *shortest;
  t_edge        *temp;
  int           ants_in_room;

  temp = now->edges;
  distance = -1;
  while (temp)
    {
      ants_in_room = nb_now_and__next(temp->connect, ants, nb_ants, anthill);
      if ((distance == -1
	   || distance > (temp->connect->distance + ants_in_room))
	  && temp->connect->distance != -1)
	{
	  distance = (temp->connect->distance + ants_in_room);
	  shortest = temp->connect;
	}
      temp = temp->next;
    }
  if (distance == -1)
    return (NULL);
  return (shortest);
}

static int	find_a_way(t_ant *ants, t_anthill *anthill,
			   int is_beginning, int i)
{
  t_room        *shortest;

  if (ants[i].next &&
      is_empty(ants, ants[i].next, anthill->entry->ants, anthill) == TRUE)
    {
      ants[i].now = ants[i].next;
      ants[i].next = NULL;
      is_beginning = print_path(is_beginning, i + 1, ants[i].now->name);
    }
  else if (!ants[i].next)
    {
      if ((shortest = find_shortest(ants[i].now, ants,
				    anthill->entry->ants, anthill)))
	{
	  if (is_empty(ants, shortest, anthill->entry->ants, anthill) == TRUE)
	    {
	      ants[i].now = shortest;
	      ants[i].next = NULL;
	      is_beginning = print_path(is_beginning, i + 1, ants[i].now->name);
	    }
	  else
	    ants[i].next = shortest;
	}
    }
  return (is_beginning);
}

int      move_ants(t_ant *ants, t_anthill *anthill)
{
  int	i;
  int	is_beginning;

  while (is_end(ants, anthill) == FALSE)
    {
      i = 0;
      is_beginning = TRUE;
      while (i < anthill->entry->ants)
	{
	  if (ants[i].now != anthill->exit)
	    is_beginning = find_a_way(ants, anthill, is_beginning, i);
	  i += 1;
	}
      if (is_beginning == TRUE)
	return (84);
      my_printf("\n");
    }
  return (0);
}
