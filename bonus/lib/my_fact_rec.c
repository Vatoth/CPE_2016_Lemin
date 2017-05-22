/*
** my_fact_rec.c for my_fact_rec in /home/lblanchard/CPool_Day05
**
** Made by Leandre Blanchard
** Login   <lblanchard@epitech.net>
**
** Started on  Fri Oct  7 09:04:27 2016 Leandre Blanchard
** Last update Tue Oct 11 18:48:14 2016 Leandre Blanchard
*/

int	my_fact_rec(int nb)
{
  if (nb < 0)
    {
      return (0);
    }
  if (nb == 1)
    {
      return (1);
    }
  else
    {
      return (nb * my_fact_rec(nb - 1));
    }
}
