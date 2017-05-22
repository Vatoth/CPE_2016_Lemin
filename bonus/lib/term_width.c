/*
** term_width.c for term_width in /home/leandre/libmy
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Sat Mar 25 20:29:10 2017 Léandre Blanchard
** Last update Sat Mar 25 20:29:47 2017 Léandre Blanchard
*/

#include "ncurses.h"

int		term_width()
{
  int		width;

  initscr();
  width = COLS;
  endwin();
  return (width);
}
