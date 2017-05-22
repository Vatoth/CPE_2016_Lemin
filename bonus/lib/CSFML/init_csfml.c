/*
** init_csfml.c for init_csfml_structs in /home/leandre/Rushs/scroller/lib/CSFML
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Fri Mar 31 14:24:11 2017 Léandre Blanchard
** Last update Fri Mar 31 21:46:56 2017 Léandre Blanchard
*/

#include "csfml.h"

sfRenderWindow          *create_window(char *name, int width, int height)
{
  sfRenderWindow        *window;
  sfVideoMode           mode;

  mode.width = width;
  mode.height = height;
  mode.bitsPerPixel = 32;
  window = sfRenderWindow_create(mode, name, sfResize | sfClose, NULL);
  if (window == NULL)
    return (NULL);
  return (window);
}

sfUint8                 *pixels_buffer(int width, int height)
{
  int                   i;
  sfUint8               *pixels;

  if ((pixels = malloc(4 * width * height)) == NULL)
    return (NULL);
  i = 0;
  while (i != width * height * 4)
    pixels[i++] = 0;
  return (pixels);
}

void                    init_window(t_window *window, char *name)
{
  window->height = 720;
  window->width = window->height * 16 / 9;
  window->window = create_window(name,
				 window->width, window->height);
  window->sprite = sfSprite_create();
  window->texture = sfTexture_create(window->width, window->height);
  sfSprite_setTexture(window->sprite, window->texture, sfTrue);
  window->pixels = pixels_buffer(window->width, window->height);
}

