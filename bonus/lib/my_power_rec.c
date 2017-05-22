/*
** my_power_rec.c for my_power_rec in /home/lblanchard/CPool_Day05
**
** Made by Leandre Blanchard
** Login   <lblanchard@epitech.net>
**
** Started on  Fri Oct  7 10:30:20 2016 Leandre Blanchard
** Last update Mon Feb 20 17:06:29 2017 Léandre Blanchard
*/

int	my_power_rec(int nb, int power)
{
  int	result;

  if (power == 0)
    return (1);
  else if (power < 0)
    return (0);
  else if (power > 1)
    {
      result = my_power_rec(nb, power - 1) * nb;
      if (result < 0)
	return (0);
      else
	return (result);
    }
  else
    return nb;
}
