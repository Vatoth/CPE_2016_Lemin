/*
** socket.c for visu-hex in /home/leandre/Games/Lemin
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Mon May  1 17:14:38 2017 Léandre Blanchard
** Last update Tue May  2 09:54:08 2017 Léandre Blanchard
*/

#include "visuhex.h"

sfTcpSocket		**init_sockets_server(void)
{
  sfTcpSocket		**sockets;
  int                   i;

  if ((sockets = malloc(sizeof(sfTcpSocket *) * MAX_PLAYERS)) == NULL)
    return (NULL);
  sockets[MAX_PLAYERS - 1] = NULL;
  i = 0;
  my_printf("%sYou are ready :)%s\n", BOLDGREEN, RESET);
  while (i < MAX_PLAYERS - 1)
    {
      if ((sockets[i] = sfTcpSocket_create()) == NULL)
	return (NULL);
      sfTcpSocket_setBlocking(sockets[i], sfFalse);
      i++;
    }
  return (sockets);
}

int			listener(t_all *all)
{
  sfTcpListener         *listener;
  int			len;
  size_t		size;
  int                   i;

  len = my_strlen(all->input) + 1;
  i = 0;
  if ((listener = sfTcpListener_create()) == NULL)
    return (-1);
  my_printf(BOLDRED);
  if (sfTcpListener_listen(listener, PORT) == sfSocketError)
    {
      sfTcpListener_destroy(listener);
      return (-1);
    }
  my_printf(RESET);
  while (i < MAX_PLAYERS - 1)
    {
      if (sfTcpListener_accept(listener, &all->sockets[i]) == sfSocketDone)
	{
	  sfTcpSocket_setBlocking(all->sockets[i], sfFalse);
	  my_printf("%s%d Players connected\n%s", BOLDGREEN, i + 2, RESET);
	  sfTcpSocket_sendPartial(all->sockets[i], &len, 4, &size);
	  sfTcpSocket_sendPartial(all->sockets[i], all->input, len - 1, &size);
	  i++;
	}
    }
  sfTcpListener_destroy(listener);
  return (0);
}
