/*
** my_puterror.c for asm in /home/Vatoth/Epitech/CPE_2016_corewar
** 
** Made by Quentin Sonnefraud
** Login   <quentin.sonnefraud@epitech.eu>
** 
** Started on  Sun Apr  2 14:31:25 2017 Quentin Sonnefraud
** Last update Sun Apr  2 14:47:01 2017 Quentin Sonnefraud
*/

#include <unistd.h>

void	my_puterror(char *s)
{
  int	i;

  i = 0;
  while (s[i])
    i++;
  write(2, s, i);
}

static void	my_puterror_char(char c)
{
  write(2, &c, 1);
}

int     my_puterror_nbr(int nb)
{
  int	modulo;

  if (nb < 0)
    {
      write(2, "-", 1);
      nb = nb * -1;
    }
  if (nb == 0)
    {
      write(2, "0", 1);
      return (0);
    }
  if (nb > 0)
    {
      if (nb > 9)
        {
          modulo = nb % 10;
          nb = (nb - modulo) / 10;
          my_puterror_nbr(nb);
          my_puterror_char(48 + modulo);
        }
      else
        my_puterror_char(nb + 48);
    }
  return (0);
}
