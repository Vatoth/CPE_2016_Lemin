/*
** get_next_line.h for gnl in /home/leandre/Prog_elem/CPE_2016_getnextline/new
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Mon Apr  3 16:37:24 2017 Léandre Blanchard
** Last update Mon Apr  3 17:01:26 2017 Léandre Blanchard
*/

#ifndef GNL_H_
# define GNL_H_

# include <fcntl.h>

# include "my.h"
# include "colors.h"

typedef struct	s_gnl
{
  int		i;
  int		size;
  char		ch;
  char		*s;
}		t_gnl;

#endif /* !GNL_H_ */
