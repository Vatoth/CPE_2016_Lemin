/*
** defines.h for visu-hex in /home/leandre/Prog_elem/CPE_2016_Lemin/bonus
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Thu Apr 27 00:43:34 2017 Léandre Blanchard
** Last update Tue May  2 14:05:03 2017 Léandre Blanchard
*/

#ifndef DEFINES_H_
# define DEFINES_H_

# define USAGE_ "%sUSAGE:%s\n\t./lem_in < map | ./visu-hex [--host],\n%s\n%s"
# define USAGE_2 "\t./visu-hex [--client] [Ip Address]"
# define L 5
# define PORT 8886
# define H_ window->height
# define W_ window->width
# define H_2 H_ / 2
# define W_2 W_ / 2
# define MAX_PLAYERS 4
# define UNABLE_CO "%sUnable to connect to <%s>%s\n"
# define SUCCESS_CO "%sSuccessfully connected to <%s>%s\n"
# define XY(x, y) xy_vectori(x, y)
# define XYF(x, y) xy_vectorf(x, y)

#endif /* !DEFINES_H_ */
