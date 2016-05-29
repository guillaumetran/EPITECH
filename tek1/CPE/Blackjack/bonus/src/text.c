/*
** text.c for blackjack in /home/tran_-/Documents/rendu/CPE_2015_Blackjack/bonus/src
**
** Made by Guillaume TRAN
** Login   <tran_-@epitech.net>
**
** Started on  Thu Mar 24 16:13:47 2016 Guillaume TRAN
** Last update Mon Mar 28 21:25:34 2016 Guillaume TRAN
*/

#include "blackjack.h"

void			load_letter(t_bunny_pixelarray *out,
				    t_bunny_pixelarray *in,
				    t_bunny_position pos_3,
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
  while (pos.y < sprites->height && !(pos.x = 0))
    {
      pos_2.x = sprites->state * sprites->width;
      while (pos.x < sprites->width)
	{
	  w = ((pos_2.x + in->clipable.clip_x_position) +
	       (pos_2.y * in->clipable.clip_width));
	  if (font[w].full != 0)
	    array[(pos.x + pos_3.x) +
		  ((pos.y +  pos_3.y) * out->clipable.clip_width)].full = font[w].full;
	  pos.x++ + pos_2.x++;
	}
      pos.y++ + pos_2.y++;
    }
}

void	get_txt_pos_two(t_bunny_position *pos, int player)
{
  if (player == 3)
    {
      pos->x = 300;
      pos->y = 450;
    }
  if (player == 4)
    {
      pos->x = 50;
      pos->y = 390;
    }
  if (player == 5)
    {
      pos->x = 520;
      pos->y = 230;
    }
}

void	get_txt_pos(t_bj *game, t_bunny_position *pos, int player)
{
  if (player == 0)
    {
      pos->x = 1050;
      pos->y = 400;
    }
  if (player == 1)
    {
      pos->x = 790;
      pos->y = 450;
    }
  if (player == 2)
    {
      pos->x = 540;
      pos->y = 500;
    }
  get_txt_pos_two(pos, player);
}

void			my_txt(t_bj *game, int nb, int player)
{
  t_bunny_position	pos;
  t_bunny_position	pos_t;
  t_bunny_pixelarray	*chiffre;
  t_sprites		sprites;

  chiffre = bunny_new_pixelarray(15, 30);
  pos_t.x = 0;
  pos_t.y = 0;
  get_txt_pos(game, &pos, player);
  sprites.width = 15;
  sprites.height = 30;
  sprites.line = 0;
  if ((sprites.state = nb / 10) != 0)
    {
      reset_pix(chiffre, game->pix, pos);
      load_letter(chiffre, game->font, pos_t, &sprites);
      bunny_blit(&game->win->buffer, &chiffre->clipable, &pos);
    }
  sprites.state = nb % 10;
  pos.x += 30;
  reset_pix(chiffre, game->pix, pos);
  load_letter(chiffre, game->font, pos_t, &sprites);
  bunny_blit(&game->win->buffer, &chiffre->clipable, &pos);
  bunny_delete_clipable(&chiffre->clipable);
}
