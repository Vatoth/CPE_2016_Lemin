/*
** free_tab.c for free_tab in /home/leandre/libmy/
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Tue Feb 28 14:14:05 2017 Léandre Blanchard
** Last update Sun Apr 30 16:47:15 2017 Léandre Blanchard
*/

#include <stdlib.h>

void	        free_tab(char **tab)
{
  int		i;

  i = 0;
  if (tab != NULL)
    {
      while (tab[i] != NULL)
	free(tab[i++]);
      free(tab);
    }
}
