/*
** main.c for lem in in /home/Vatoth/Epitech/CPE_2016_Lemin
**
** Made by Quentin Sonnefraud
** Login   <quentin.sonnefraud@epitech.eu>
**
** Started on  Mon Apr  3 15:06:48 2017 Quentin Sonnefraud
** Last update Sun Apr 30 12:34:29 2017 
*/

#include <stdlib.h>
#include "lemin.h"
#include "graph.h"

static t_ant    *get_ants(int nb, t_anthill *anthill)
{
  t_ant         *ants;
  int           i;

  if (!(ants = malloc(sizeof(*ants) * nb)))
    return (NULL);
  i = 0;
  while (i < nb)
    {
      ants[i].now = anthill->entry;
      ants[i].next = NULL;
      i += 1;
    }
  return (ants);
}

void	init(t_anthill *anthill, t_list *list)
{
  anthill->first = NULL;
  anthill->exit = NULL;
  anthill->entry = NULL;
  list->first = NULL;
  list->last = NULL;
  list->len = 0;
}

int		main(int ac, char **av)
{
  t_list	list;
  t_anthill	anthill;
  t_ant		*ants;

  if (ac != 1 || av[1] != NULL)
    return (my_printf("USAGE:\n\t ./lem_in < map\n"));
  init(&anthill, &list);
  if (recup_info(&list, &anthill) == ERROR ||
      anthill.entry == NULL || anthill.exit == NULL)
    {
      printf_info(&list, &anthill);
      return (ERROR);
    }
  anthill.entry->ants = anthill.ants;
  check_graph(&anthill);
  if (anthill.entry->mark == FALSE)
    {
      printf_info(&list, &anthill);
      return (ERROR);
    }
  printf_info(&list, &anthill);
  if (!(ants = get_ants(anthill.entry->ants, &anthill)))
    return (1);
  move_ants(ants, &anthill);
  return (0);
}
