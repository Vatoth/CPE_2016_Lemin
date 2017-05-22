/*
** create_sprite.c for create_sprite in /home/leandre/Rushs/scroller
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Sun Apr  2 12:20:16 2017 Léandre Blanchard
** Last update Sun Apr 30 20:33:11 2017 Léandre Blanchard
*/

#include "csfml.h"
#include "../colors.h"

void			put_sprite(t_window *window, t_sprite *sprite, sfVector2f pos)
{
  sfSprite_setPosition(sprite->sprite, pos);
  sfSprite_setScale(sprite->sprite, xy_vectorf(1, 1));
  sfRenderWindow_drawSprite(window->window, sprite->sprite, NULL);
}

void			put_sprite_resize(t_window *window,
				t_sprite *sprite, sfVector2f pos, sfVector2f resize)
{
  sfSprite_setScale(sprite->sprite, resize);
  sfSprite_setPosition(sprite->sprite, pos);
  sfRenderWindow_drawSprite(window->window, sprite->sprite, NULL);
}

t_sprite		*create_sprite(const char *pathname)
{
  t_sprite		*sprite;

  if ((sprite = malloc(sizeof(t_sprite))) == NULL)
    return (NULL);
  my_printf(BOLDRED);
  if ((sprite->texture = sfTexture_createFromFile(pathname, NULL)) == NULL)
    {
      free(sprite);
      return (NULL);
    }
  my_printf(RESET);
  if ((sprite->sprite = sfSprite_create()) == NULL)
    {
      sfTexture_destroy(sprite->texture);
      free(sprite);
      return (NULL);
    }
  sfSprite_setTexture(sprite->sprite, sprite->texture, sfTrue);
  return (sprite);
}

t_sprite        **create_sprites(int nb)
{
  int           i;
  t_sprite      **sprites;

  i = 0;
  if ((sprites = malloc(sizeof(t_sprite *) * (nb + 1))) == NULL)
    return (NULL);
  while (i < nb)
    if ((sprites[i++] = malloc(sizeof(t_sprite))) == NULL)
      return (NULL);
  sprites[nb] = NULL;
  return (sprites);
}
