/*
** clear_list.c for clear_list in /home/homegan/projects/CPE_2016_Lemin
** 
** Made by Antoine
** Login   <antoine.le-du@epitech.eu>
** 
** Started on  Mon Apr 10 17:32:23 2017 Antoine
** Last update Sat Apr 29 15:28:47 2017 Antoine
*/

#include "lemin.h"

t_line		*del_in_list(t_list *list, t_line *element)
{
  t_line	*temp;

  temp = NULL;
  if (element->next == NULL)
    {
      list->last = element->prev;
      if (list->last != NULL)
	list->last->next = NULL;
    }
  else if (element->prev == NULL)
    {
      list->first = element->next;
      if (list->first != NULL)
	list->first->prev = NULL;
    }
  else
    {
      element->next->prev = element->prev;
      element->prev->next = element->next;
    }
  temp = element->next;
  free(element->line);
  list->len--;
  return (temp);
}

char	*get_without_hashtag(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '#' && str[i] != '\0')
    i++;
  if (str[i] == '\0')
    return (str);
  if (my_compare("##start", str + i, 3) == 0)
    i = i + 7;
  else if (my_compare("##end", str + i, 3) == 0)
    i = i + 5;
  while (str[i] != '\0')
    {
      if (str[i] == '#')
	{
	  str[i] = '\0';
	  return (str);
	}
      i++;
    }
  return (str);
}

int             clear_list(t_list *list)
{
  t_line     *element;

  if (list != NULL)
    {
      element = list->first;
      while (element)
        {
	  if (my_strlen(element->line) == 0)
	    del_in_list(list, element);
          else if (element->line[0] == '#' &&
		   my_compare(element->line, "##start", 7) != 0
		   && my_compare(element->line, "##end", 5) != 0)
	    del_in_list(list, element);
	  else
	    element->line = get_without_hashtag(element->line);
	  element = element->next;
        }
    }
  return (0);
}
