/*
** my_power_it.rec for my_power_rec in /home/lblanchard/CPool_Day05
**
** Made by Leandre Blanchard
** Login   <lblanchard@epitech.net>
**
** Started on  Fri Oct  7 10:30:20 2016 Leandre Blanchard
** Last update Fri Oct  7 13:34:23 2016 Leandre Blanchard
*/

int	my_power_rec(int nb, int p)
{
  int power;

  if (p == 0)
    {
      power = 1;
    }
  else
    {
      power = nb * my_power_rec(nb, p - 1);
    }
  return (power);
}
