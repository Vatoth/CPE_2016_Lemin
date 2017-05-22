/*
** sprites.c for visu-hex in /home/leandre/Prog_elem/CPE_2016_Lemin/bonus
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Sun Apr 30 19:49:40 2017 Léandre Blanchard
** Last update Sun Apr 30 20:46:31 2017 Léandre Blanchard
*/

#include "visuhex.h"

static int	fill_ants_sprite(t_sprite **sprites, const char *pathname)
{
  sfTexture	*texture;
  sfVector2i	a;
  int		x;

  x = 0;
  my_printf(BOLDRED);
  if ((texture = sfTexture_createFromFile(pathname, NULL)) == NULL)
    return (-1);
  a = xy_vectori(0, 0);
  while (sprites[x] != NULL)
    {
      sprites[x]->texture = texture;
      sprites[x]->sprite = sfSprite_create();
      sfSprite_setTexture(sprites[x]->sprite, texture, sfTrue);
      sfSprite_setTextureRect(sprites[x]->sprite,
			      (sfIntRect){a.x, a.y, 64, 64});
      a.x += 64;
      if (a.x == 256)
	{
	  a.x = 0;
	  a.y = (a.y + 64) % 256;
	}
      x++;
    }
  return (0);
}

t_hive		*hive_ants_sprites(void)
{
  t_hive	*hive;

  if ((hive = malloc(sizeof(t_hive))) == NULL)
    return (NULL);
  if ((hive->room = create_sprite("sprites/room.png")) == NULL)
    return (NULL);
  if ((hive->ants = create_sprites(16)) == NULL)
    return (NULL);
  if (fill_ants_sprite(hive->ants, "sprites/ant.png") == -1)
    return (NULL);
  if ((hive->background = create_sprite("sprites/hive.png")) == NULL)
    return (NULL);
  return (hive);
}
