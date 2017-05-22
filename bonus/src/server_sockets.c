/*
** server_sockets.h for server_socket in /home/leandre/Prog_elem/CPE_2016_Lemin/bonus
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Fri Apr 28 15:42:57 2017 Léandre Blanchard
** Last update Tue May  2 10:02:39 2017 Léandre Blanchard
*/

#include "visuhex.h"

void			display(t_window *window, t_hive *hive, t_all *all)
{
  static int		a;
  int			i;

  i = 0;
  put_sprite(window, hive->background, xy_vectorf(0, 0));
  while (i < all->nb_room)
    {
      put_sprite(window, hive->room, xy_vectorf(all->rooms[i].pos.x * 10,
						all->rooms[i].pos.y * 5));
      if (i != all->start && i != all->end)
	put_word(all->rooms[i].name, xy_vectorf(all->rooms[i].pos.x * 10 + 70,
						all->rooms[i].pos.y * 5 + 10),
		                                window, sfWhite);
      i++;
    }
  i = 0;
  while (i < all->nb_ants)
    {
      put_sprite(window, hive->ants[(a / 100) % 4],
		 xy_vectorf(all->ants[i].pos.x * 10 + 48,
			    all->ants[i].pos.y * 5 + 32));
      put_number(i + 1, xy_vectorf(all->ants[i].pos.x * 10 + 48,
			       all->ants[i].pos.y * 5 + 32), window,
		               sfWhite);
      i++;
    }
  put_word("START", XYF(all->rooms[all->start].pos.x * 10 + 30,
			all->rooms[all->start].pos.y * 5 + 10), window, sfWhite);
  put_word("END", XYF(all->rooms[all->end].pos.x * 10 + 50,
		      all->rooms[all->end].pos.y * 5 + 10), window, sfWhite);
  a++;
}

static int		before_start(t_window *window)
{
  sfIpAddress		addr;
  t_sprite		*background;
  t_sprite		*clouds;
  int			a;

  if ((background = create_sprite("sprites/plains.png")) == NULL ||
      (clouds = create_sprite("sprites/clouds.png")) == NULL)
    return (-1);
  addr = sfIpAddress_getLocalAddress();
  while (sfRenderWindow_isOpen(window->window) && !KP(sfKeyRight))
    {
      window_clear(window);
      close_win(window);
      put_sprite(window, clouds, xy_vectorf(-a / 10, 0));
      put_sprite(window, clouds, xy_vectorf(1280 - a / 10, 0));
      put_sprite(window, background, xy_vectorf(0, 0));
      put_word(addr.address, xy_vectorf(20, 20), window, sfBlack);
      put_word("4 players connected ?\n Press Enter to start",
	       xy_vectorf(W_2, H_2), window, sfBlack);
      window_refresh(window);
      a = (a + 1) % (1280 * 10);
    }
  free_sprite(background);
  free_sprite(clouds);
  return (0);
}

int			server_mode(t_window *window, t_all *all, t_hive *hive)
{
  sfThread		*thread;
  sfThread		*moves;

  if ((all->sockets = init_sockets_server()) == NULL)
    return (-1);
  thread = sfThread_create((void *)listener, (void *)all);
  moves = sfThread_create((void *)move_ants, (void *)all);
  sfThread_launch(thread);
  if (before_start(window) == -1)
    return (-1);
  sfThread_launch(moves);
  while (sfRenderWindow_isOpen(window->window))
    {
      window_clear(window);
      draw_tunnels(all, window);
      display(window, hive, all);
      close_win(window);
      window_refresh(window);
    }
  free_thread(thread);
  free_thread(moves);
  return (0);
}
