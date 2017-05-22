/*
** my_strcapitalize.c for my_strcapitalize in /home/lblanchard/CPool_Day06
** 
** Made by Leandre Blanchard
** Login   <lblanchard@epitech.net>
** 
** Started on  Mon Oct 10 14:35:55 2016 Leandre Blanchard
** Last update Mon Oct 10 14:52:17 2016 Leandre Blanchard
*/

char	*my_strcapitalize(char *str)
{
  int	i;

  i = 0;
  while (i != '\0')
    {
      if (str[0] <= 'z' && str[0] >= 'a')
	{
	  str[0] = str[0] - 32;
	}
      if (str[i] == ' ' && str[i + 1] <= 'z' && str[i + 1] >= 'a')
	{
	  i = i + 1;
	  str[i] = str[i] - 32;
	  i = i + 1;
	}
    }
  return str;
}
