/*
** create_edge.c for create_edge.c in /home/vatoth/Epitech/CPE_2016_Lemin/src
** 
** Made by 
** Login   <quentin.sonnefraud@epitech.eu>
** 
** Started on  Sat Apr 29 10:46:24 2017 
** Last update Sun Apr 30 13:56:28 2017 
*/

#include "graph.h"
#include "lemin.h"
#include "my_str_to_wordtab.h"

static void     linking(t_room *room, t_room *to_link,
                        t_edge *edge, t_edge *edge_link)
{
  edge_link->connect = room;
  edge_link->next = to_link->edges;
  to_link->edges = edge_link;
  edge->connect = to_link;
  edge->next = room->edges;
  room->edges = edge;
}

static int	create_edge(char **tab, t_anthill *anthill,
			    int found_first, int found_second)
{
  t_room        *room;
  t_room        *to_link;
  t_edge        *edge;
  t_edge        *edge_link;

  room = anthill->first;
  to_link = anthill->first;
  while (room && to_link && (found_first == 0 || found_second == 0))
    {
      if (my_strcmp(room->name, tab[0]) == 0)
        found_first = 1;
      else
        room = room->next;
      if (my_strcmp(to_link->name, tab[1]) == 0)
        found_second = 1;
      else
        to_link = to_link->next;
    }
  if (found_first == 0 || found_second == 0 ||
      !(edge = malloc(sizeof(*edge)))
      || !(edge_link = malloc(sizeof(*edge_link))))
    return (ERROR);
  linking(room, to_link, edge, edge_link);
  return (0);
}

int		create_link(t_list *list, t_anthill *anthill)
{
  t_line        *element;
  char          **tab;
  char          *temp;

  element = list->first;
  while (element)
    {
      if (!(tab = my_str_to_wordtab(element->line, EDGE_CHAR)))
        return (ERROR);
      if (count_tab(tab) == 2)
        {
          if (create_edge(tab, anthill, 0, 0) == ERROR)
            return (ERROR);
          temp = tab[0];
          tab[0] = tab[1];
          tab[1] = temp;
          if (create_edge(tab, anthill, 0, 0) == ERROR)
            return (ERROR);
          element->bool = TRUE;
        }
      free_tab(tab);
      element = element->next;
    }
  return (0);
}
