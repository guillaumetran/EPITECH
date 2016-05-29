/*
** blackjack_money.c for blackjack in /home/tran_-/Documents/rendu/CPE_2015_Blackjack/bonus
**
** Made by Guillaume TRAN
** Login   <tran_-@epitech.net>
**
** Started on  Mon Mar 28 22:27:16 2016 Guillaume TRAN
** Last update Mon Mar 28 23:28:20 2016 Guillaume TRAN
*/

#include "blackjack.h"

void		count_money(t_bj *game)
{
  if (game->mon_check == 0)
    {
      if (game->sum[0] > game->sum[5] && game->sum[0] <= 21)
	game->money += 10;
      else if (game->sum[0] <= 21 && game->sum[5] > 21)
	game->money += 10;
      else if (game->sum[0] > 21)
	game->money -= 10;
      else if (game->sum[0] == 21 && my_strhands(game->hands[0]) == 2)
	game->money += 15;
      else if (game->sum[0] != game->sum[5])
	game->money -= 10;
      game->mon_check = 1;
    }
}

void		print_money(t_bj *game)
{
  t_bunny_position      pos;
  t_bunny_position      pos_t;
  t_bunny_pixelarray    *chiffre;
  t_sprites             sprites;

  chiffre = bunny_new_pixelarray(15, 30);
  pos_t.x = 0;
  pos_t.y = 0;
  pos.x = 1170;
  pos.y = 440;
  sprites.width = 15;
  sprites.height = 30;
  sprites.line = 0;
  if ((sprites.state = game->money / 100) != 0)
    {
      reset_pix(chiffre, game->pix, pos);
      load_letter(chiffre, game->font, pos_t, &sprites);
      bunny_blit(&game->win->buffer, &chiffre->clipable, &pos);
      pos.x += 30;
    }
  if ((sprites.state = game->money / 10) != 0)
    {
      reset_pix(chiffre, game->pix, pos);
      load_letter(chiffre, game->font, pos_t, &sprites);
      bunny_blit(&game->win->buffer, &chiffre->clipable, &pos);
    }
  sprites.state = game->money % 10;
  pos.x += 30;
  reset_pix(chiffre, game->pix, pos);
  load_letter(chiffre, game->font, pos_t, &sprites);
  bunny_blit(&game->win->buffer, &chiffre->clipable, &pos);
  bunny_delete_clipable(&chiffre->clipable);
}
