/*
** parse.c for lemin in /home/vatoth/Epitech/CPE_2016_Lemin/src
** 
** Made by 
** Login   <quentin.sonnefraud@epitech.eu>
** 
** Started on  Sat Apr 29 10:43:52 2017 
** Last update Sun Apr 30 18:08:56 2017 Antoine
*/

#include "graph.h"
#include "lemin.h"
#include "my_str_to_wordtab.h"

static int              parser(t_line *element, t_anthill *anthill,
			       const int check_start, const int check_exit)
{
  char                  **tab;
  t_room                *room;

  if (!(tab = my_str_to_wordtab(element->line, SEPARATOR_CHAR)))
    return (ERROR);
  if (count_tab(tab) == 3)
    {
      if (!(room = malloc(sizeof(*room))) ||
          !(room->name = my_strdup(tab[0]))
          || (setup_room(tab, anthill, room) == ERROR))
        return (ERROR);
      room->mark = FALSE;
      if (check_start == 1 && anthill->entry == NULL)
        anthill->entry = room;
      else if (check_exit == 1 && anthill->exit == NULL)
        anthill->exit = room;
      element->bool = TRUE;
    }
  free_tab(tab);
  return (0);
}

static int              get_info(t_anthill *anthill, t_line *element,
				 int check_start, int check_exit)
{
  while (element)
    {
      if (my_strcmp(element->line, START_COMMENT) == 0)
        {
          if ((check_exit >= 2 && anthill->exit == NULL) || check_start > 0)
            return (ERROR);
          check_start++;
          element = element->next;
        }
      else if (my_strcmp(element->line, END_COMMENT) == 0)
        {
          if ((check_start >= 2 && anthill->entry == NULL) || check_exit > 0)
            return (ERROR);
          check_exit++;
          element = element->next;
        }
      else
        {
          if (parser(element, anthill, check_start, check_exit) == ERROR)
            return (ERROR);
          element = element->next;
        }
    }
  return (0);
}

int              parse_info(t_list *list, t_anthill *anthill)
{
  t_line	*element;

  element = list->first;
  if (check_number(element->line) == ERROR)
    return (ERROR);
  list->first->bool = TRUE;
  anthill->ants = my_getnbr(element->line);
  if (get_info(anthill, element, 0, 0) == ERROR ||
      anthill->entry == NULL || anthill->exit == NULL)
    return (ERROR);
  return (create_link(list, anthill));
}
