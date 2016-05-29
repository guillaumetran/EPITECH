/*
** blackjack_button.c for blackjack in /home/tran_-/Documents/rendu/CPE_2015_Blackjack/bonus/src
**
** Made by Guillaume TRAN
** Login   <tran_-@epitech.net>
**
** Started on  Thu Mar 17 23:05:02 2016 Guillaume TRAN
** Last update Mon Mar 28 22:12:54 2016 Guillaume TRAN
*/

#include "blackjack.h"

void		tekpixel(t_bunny_pixelarray *pix, t_bunny_position pos,
			 unsigned int color)
{
  t_color	*array;

  array = pix->pixels;
  array[pos.x + (pos.y * pix->clipable.clip_width)].full = color;
}

void		my_button(t_bj *game)
{
  t_bunny_pixelarray	*but;
  t_bunny_position	pos;
  t_bunny_position	pos2;

  pos2.x = 0;
  pos2.y = 0;
  pos.x = 540;
  pos.y = 640;
  but = bunny_new_pixelarray(128, 128);
  reset_pix(but, game->pix, pos);
  my_blit(but, game->hit, pos2);
  bunny_blit(&game->win->buffer, &but->clipable, &pos);
  pos.x = 708;
  reset_pix(but, game->pix, pos);
  my_blit(but, game->stand, pos2);
  bunny_blit(&game->win->buffer, &but->clipable, &pos);
  bunny_delete_clipable(&but->clipable);
}
