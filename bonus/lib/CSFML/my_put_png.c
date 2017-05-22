/*
** my_put_png.c for put_png in /home/leandre/Rushs/scroller/lib/CSFML
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Fri Mar 31 13:56:53 2017 Léandre Blanchard
** Last update Fri Mar 31 13:57:11 2017 Léandre Blanchard
*/

#include "csfml.h"

void            put_png(t_window *window, sfVector2f pos, char *name)
{
  sfSprite      *sprite;
  sfTexture     *texture;

  texture = sfTexture_createFromFile(name, NULL);
  sprite = sfSprite_create();
  sfSprite_setTexture(sprite, texture, sfTrue);
  sfSprite_setPosition(sprite, pos);
  sfRenderWindow_drawSprite(window->window, sprite, NULL);
  sfSprite_destroy(sprite);
  sfTexture_destroy(texture);
}

void            put_png_resize(t_window *window, sfVector2f pos,
			       char *name, sfVector2f resize)
{
  sfSprite      *sprite;
  sfTexture     *texture;

  texture = sfTexture_createFromFile(name, NULL);
  sprite = sfSprite_create();
  sfSprite_setTexture(sprite, texture, sfTrue);
  sfSprite_setScale(sprite, resize);
  sfSprite_setPosition(sprite, pos);
  sfRenderWindow_drawSprite(window->window, sprite, NULL);
  sfSprite_destroy(sprite);
  sfTexture_destroy(texture);
}
