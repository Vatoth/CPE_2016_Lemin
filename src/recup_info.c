/*
** recup_info.c for recup_info in /home/vatoth/Epitech/CPE_2016_Lemin
**
** Made by
** Login   <quentin.sonnefraud@epitech.eu>
**
** Started on  Mon Apr 10 12:58:07 2017
** Last update Sat Apr 29 10:49:51 2017 
*/

#include <stdio.h>
#include "lemin.h"
#include "get_next_line.h"
#include "graph.h"
#include "my_str_to_wordtab.h"

static void		setup_list(t_line *new_element,
				   t_list *list)
{
   list->len++;
   new_element->bool = FALSE;
   new_element->prev = list->last;
   new_element->next = NULL;
   if (list->last)
     list->last->next = new_element;
   else
     list->first = new_element;
   list->last = new_element;
}

int		recup_info(t_list *list, t_anthill *anthill)
{
  t_line	*new_element;
  char		*s;

  while ((s = get_next_line(0)))
    {
      if (s[0] == 0)
	return (ERROR);
      epur_str(s);
      if (!(new_element = malloc(sizeof(*new_element))) ||
	  (!(new_element->line = my_strdup(s))))
	return (ERROR);
      setup_list(new_element, list);
      free(s);
    }
  clear_list(list);
  if (list->first == NULL)
    return (ERROR);
  return (parse_info(list, anthill));
}
