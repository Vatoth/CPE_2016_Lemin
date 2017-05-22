/*
** my_strstr.c for my_strstr in /home/lblanchard/CPool_Day06
**
** Made by Leandre Blanchard
** Login   <lblanchard@epitech.net>
**
** Started on  Thu Oct  6 11:19:22 2016 Leandre Blanchard
** Last update Mon Oct 10 17:50:00 2016 Leandre Blanchard
*/

char	*my_strstr(char *str, char *to_find)
{
  int	i;

  if (str[0] != '\0')
    {
      i = 0;
      while (to_find[i] != '\0')
	{
	  if (to_find[i] != str[i])
	    {
	      return (my_strstr(str + 1, to_find));
	      i = i + 1;
	    }
	}
      return (str);
    }
  else
    {
      return (0);
    }
}
