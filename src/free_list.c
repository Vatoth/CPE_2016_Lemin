/*
** free_list.c for free_list in /home/homegan/projects/CPE_2016_Lemin
** 
** Made by Antoine
** Login   <antoine.le-du@epitech.eu>
** 
** Started on  Mon Apr 10 17:50:18 2017 Antoine
** Last update Sun Apr 30 18:07:59 2017 Antoine
*/

#include "lemin.h"

int		free_list(t_list *list)
{
  t_line	*element;
  t_line	*element_prev;

  if (list)
    {
      element = list->first;
      while (element)
	{
	  element_prev = element;
	  element = element->next;
	  free(element_prev->line);
	  free(element_prev);
	}
    }
  return (0);
}
