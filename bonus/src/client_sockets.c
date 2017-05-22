/*
** server_client.c for visu-hex in /home/leandre/Prog_elem/CPE_2016_Lemin/bonus
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Sun Apr 30 19:02:34 2017 Léandre Blanchard
** Last update Fri May  5 09:56:34 2017 Léandre Blanchard
*/

#include "visuhex.h"

static sfTcpSocket	*connection(sfIpAddress *addr)
{
  sfTcpSocket		*socket;

  if ((socket = sfTcpSocket_create()) == NULL)
    return (NULL);
  if ((sfTcpSocket_connect(socket, *addr, PORT, sfSeconds(5)))
      != sfSocketDone)
    {
      my_printf(UNABLE_CO, BOLDRED, addr->address, RESET);
      return (NULL);
    }
  my_printf(SUCCESS_CO, BOLDGREEN, addr->address, RESET);
  sfTcpSocket_setBlocking(socket, sfFalse);
  return (socket);
}

static char		*receive_file(sfTcpSocket *socket, t_window *window)
{
  int			datas;
  size_t		size;
  char			*input;

  if (sfTcpSocket_receive(socket, &datas, 4, &size) ==
      sfSocketDisconnected)
    {
      sfRenderWindow_close(window->window);
      my_printf("%sHost disconnected\n%s", BOLDRED, RESET);
    }
  my_printf("%d bytes received\n", size);
  if (size != 4)
    return (NULL);
  if ((input = my_calloc(datas)) == NULL)
    return (NULL);
  if (sfTcpSocket_receive(socket, input, datas - 1, &size) ==
      sfSocketDisconnected)
    {
      sfRenderWindow_close(window->window);
      my_printf("%sHost disconnected\n%S", BOLDRED, RESET);
    }
  my_printf("%s\n", input);
  return (input);
}

static t_all		*client_all(t_window *window, sfTcpSocket *socket)
{
  char			*input;
  char			**tab;
  t_all			*all;

  if ((input = receive_file(socket, window)) == NULL)
    return (NULL);
  if ((tab = my_str_to_wordtab(input, '\n')) == NULL)
    return (NULL);
  if ((all = parse(tab)) == NULL)
    return (NULL);
  free(input);
  free_tab(tab);
  return (all);
}

int			client_mode(t_window *window,
				    sfIpAddress addr, t_hive *hive)
{
  sfTcpSocket		*socket;
  sfThread		*thread;
  t_all			*all;

  if ((socket = connection(&addr)) == NULL)
    return (-1);
  if ((all = client_all(window, socket)) == NULL)
    return (-1);
  thread = sfThread_create((void *)move_ants, (void *)all);
  sfThread_launch(thread);
  while (sfRenderWindow_isOpen(window->window))
    {
      window_clear(window);
      draw_tunnels(all, window);
      close_win(window);
      display(window, hive, all);
      window_refresh(window);
    }
  free_thread(thread);
  return (0);
}
