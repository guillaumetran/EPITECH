/*
** blackjack.h for blackjack in /home/tran_-/Documents/rendu/CPE_2015_Blackjack/bonus/include
**
** Made by Guillaume TRAN
** Login   <tran_-@epitech.net>
**
** Started on  Wed Mar 16 16:57:50 2016 Guillaume TRAN
** Last update Mon Mar 28 22:51:14 2016 Guillaume TRAN
*/

#ifndef BLACKJACK_H_
# define BLACKJACK_H_
# define WIN_X		(1284.0)
# define WIN_Y		(770.0)

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "lapin.h"
# include "lapin_enum.h"
# include "sprites.h"

typedef struct		s_bj
{
  t_bunny_window	*win;
  t_bunny_pixelarray	*pix;
  t_bunny_pixelarray	*table;
  t_bunny_pixelarray	*cards;
  t_bunny_pixelarray	*font;
  t_bunny_pixelarray	*stand;
  t_bunny_pixelarray	*hit;
  t_bunny_pixelarray	*gg;
  t_bunny_pixelarray	*loose;
  t_bunny_pixelarray	*out;
  t_bunny_pixelarray	*tie;
  t_bunny_pixelarray	*bj;
  t_bunny_effect	*sound;
  int			players;
  int			player;
  int			card;
  int			nb_pick;
  int			turn;
  int			frame;
  int			money;
  int			mon_check;
  int			ia_play;
  int			*sum;
  int			*as;
  char			*pick;
  char			**hands;
  char			**names;
}			t_bj;

t_bj			*blackjack_start();
t_bunny_response	blackjack_click(t_bunny_event_state	sta,
					t_bunny_mouse_button	but,
					void			*data);
t_bunny_response	blackjack_callback(t_bunny_event_state	sta,
					   t_bunny_keysym	sym,
					   void			*data);
void			my_blit(t_bunny_pixelarray		*out,
				t_bunny_pixelarray		*in,
				t_bunny_position		pos_2);
void			load_card(t_bunny_pixelarray *out,
				  t_bunny_pixelarray *in,
				  int number, int color);
char			*initialize_pick(int cards);
char			**initialize_name(int players, int lenght);
int			*initialize_sum(int players);
int			get_card_value(char);
int			count_as(char *);
void			pick_card(t_bj *, int);

#endif /* !BLACKJACK_H_ */
