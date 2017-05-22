/*
** my_str_isalpha.c for my_str_isalpha.c in /home/lblanchard/CPool_Day06
** 
** Made by Leandre Blanchard
** Login   <lblanchard@epitech.net>
** 
** Started on  Mon Oct 10 14:53:07 2016 Leandre Blanchard
** Last update Mon Oct 10 15:05:30 2016 Leandre Blanchard
*/

int	my_str_isalpha(char *str)
{
  int	i;
  int	j;

  j = 0;
  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] <= 'A' || str[i] >= 'z')
	{
	  if (str[i] <= 'a' && str[i] >= 'Z')
	    {
	      j = j + 1;
	    }
	  j = j + 1;
	}
      i = i + 1;
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
