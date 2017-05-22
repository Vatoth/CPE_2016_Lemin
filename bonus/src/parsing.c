/*
** parsing.c for parsing.c in /home/vatoth/Epitech/CPE_2016_Lemin/bonus
**
** Made by
** Login   <quentin.sonnefraud@epitech.eu>
**
** Started on  Fri Apr 28 15:35:11 2017
** Last update Mon May  1 16:19:37 2017 Léandre Blanchard
*/

#include <visuhex.h>
#include <string.h>
#include <my_str_to_wordtab.h>

static void		take_move(t_all *all, char **moves, int i)
{
  int			index;
  char			**move;
  int			j;

  index = 0;
  while (moves[index])
    {
      move = my_str_to_wordtab(moves[index], '-');
      all->moves[i][index].no = atoi(&move[0][1]);
      j = 0;
      while (strcmp(all->rooms[j].name, move[1]) != 0)
	j++;
      all->moves[i][index].room = all->rooms[j].no;
      index++;
      free_tab(move);
    }
  all->moves[i][index].no = -1;
  all->moves[i][index].room = -1;
}

static int		take_moves(t_all *all, char **tab)
{
  int			i;
  int			len;
  char			**moves;

  i = 0;
  len = 0;
  while (tab[len])
    len++;
  if ((all->moves = malloc(sizeof(t_move *) * (len + 1))) == NULL)
    return (-1);
  while (tab[i])
    {
      moves = my_str_to_wordtab(tab[i], ' ');
      if ((all->moves[i] = malloc(sizeof(t_move)
				  * (count_tab(moves) + 1))) == NULL)
	return (-1);
      take_move(all, moves, i);
      free_tab(moves);
      i++;
    }
  all->moves[len] = NULL;
  return (0);
}

int			take_tunnels(char **tab, t_all *all)
{
  char			**tunnels;
  int			i;

  all->nb_tunnel = count_int(tab, "#moves");
  if ((all->tunnels = malloc(sizeof(sfVector2i) * all->nb_tunnel)) == NULL)
    return (-1);
  i = 0;
  while (tab[i] && strcmp(tab[i], "#moves") != 0)
    {
      tunnels = my_str_to_wordtab(tab[i], '-');
      all->tunnels[i].x = 0;
      all->tunnels[i].y = 0;
      while (strcmp(tunnels[0], all->rooms[all->tunnels[i].x].name) != 0)
	{
	  all->tunnels[i].x++;
	}
      while (strcmp(tunnels[1], all->rooms[all->tunnels[i].y].name) != 0)
        all->tunnels[i].y++;
      i++;
      free_tab(tunnels);
    }
  take_moves(all, &tab[++i]);
  return (0);
}
