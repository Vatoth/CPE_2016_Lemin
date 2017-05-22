/*
** my_get_float.c for get_float in /home/leandre/libmy
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Wed Mar 15 19:45:53 2017 Léandre Blanchard
** Last update Wed Mar 15 20:29:34 2017 Léandre Blanchard
*/

float		get_int_part(char *str)
{
  float		nb;
  int		i;

  i = 0;
  nb = 0;
  if (str[0] == '-')
    i++;
  while (str[i] >= '0' && str[i] <= '9'
	 && str[i] != '.' && str[i] != 0)
    {
      nb *= 10;
      nb += (str[i] - 48);
      i++;
    }
  if (str[0] == '-')
    nb *= (-1);
  return (nb);
}

float		my_get_float(char *str)
{
  float		nb;
  int		i;
  int		mod;

  i = 0;
  mod = 10;
  nb += get_int_part(str);
  while (str[i] != 0 && str[i] != '.')
    i++;
  if (str[i] == '.')
    i++;
  while (str[i] != 0)
    {
      nb += (str[i] - 48) / (float)mod;
      i++;
      mod *= 10;
    }
  return (nb);
}
