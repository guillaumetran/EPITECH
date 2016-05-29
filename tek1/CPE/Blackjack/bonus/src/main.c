/*
** main.c for Blackjack in /home/tran_-/Documents/rendu/CPE_2015_Blackjack/bonus/src
**
** Made by Guillaume TRAN
** Login   <tran_-@epitech.net>
**
** Started on  Wed Mar 16 16:49:57 2016 Guillaume TRAN
** Last update Mon Mar 28 23:01:12 2016 Guillaume TRAN
*/

#include "blackjack.h"

int		main(int ac, char **av)
{
  t_bj		*game;
  t_bunny_music	*musique;

  musique = bunny_load_music("ressources/music.ogg");
  bunny_sound_play(&musique->sound);
  bunny_sound_loop(&musique->sound, 1);
  if ((game = blackjack_start()) == NULL)
    return (-1);
  srand(time(NULL));
  blackjack_loop(game);
  bunny_sound_stop(&musique->sound);
  bunny_delete_sound(&musique->sound);
  bunny_delete_sound(&game->sound->sound);
  return (ac - ac);
}
