/*
** visu-hex.h for visu-hex in /home/leandre/Prog_elem/CPE_2016_Lemin/bonus
**
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
**
** Started on  Thu Apr 27 00:40:02 2017 Léandre Blanchard
** Last update Tue May  2 10:04:32 2017 Léandre Blanchard
*/

#ifndef VISUHEX_H_
# define VISUHEX_H_

# include <fcntl.h>
# include <sys/types.h>
# include <sys/ioctl.h>
# include <unistd.h>
# include <ncurses.h>
# include <termios.h>
# include <stdio.h>
# include <math.h>

# include "my.h"
# include "colors.h"
# include "defines.h"
# include "my_csfml.h"
# include "my_str_to_wordtab.h"

typedef struct	s_ant
{
  int		no;
  char		name[20];
  sfVector2f	pos;
}		t_ant;

typedef struct	s_room
{
  int		no;
  char		name[20];
  sfVector2i	pos;
}		t_room;

typedef struct	s_hive
{
  t_sprite	*background;
  t_sprite	*room;
  t_sprite	**ants;
}		t_hive;

typedef struct	s_move
{
  int		no;
  int		room;
}		t_move;

typedef struct  s_all
{
  int		nb_ants;
  int		nb_room;
  int		nb_tunnel;
  int	        start;
  int		end;
  t_room	*rooms;
  sfVector2i	*tunnels;
  t_move	**moves;
  t_ant		*ants;
  float		speed;
  char		*input;
  sfTcpSocket	**sockets;
}		t_all;

void		display(t_window *window, t_hive *hive, t_all *all);

sfTcpSocket	**init_sockets_server(void);

int		listener(t_all *all);

void		my_draw_line(sfUint8 *pixels, sfVector2f from,
			  sfVector2f to, sfColor color);

int		draw_tunnels(t_all *all, t_window *window);

int		move_ants(t_all *all);

t_all		*parse(char **tab);

int             take_tunnels(char **tab, t_all *all);

int		count_int(char **tab, const char *s);

int		count_tab(char **tab);

void		free_all(t_all *all, t_window *window,
			 char *input, char **tab);

void		free_hive(t_hive *hive);

int		server_mode(t_window *window, t_all *all, t_hive *hive);

int		client_mode(t_window *window,
			    sfIpAddress addr, t_hive *hive);

t_hive		*hive_ants_sprites(void);

#endif /* !VISUHEX_H_ */
