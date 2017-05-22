/*
** my_str_isnum.c for my_str_isnum in /home/lblanchard/CPool_Day06
** 
** Made by Leandre Blanchard
** Login   <lblanchard@epitech.net>
** 
** Started on  Mon Oct 10 15:07:36 2016 Leandre Blanchard
** Last update Mon Feb 27 12:23:06 2017 Léandre Blanchard
*/

int	my_str_isnum(char *str, char c)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if ((str[i] < '0' || str[i] > '9') && str[i] != c)
	return (1);
      i++;
    }
  return (0);
}
