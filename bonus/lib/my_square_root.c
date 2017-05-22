/*
** my_square_root.c for my_square_root in /home/lblanchard/CPool_Day05
**
** Made by Leandre Blanchard
** Login   <lblanchard@epitech.net>
**
** Started on  Fri Oct  7 12:52:37 2016 Leandre Blanchard
** Last update Fri Oct  7 13:32:09 2016 Leandre Blanchard
*/

int	my_square_root(int nb)
{
  int	i;

  i = 0;
  while (i * i != nb && i * i <= nb)
    {
      i = i + 1;
    }
  if (i * i >= nb)
    {
      return (0);
    }
  else
    {
      return (i);
    }
}
