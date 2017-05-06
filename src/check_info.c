/*
** check_info.c for lemin in /home/vatoth/Epitech/CPE_2016_Lemin/src
** 
** Made by 
** Login   <quentin.sonnefraud@epitech.eu>
** 
** Started on  Sat Apr 29 10:41:12 2017 
** Last update Sun Apr 30 18:07:13 2017 Antoine
*/

#include "lemin.h"
#include "graph.h"

int     check_number(const char *str)
{
  int   i;

  i = 0;
  while (str[i])
    {
      if (str[i] >= '0' && str[i] <= '9')
	i++;
      else
	return (ERROR);
    }
  return (0);
}

int             check_twice(t_anthill *anthill,
			    const char *name,
			    const int x, const int y)
{
  t_room	*room;

  room = anthill->first;
  while (room)
    {
      if ((my_strcmp(room->name, name) == 0 ||
           (x == room->x && y == room->y)))
        return (ERROR);
      room = room->next;
    }
  return (0);
}

int     check_pos(const char *s)
{
  int   i;

  i = 0;
  while (s[i])
    {
      if ((s[i] >= '0' && s[i] <= '9') || s[i] == '-')
        i++;
      else
	return (ERROR);
    }
  return (0);
}

int     setup_room(char **tab, t_anthill *anthill,
		   t_room *room)
{
  room->ants = 0;
  room->mark = FALSE;
  room->distance = -1;
  if ((check_pos(tab[1]) == ERROR) ||
      (check_pos(tab[2]) == ERROR))
    return (ERROR);
  room->x = my_getnbr(tab[1]);
  room->y = my_getnbr(tab[2]);
  if (check_twice(anthill, room->name,
		  room->x, room->y) == ERROR)
    return (0);
  room->next = anthill->first;
  anthill->first = room;
  room->edges = NULL;
  return (0);
}
