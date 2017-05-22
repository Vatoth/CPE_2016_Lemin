/*
** free.c for my_csfml in /home/leandre/C_graphical_prog/tekadventure
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Wed Apr  5 14:48:58 2017 Léandre Blanchard
** Last update Mon Apr 24 11:41:16 2017 Léandre Blanchard
*/

#include "csfml.h"

void		free_sprites_only(t_sprite **sprites)
{
  int		i;

  i = 0;
  if (sprites != NULL)
    {
      sfTexture_destroy(sprites[0]->texture);
      while (sprites[i] != NULL)
	{
	  if (sprites[i]->sprite != NULL)
	    sfSprite_destroy(sprites[i]->sprite);
	  free(sprites[i++]);
	}
      free(sprites);
    }
}

void		free_sprites(t_sprite **sprites)
{
  int		i;

  i = 0;
  if (sprites != NULL)
    {
      while (sprites[i] != NULL)
	{
	  free_sprite(sprites[i]);
	  i++;
	}
      free(sprites);
    }
}

void            free_sprite(t_sprite *sprite)
{
  if (sprite != NULL)
    {
      if (sprite->sprite != NULL)
	sfSprite_destroy(sprite->sprite);
      if (sprite->texture != NULL)
	sfTexture_destroy(sprite->texture);
      free(sprite);
    }
}

void            free_window(t_window *window)
{
  if (window != NULL)
    {
      if (window->window != NULL)
	sfRenderWindow_destroy(window->window);
      if (window->pixels != NULL)
	free(window->pixels);
      if (window->font != NULL)
	free(window->font);
      if (window->music != NULL)
	sfMusic_destroy(window->music);
      if (window->texture != NULL)
	sfTexture_destroy(window->texture);
      if (window->sprite != NULL)
	sfSprite_destroy(window->sprite);
      free(window);
    }
}

void		free_thread(sfThread *thread)
{
  sfThread_terminate(thread);
  sfThread_destroy(thread);
}
