/*
** graph.h for lemin in /home/vatoth/Epitech/CPE_2016_Lemin
**
** Made by
** Login   <quentin.sonnefraud@epitech.eu>
**
** Started on  Mon Apr 10 14:51:23 2017
** Last update Tue May  2 13:23:21 2017 Léandre Blanchard
*/

#ifndef GRAPH_H_
# define GRAPH_H_

# define TRUE (1)
# define FALSE (0)

typedef int t_bool;

typedef struct		s_room
{
  int			ants;
  int			visits;
  int			distance;
  t_bool		mark;
  char			*name;
  int			x;
  int			y;
  struct s_edge		*edges;
  struct s_room		*next;
}			t_room;

typedef struct		s_edge
{
  struct s_room		*connect;
  struct s_edge		*next;
}			t_edge;

typedef struct		s_ant
{
  struct s_room		*now;
  struct s_room		*next;
}			t_ant;

typedef struct		s_anthill
{
  int			ants;
  struct s_room		*entry;
  struct s_room		*exit;
  struct s_room		*first;
}			t_anthill;

#endif /* !GRAPH_H_ */
