/*
** xy_vect.c for xy_vect in /home/leandre/Rushs/scroller/lib/CSFML
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Fri Mar 31 14:21:49 2017 Léandre Blanchard
** Last update Fri Mar 31 14:22:00 2017 Léandre Blanchard
*/

#include "csfml.h"

sfVector2f      xy_vectorf(float x, float y)
{
  sfVector2f    xy;

  xy.x = x;
  xy.y = y;
  return (xy);
}

sfVector2i      xy_vectori(int x, int y)
{
  sfVector2i    xy;

  xy.x = x;
  xy.y = y;
  return (xy);
}

sfVector3f      xyz_vector(float x, float y, float z)
{
  sfVector3f    xyz;

  xyz.x = x;
  xyz.y = y;
  xyz.z = z;
  return (xyz);
}
