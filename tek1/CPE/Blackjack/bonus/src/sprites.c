/*
** sprites.c for sprites in /home/tran_-/Documents/rendu/CPE_2015_Blackjack/bonus/src
**
** Made by Guillaume TRAN
** Login   <tran_-@epitech.net>
**
** Started on  Thu Mar 24 16:08:42 2016 Guillaume TRAN
** Last update Sun Mar 27 20:40:55 2016 Ladenburger Pierre
*/

#include "blackjack.h"

void		reset_pix(t_bunny_pixelarray *pix,
			  t_bunny_pixelarray *ini,
			  t_bunny_position p)
{
  t_color	*array;
  t_color	*ar;
  int		x;
  int		y;
  int		w;
  int		i;

  y = 0;
  array = pix->pixels;
  ar = ini->pixels;
  i = p.x;
  while (y < pix->clipable.clip_height)
    {
      x = 0;
      p.x = i;
      while (x < pix->clipable.clip_width)
	{
	  w = (p.x + (p.y * ini->clipable.clip_width));
	  array[(x + pix->clipable.clip_x_position) +
		(y * pix->clipable.clip_width)].full = ar[w].full;
	  x++;
	  p.x++;
	}
      y++ + ++p.y;
    }
}

void			load_sprites(t_bunny_pixelarray	*out,
				     t_bunny_pixelarray	*in,
				     t_sprites *sprites)
{
  t_bunny_position	pos;
  t_bunny_position	pos_2;
  t_color		*font;
  t_color		*array;
  int			w;

  array = out->pixels;
  font = in->pixels;
  pos.y = 0;
  pos_2.y = sprites->line * sprites->height;
  while (pos.y < out->clipable.clip_height && !(pos.x = 0))
    {
      pos_2.x = sprites->state * sprites->width;
      while (pos.x < out->clipable.clip_width)
	{
	  w = ((pos_2.x + in->clipable.clip_x_position) +
	       (pos_2.y * in->clipable.clip_width));
	  if (font[w].argb[3] > 160)
	    array[pos.x +
		  (pos.y * out->clipable.clip_width)].full = font[w].full;
	  pos.x++ + pos_2.x++;
	}
      pos.y++ + pos_2.y++;
    }
}
