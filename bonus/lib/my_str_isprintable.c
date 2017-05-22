/*
** my_str_isprintable.c for my_str_isprintable in /home/lblanchard/CPool_Day06
** 
** Made by Leandre Blanchard
** Login   <lblanchard@epitech.net>
** 
** Started on  Mon Oct 10 15:34:34 2016 Leandre Blanchard
** Last update Mon Oct 10 15:41:22 2016 Leandre Blanchard
*/

int	my_str_isprintable(char *str)
{
  int	i;
  int	j;

  j = 0;
  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] <= 31 && str[i] >= 0)
	{
	  j = j + 1;
	}
      i = i + 1;
    }
  if (j == 0 || i == 0)
    {
      return '1';
    }
  else
    {
      return '0';
    }
}
