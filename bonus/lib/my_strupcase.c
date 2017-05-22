/*
** my_strupcase.c for my_strupcase in /home/lblanchard/CPool_Day06
** 
** Made by Leandre Blanchard
** Login   <lblanchard@epitech.net>
** 
** Started on  Mon Oct 10 13:31:40 2016 Leandre Blanchard
** Last update Sun Apr 30 17:24:25 2017 Léandre Blanchard
*/

char	*my_strupcase(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] >= 'a' && str[i] <= 'z')
	{
	  str[i] = str[i] - 32;
	}
      i = i + 1;
    }
  return str;
}
