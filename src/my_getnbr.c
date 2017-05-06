/*
** my_getnbr.c for task06 in /home/TomicNikola/CPool_Day04
**
** Made by Nikola Tomic
** Login   <TomicNikola@epitech.net>
**
** Started on  Thu Oct  6 16:40:17 2016 Nikola Tomic
** Last update Mon Apr 10 16:17:57 2017 
*/

int	my_getnbr(const char *str)
{
  int	var;
  int	inv;
  int	i;

  if (!str)
    return (0);
  inv = 1;
  var = 0;
  i = 0;
  while ((str[i] < 48 || str[i] > 57) && str[i] != 0)
    i = i + 1;
  if (i > 0 && str[i - 1] == 45)
    inv = -1;
  while (str[i] != 0 && str[i] >= '0' && str[i] <= '9')
    {
      var = var * 10;
      var = var + str[i] - 48;
      i = i + 1;
    }
  var = var * inv;
  return (var);
}
