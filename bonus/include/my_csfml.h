/*
** csfml.h for csfml_h_lib in /home/leandre/Rushs/scroller/lib/CSFML
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Fri Mar 31 13:58:23 2017 Léandre Blanchard
** Last update Sun Apr 30 17:31:14 2017 Léandre Blanchard
*/

#ifndef MY_CSFML_H_
# define MY_CSFML_H_

# include <SFML/Audio.h>
# include <SFML/Network.h>
# include <SFML/Graphics.h>
# include <SFML/System.h>
# include <SFML/Window.h>

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stddef.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <time.h>
# include <termios.h>
# include <curses.h>
# include <dirent.h>

# include "my.h"

# define KP(key) sfKeyboard_isKeyPressed(key)

typedef struct		s_window
{
  int			width;
  int			height;
  sfVector2i		mouse;
  sfEvent		event;
  sfRenderWindow	*window;
  sfUint8		*pixels;
  char			*font;
  sfMusic		*music;
  sfTexture		*texture;
  sfSprite		*sprite;
}			t_window;

typedef struct		s_sprite
{
  sfSprite		*sprite;
  sfTexture		*texture;
}			t_sprite;

typedef t_window t_win;

void		free_sprite(t_sprite *sprite);

void		free_sprites_only(t_sprite **sprites);

void		free_thread(sfThread *thread);

void		free_window(t_window *window);

void		free_sprites(t_sprite **sprites);

t_sprite	**create_sprites(int nb);

int		is_in_rect(t_window *window, sfVector2f origin, sfVector2f size);

void		window_clear(t_window *window);

int		key_released(int key);

void		window_refresh(t_window *window);

void		put_sprite(t_window *window, t_sprite *sprite, sfVector2f pos);

void		put_sprite_resize(t_window *window, t_sprite *sprite,
				  sfVector2f pos, sfVector2f resize);

void		close_win(t_window *window);

sfVector2i	xy_vectori(int x, int y);

sfVector2f      xy_vectorf(float x, float y);

sfVector3f      xyz_vector(float x, float y, float z);

sfVector2i	pos_mouse(t_window *window);

void		put_square(sfVector2i pos, sfColor color,
			   t_window *window, int size);

void		draw_circle(t_window *window, sfVector2f pos,
			    int size, sfColor color);

void            put_png_resize(t_window *window, sfVector2f pos,
			       char *name, sfVector2f resize);

void            put_png(t_window *window, sfVector2f pos, char *name);

int             my_put_pixel(t_window *window, int x, int y, sfColor color);

void		clear_white(t_window *window);

void		put_word(char *word, sfVector2f pos,
			 t_window *window, sfColor color);

void            put_number(int nb, sfVector2f pos,
			   t_window *window, sfColor color);

void		init_window(t_window *window, char *name);

t_sprite	*create_sprite(const char *pathname);

#endif /* !MY_CSFML_H_ */
