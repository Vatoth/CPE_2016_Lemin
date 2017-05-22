/*
** my_is_prime.c for my_is_prime in /home/lblanchard/CPool_Day05
**
** Made by Leandre Blanchard
** Login   <lblanchard@epitech.net>
**
** Started on  Fri Oct  7 11:01:26 2016 Leandre Blanchard
** Last update Fri Oct  7 13:34:00 2016 Leandre Blanchard
*/

int	my_is_prime(int nb)
{
  int	i;

  i = 2;
  while (i < nb)
    {
      if (nb % i == 0 && i != nb)
	{
	  return (0);
	}
      i = i + 1;
    }
  return (1);
}
