/*
** my_strncmp.c for my_strncmp in /home/lblanchard/CPool_Day06
**
** Made by Leandre Blanchard
** Login   <lblanchard@epitech.net>
**
** Started on  Thu Oct  6 11:19:22 2016 Leandre Blanchard
** Last update Thu Mar 16 14:52:30 2017 Léandre Blanchard
*/

int	my_strncmp(char *s1, char *s2, int n)
{
  int   i;

  i = 0;
  while (s1[i] != 0 && s2[i] != 0 && n != 0)
    {
      if (s1[i] != s2[i])
	return (s1[i] - s2[i]);
      i++;
    }
  return (s1[i - 1] - s2[i - 1]);
}
