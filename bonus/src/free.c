/*
** free.c for visu-hex in /home/leandre/Prog_elem/CPE_2016_Lemin/bonus
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Sun Apr 30 18:15:09 2017 Léandre Blanchard
** Last update Sun Apr 30 20:45:07 2017 Léandre Blanchard
*/

#include "visuhex.h"

void		free_all(t_all *all, t_window *window, char *input, char **tab)
{
  free_window(window);
  free_tab(tab);
  if (input != NULL)
    free(input);
  if (all != NULL)
    {
      if (all->rooms != NULL)
	free(all->rooms);
      if (all->ants != NULL)
	free(all->ants);
      if (all->moves != NULL)
	free(all->moves);
      if (all->tunnels != NULL)
	free(all->tunnels);
      free(all);
    }
}

void		free_hive(t_hive *hive)
{
  if (hive != NULL)
    {
      free_sprite(hive->room);
      free_sprite(hive->background);
      free_sprites_only(hive->ants);
      free(hive);
    }
}
