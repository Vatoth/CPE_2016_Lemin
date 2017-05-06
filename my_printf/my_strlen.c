/*
** my_strlen.c for my_strlen in /home/Vatoth/CPool_Day04
** 
** Made by Quentin Sonnefraud
** Login   <Vatoth@epitech.net>
** 
** Started on  Thu Oct  6 21:15:15 2016 Quentin Sonnefraud
** Last update Mon Mar  6 16:28:43 2017 Vatoth
*/

int     my_strlen(const char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}
