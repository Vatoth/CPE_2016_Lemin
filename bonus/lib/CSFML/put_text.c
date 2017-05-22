
/*
** put_text.c for  in /home/leandre/Rushs/scroller/lib/CSFML
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Fri Mar 31 14:08:05 2017 Léandre Blanchard
** Last update Mon May  1 17:42:35 2017 Léandre Blanchard
*/

#include "csfml.h"

void            put_word(char *word, sfVector2f pos,
			 t_window *window, sfColor color)
{
  sfFont        *font;
  sfText        *text;

  if (window->font != NULL)
    {
      font = sfFont_createFromFile(window->font);
      text = sfText_create();
      sfText_setString(text, word);
      sfText_setFont(text, font);
      sfText_setColor(text, color);
      sfText_setCharacterSize(text, 30);
      sfText_setPosition(text, pos);
      sfRenderWindow_drawText(window->window, text, NULL);
      sfText_destroy(text);
      sfFont_destroy(font);
    }
}

void            put_number(int nb, sfVector2f pos,
			   t_window *window, sfColor color)
{
  char          *str;

  if (nb != 0)
    {
      str = int_char(nb);
      put_word(str, pos, window, color);
      free(str);
    }
  else
    put_word("0", pos, window, color);
}
