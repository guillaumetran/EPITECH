/*
** sokoban.h for sokoban.h in /home/tran_-/Documents/rendu/PSU_2015_my_sokoban/include
**
** Made by Guillaume TRAN
** Login   <tran_-@epitech.net>
**
** Started on  Mon Jan  4 10:33:06 2016 Guillaume TRAN
** Last update Sun Jan 17 15:43:23 2016 Guillaume TRAN
*/

#ifndef SOKOBAN_H_
# define SOKOBAN_H_

#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

typedef struct	s_info
{
  char		**map;
  int		**goal;
  int		**box;
  int		width;
  int		height;
  int		key;
  int		posx;
  int		posy;
  int		pos_player[2];
  int		o;
  int		x;
  int		level;
  int		level_max;
}		t_info;

char	**my_initialize_map(int width, int height);
int	**my_initialize_goal(int width, int height);
int     get_height(int map);
int     get_width(int map);
int     my_sokoban(t_info sokoban, char *filename);
int     game(t_info *sokoban);
int	my_fill_goal(int   **goal, char **map, int width, int height);
int	my_fill_box(int   **box, char **map, int width, int height);
void	display_map(char **map, int length);
int     my_fill_map(char **map, char *filename, int width, int height);
void	move_player(char **map, int coord[2], int key);
void	move_up(char **map, int coord[2]);
void	move_down(char **map, int coord[2]);
void	move_left(char **map, int coord[2]);
void	move_right(char **map, int coord[2]);
int     check_win(int **goal, char **map, int o);
int     check_box(int **box, int **goal, char **map, int x);
int     is_placed(int y, int x, int **goal, int o);
int     is_blocked(int y, int x, char **map);
int     check_map(char **map, int width, int height);
void    replace_goal(int **goal, char **map, int o);
int    find_player(char **map, int width, int height, int coord[2]);
void	game_part_one(t_info *sokoban);
void	start_ncurses(t_info *sokoban);

#endif /* !SOKOBAN_H_ */
