/*
** blackjack_start.c for blackjack in /home/tran_-/Documents/rendu/CPE_2015_Blackjack/bonus/src
**
** Made by Guillaume TRAN
** Login   <tran_-@epitech.net>
**
** Started on  Wed Mar 16 17:49:09 2016 Guillaume TRAN
** Last update Mon Mar 28 22:51:58 2016 Guillaume TRAN
*/

#include "blackjack.h"

void			blackjack_initialize(t_bj *game)
{
  game->card = 52;
  game->nb_pick = 0;
  game->turn = 0;
  game->ia_play = 0;
  game->frame = 0;
  game->players = 6;
  game->mon_check = 0;
  game->player = 0;
  game->pick = initialize_pick(game->card);
  game->hands = initialize_name(game->players, 20);
  game->sum = initialize_sum(game->players);
  game->as = initialize_sum(game->players);
}

t_bj			*blackjack_start()
{
  t_bj			*game;
  t_bunny_position	pos;

  if ((game = bunny_malloc(sizeof(t_bj))) == NULL)
    return (NULL);
  if ((game->win = bunny_start(WIN_X, WIN_Y, 0, "Blackjack")) == NULL)
    return (NULL);
  if ((game->pix = bunny_new_pixelarray(WIN_X, WIN_Y)) == NULL)
    return (NULL);
  if ((game->table = bunny_load_pixelarray("ressources/table.png")) == NULL)
    return (NULL);
  if ((game->cards = bunny_load_pixelarray("ressources/cards.png")) == NULL)
    return (NULL);
  if ((game->hit = bunny_load_pixelarray("ressources/hit.png")) == NULL)
    return (NULL);
  if ((game->stand = bunny_load_pixelarray("ressources/stand.png")) == NULL)
    return (NULL);
  if ((game->gg = bunny_load_pixelarray("ressources/win.png")) == NULL)
    return (NULL);
  if ((game->loose = bunny_load_pixelarray("ressources/loose.png")) == NULL)
    return (NULL);
  if ((game->out = bunny_load_pixelarray("ressources/out.png")) == NULL)
    return (NULL);
  if ((game->tie = bunny_load_pixelarray("ressources/tie.png")) == NULL)
    return (NULL);
  if ((game->bj = bunny_load_pixelarray("ressources/bj.png")) == NULL)
    return (NULL);
  if ((game->font = bunny_load_pixelarray("ressources/nb.png")) == NULL)
    return (NULL);
  game->sound = bunny_load_effect("ressources/card.ogg");
  blackjack_initialize(game);
  game->money = 50;
  get_pick(game);
  pos.x = 0;
  pos.y = 0;
  my_blit(game->pix, game->table, pos);
  bunny_blit(&game->win->buffer, &game->pix->clipable, &pos);
  bunny_display(game->win);
  distribute_cards(game);
  return (game);
}
