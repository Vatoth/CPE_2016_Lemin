/*
** my_str_islower.c for my_is_lower in /home/lblanchard/CPool_Day06
** 
** Made by Leandre Blanchard
** Login   <lblanchard@epitech.net>
** 
** Started on  Mon Oct 10 15:27:30 2016 Leandre Blanchard
** Last update Mon Feb 20 17:14:04 2017 Léandre Blanchard
*/

int	my_str_islower(char *str)
{
  int	i;
  int	j;

  j = 0;
  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] <= 'z' && str[i] >= 'a')
	{
	  i = i + 1;
	}
      else
	{
	  i = i + 1;
	  j = j + 1;
	}
    }
  if (j == 0)
    {
      return '1';
    }
  else
    {
      return '0';
    }
}
