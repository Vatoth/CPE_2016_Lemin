/*
** test-.c for test.task in /home/lblanchard/CPool_Day04
** 
** Made by Leandre Blanchard
** Login   <lblanchard@epitech.net>
** 
** Started on  Thu Oct  6 08:49:06 2016 Leandre Blanchard
** Last update Sat Oct  8 01:04:09 2016 Leandre Blanchard
*/

int	my_swap(int *a, int *b)
{
  int	c;

  c = *a;
  *a = *b;
  *b = c;
  return (0);
}
