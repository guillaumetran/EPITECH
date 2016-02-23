/*
** allum1.h for allum1 in /home/tran_-/Documents/rendu/CPE_2015_Allum1/include
**
** Made by tran_-
** Login   <tran_-@epitech.net>
**
** Started on  Mon Feb  8 12:22:14 2016 tran_-
** Last update Sun Feb 21 22:38:28 2016 Guillaume TRAN
*/

#ifndef ALLUM1_H_
# define ALLUM1_H_
# define _BSD_SOURCE

#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <ncurses.h>
#include "my.h"

typedef struct s_allum
{
  char		**map;
  int		allum;
  int		check_pos;
  int		line_one;
  int		one[4];
  int		line_plus;
  int		plus[4];
  int		line_zero;
  int		width;
  int		height;
  int		selector;
  int		mselector;
  int		status;
}		t_allum;

char	**my_initialize_map(int width, int height);
void	my_fill_map(t_allum *allum);
void	display_map(t_allum *allum);
int	count_line(t_allum *allum, int **lines);
int	check_win(t_allum *allum, int id);
void	remove_allum(t_allum *allum, int line, int match);
void	ia_turn(t_allum *allum);
int	count_allum(t_allum *allum, int line);
void	part_one(t_allum *allum, int key);
int	part_two(t_allum *allum);
void	start_game(char *name);

#endif /* !ALLUM1_H_ */
