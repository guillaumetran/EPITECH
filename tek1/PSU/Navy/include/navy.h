/*
** navy.h for navy.h in /home/tran_-/Documents/rendu/PSU_2015_navy
**
** Made by Guillaume TRAN
** Login   <tran_-@epitech.net>
**
** Started on  Thu Dec 10 20:39:56 2015 Guillaume TRAN
** Last update Mon Dec 21 23:36:30 2015 Guillaume TRAN
*/

#ifndef NAVY_H_
# define NAVY_H_

typedef struct  s_info
{
  int           pid_enemy;
  int           finish;
  int           counter;
  int		win;
}               t_info;
t_info          navy;
char		**my_fill_grid(char **grid);
char		**my_initialize_grid();
void		display_line(int number, char **grid);
void		my_display(char **grid);
int		case_one(int *coord, char **grid, char c);
int		case_two(int *coord, char **grid, char c);
int		put_boat(int *coord, char **grid, char c);
int		place_boat(char **pos, char **grid);
void		start_navy(char **pos);
void		start_navy_enemy(char **pos);
int		connected(char **pos);
int		enemy_connection(char **pos);
int		check_win(char **grid, char **gridenemy);
int		check_loose(char **grid, char **gridenemy);
void		check_result(char **grid, int *coord);
void		hit(int sig);
void		not(int sig);
void		hitornot(char **gridenemy, int *coord);
int		game(char **grid, char **gridenemy);
int		game_enemy(char **grid, char **gridenemy);
int		*convert_to_coord(char *str, int *coord);
void		send_coord(int *coord);
void		function_ok(int sig);
void		function_done(int sig);
int		*receive_coord(int *coord);
void		my_parser(char boat[32], char **pos);
int		my_get_boat(int map, char **pos);
void		check_input_coord(char str[3], int *coord);
void		enemy_ok(int sig);
void		enemy_lost(int sig);
void		enemy_go(char **grid, char **gridenemy, int *coord);
int		player_one_go(char **grid, char **gridenemy, char **pos);

#endif /* !NAVY_H_ */
