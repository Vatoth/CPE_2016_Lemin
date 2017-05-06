/*
** lem_in.h for lem_in in /home/Vatoth/Epitech/CPE_2016_Lemin
** 
** Made by Quentin Sonnefraud
** Login   <quentin.sonnefraud@epitech.eu>
** 
** Started on  Mon Apr  3 15:11:11 2017 Quentin Sonnefraud
** Last update Tue May  2 13:26:32 2017 Léandre Blanchard
*/

#ifndef LEMIN_H_
# define LEMIN_H_

# include <stdlib.h>
# include "graph.h"

# define ERROR (1)
# define START_COMMENT "##start"
# define END_COMMENT "##end"
# define EDGE_CHAR '-'
# define SEPARATOR_CHAR ' '

typedef struct          s_line
{
  char                  *line;
  t_bool		bool;
  struct s_line	        *next;
  struct s_line		*prev;
}                       t_line;

typedef struct          s_list
{
  int                   len;
  struct s_line         *first;
  struct s_line	        *last;
}                       t_list;

void    printf_info(t_list *list, t_anthill *anthill);
void    free_tab(char **tab);
int	recup_info(t_list *list, t_anthill *anthill);
char	*my_strdup(const char *src);
int	my_strlen(const char *);
int	my_printf(const char *s, ...);
int     count_tab(char **tab);
int     my_putstr_error(const char *str);
void    epur_str(char *str);
int     my_getnbr(const char *str);
int     my_strcmp(const char *s1, const char *s2);
int	clear_list(t_list *list);
int     my_compare(char *s1, char *s2, int i);
int	free_list(t_list *list);
int	check_graph(t_anthill *anthill);
int	path(t_anthill *anthill);
int	move_ants(t_ant *ants, t_anthill *anthill);
int     is_end(t_ant *ants, t_anthill *anthill);
int     is_empty(t_ant *ants, t_room *room, int nb, t_anthill *anthill);
int     nb_in_next(t_ant *ants, t_room *room, int nb);
int     setup_room(char **tab, t_anthill *anthill, t_room *room);
int     create_link(t_list *list, t_anthill *anthill);
int     check_number(const char *str);
int     parse_info(t_list *list, t_anthill *anthill);

#endif /* !LEMIN_H_ */
