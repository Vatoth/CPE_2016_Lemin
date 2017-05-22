/*
** my_sort_in_tab.c for my_sort_in_tab in /home/lblanchard/CPool_Day04
** 
** Made by Leandre Blanchard
** Login   <lblanchard@epitech.net>
** 
** Started on  Sat Oct  8 01:00:18 2016 Leandre Blanchard
** Last update Tue Oct 11 11:47:24 2016 Leandre Blanchard
*/

void	my_sort_int_tab(int* tab, int size)
{
  int	i;
  int	a;
  int	tiny;
  int	wle;

  i = 0;
  a = 0;
  tiny = 0;
  while (i < size)
    {
      while (a < size)
	{
	  if (tab[i] < tab[tiny])
	    {
	      tiny = a;
	    }
	  a = a + 1;
	}
      wle = tab[i];
      tab[i] = tab[tiny];
      tab[tiny] = wle;
      i = i + 1;
      a = i;
      tiny = i;
    }
}
