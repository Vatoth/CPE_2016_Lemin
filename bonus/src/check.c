/*
** parsing.c for parsing.c in /home/vatoth/Epitech/CPE_2016_Lemin/bonus
**
** Made by
** Login   <quentin.sonnefraud@epitech.eu>
**
** Started on  Fri Apr 28 15:35:11 2017
** Last update Sun Apr 30 18:23:20 2017 Léandre Blanchard
*/

#include <string.h>
#include "visuhex.h"
#include "my_str_to_wordtab.h"

int	count_int(char **tab, const char *s)
{
  int	i;
  int	nb;

  nb = 0;
  i = 0;
  while (strcmp(tab[i], s) != 0)
    {
      if (tab[i][0] != '#')
	nb++;
      i++;
    }
  return (nb);
}

int	count_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    i++;
  return (i);
}

static void     bord(t_all *all, char **tab, int *i, int j)
{
  if (strcmp(tab[*i], "##end") == 0)
    {
      all->end = j;
      *i = *i + 1;
    }
  else if (strcmp(tab[*i], "##start") == 0)
    {
      all->start = j;
      *i = *i + 1;
    }
}

static int	take_room(char **tab, t_all *all)
{
  char		**plop;
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (tab[i] && strcmp(tab[i], "#tunnels") != 0)
    {
      bord(all, tab, &i, j);
      if (tab[i] && strcmp(tab[i], "#tunnels") != 0)
	{
          plop = my_str_to_wordtab(tab[i++], ' ');
          memset(all->rooms[j].name, 0, 20);
          memcpy(all->rooms[j].name, plop[0], strlen(plop[0]));
          all->rooms[j].no = j;
          all->rooms[j].pos.x = atoi(plop[1]);
          all->rooms[j++].pos.y = atoi(plop[2]);
          free_tab(plop);
	}
    }
  return (i);
}

t_all   *parse(char **tab)
{
  int   i;
  int   j;
  t_all *all;

  if (tab == NULL || tab[0] == NULL)
    return (NULL);
  if (((all = malloc(sizeof(t_all))) == NULL) || !(tab[1]) || !(tab[3]))
    return (NULL);
  all->nb_ants = atoi(tab[1]);
  all->nb_room = count_int(&tab[3], "#tunnels");
  if ((all->rooms = malloc(sizeof(t_room) * all->nb_room)) == NULL ||
      (all->ants = malloc(sizeof(t_ant) * all->nb_ants)) == NULL)
    return (NULL);
  i = take_room(&tab[3], all);
  i = i + 3;
  j = 0;
  while (j < atoi(tab[1]))
    {
      memset(all->ants[j].name, 0, 20);
      all->ants[j].no = j;
      j++;
    }
  take_tunnels(&tab[++i], all);
  return (all);
}
