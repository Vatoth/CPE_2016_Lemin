/*
** main.c for visu-hex in /home/leandre/Prog_elem/CPE_2016_Lemin/bonus
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Thu Apr 27 00:37:03 2017 Léandre Blanchard
** Last update Tue May  2 10:04:22 2017 Léandre Blanchard
*/

#include "visuhex.h"

static int		usage(void)
{
  my_printf(USAGE_, BOLDWHITE, BOLDGREEN, USAGE_2, RESET);
  return (1);
}

static char		*get_input(int fd)
{
  int			size;
  char			*s;
  char			*prev;
  char			buffer[12];

  size = 10;
  if ((s = my_calloc(size + 2)) == NULL)
    return (NULL);
  zeros(buffer, 12);
  while (read(fd, buffer, 10) > 0)
    {
      prev = s;
      size += 10;
      if ((s = my_catalloc(s, buffer)) == NULL)
	return (NULL);
      free(prev);
      zeros(buffer, 12);
    }
  return (s);
}

static int		micro_error_gest(int ac, char **av)
{
  if (ac < 2)
    return (usage());
  if (my_strcmp(av[1], "-h") == 0)
    return (usage());
  if (ac == 3)
      if (my_strcmp(av[1], "--client") == 0)
	{
	  my_printf("%sClient mode with ip: [%s]\n%s", BOLDGREEN, av[2], RESET);
	  return (2);
	}
  if (ac == 2)
    if (my_strcmp(av[1], "--host") == 0)
      {
	my_printf("%sServer mode enabled\n%s", BOLDGREEN, RESET);
	return (3);
      }
  return (usage());
}

int			start(t_window *window, t_all *all, int todo, char **av)
{
  t_hive		*hive;

  if ((hive = hive_ants_sprites()) == NULL)
    return (-1);
  if (todo == 2)
    client_mode(window, sfIpAddress_fromString(av[2]), hive);
  if (todo == 3)
    server_mode(window, all, hive);
  free_hive(hive);
  return (0);
}

int			main(int ac, char **av)
{
  char			*input;
  char			**tab;
  t_all			*all;
  t_window		*window;
  int			todo;

  if ((todo = micro_error_gest(ac, av)) == 1)
    return (-1);
  if (todo == 3)
    {
      if ((input = get_input(0)) == NULL)
	return (-1);
      if ((tab = my_str_to_wordtab(input, '\n')) == NULL)
	return (-1);
    }
  if ((window = malloc(sizeof(t_win))) == NULL)
    return (-1);
  if ((window->font = my_strdup("fonts/arial.ttf")) == NULL)
    return (-1);
  if ((window->music = sfMusic_createFromFile("musics/lobby.wav")) == NULL)
    return (-1);
  init_window(window, "Lem-in");
  if (todo == 3)
    all = parse(tab);
  all->input = input;
  start(window, all, todo, av);
  if (todo == 3)
    free_all(all, window, input, tab);
  else
    free_window(window);
  return (0);
}
