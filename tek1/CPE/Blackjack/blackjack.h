/*
** blackjack.h for Blackjack in /home/tran_-/Documents/rendu/CPE_2015_Blackjack
**
** Made by Guillaume TRAN
** Login   <tran_-@epitech.net>
**
** Started on  Mon Feb 29 13:33:07 2016 Guillaume TRAN
** Last update Sat Mar 26 20:00:21 2016 Pierre Ladenburger
*/

#ifndef BLACKJACK_H_
# define BLACKJACK_H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include "get_next_line.h"
#include "lib/my/lib.h"

typedef struct		s_blackjack
{
  int			ia;
  int			players;
  int			cards;
  int			nb_pick;
  int			*sum;
  int			*as;
  char			*pick;
  char			**hands;
  char			**names;
}			t_blackjack;

int	my_strlen(char *);
void	pick_card(t_blackjack *, int);
void	get_names(t_blackjack *, char *, char *, char *);
void	display_msg(t_blackjack *, int);
int	*initialize_sum(int players);
char	*initialize_pick(int cards);
char	**initialize_name(int players, int);
void	my_puthands(char *str);
void	display_game(t_blackjack *bj, int player);
void	my_putstr(char *str);
int	my_strhands(char *str);
void	my_putchar(char c);
char	*my_strcp(char *str);
void	distribute_cards(t_blackjack *bj);
char	get_card(char *cards);
int	count_as(char *);
int	check_card(char *pick, char card, int  i);
void	winner_is(t_blackjack *bj, int, int, int);

#endif /* !BLACKJACK_H_ */
