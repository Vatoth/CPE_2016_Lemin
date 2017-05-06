/*
** tools.c for asm in /home/Vatoth/epitech/CPE_2016_Lemin
**
** Made by Quentin Sonnefraud                                      
** Login   <quentin.sonnefraud@epitech.eu>
**
** Started on  Wed Mar 22 13:55:03 2017 Quentin Sonnefraud
** Last update Tue Apr 11 16:35:22 2017 Antoine                      
*/

#include <stdlib.h>

void	free_tab(char **tab)
{
  int	i;

  i = 0;
  if (tab != NULL)
    {
      while (tab[i])
	free(tab[i++]);
      free(tab);
    }
}
