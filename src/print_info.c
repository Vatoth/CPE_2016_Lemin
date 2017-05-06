/*
** print_info.c for lemin in /home/vatoth/CPE_2016_Lemin/src
**
** Made by
** Login   <quentin.sonnefraud@epitech.eu>
**
** Started on  Tue Apr 25 21:18:02 2017
** Last update Sun Apr 30 18:09:13 2017 Antoine
*/

#include "graph.h"
#include "lemin.h"

static void		print_tunnels(t_list *list)
{
  t_line		*lines;
  int			i;
  int			c;
  int			h;

  lines = list->first;
  while (lines)
    {
      i = 0;
      c = 0;
      h = 0;
      while (lines->line[i])
	{
	  if (lines->line[i] == EDGE_CHAR)
	    c++;
	  if (lines->line[i] == ' ')
	    h++;
	  i++;
	}
      if (c == 1 && h == 0 && lines->bool == TRUE)
	my_printf("%s\n", lines->line);
      lines = lines->next;
    }
}

static void	print_rooms(t_room *room, t_anthill *anthill)
{
  if (room && anthill)
    {
      if (room->next)
	print_rooms(room->next, anthill);
      if (room == anthill->entry)
	my_printf("##start\n");
      else if (room == anthill->exit)
	my_printf("##end\n");
      my_printf("%s %i %i\n", room->name, room->x, room->y);
    }
}

void	printf_info(t_list *list, t_anthill *anthill)
{
  my_printf("#number_of_ants\n");
  my_printf("%i\n", anthill->ants);
  my_printf("#rooms\n");
  print_rooms(anthill->first, anthill);
  my_printf("#tunnels\n");
  print_tunnels(list);
  my_printf("#moves\n");
}
