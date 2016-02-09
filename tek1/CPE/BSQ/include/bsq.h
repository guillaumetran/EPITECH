/*
** bsq.h for bsq.h in /home/tran_-/Documents/rendu/CPE_2015_BSQ
**
** Made by Guillaume TRAN
** Login   <tran_-@epitech.net>
**
** Started on  Mon Dec 21 15:04:06 2015 Guillaume TRAN
** Last update Mon Dec 28 13:36:59 2015 Guillaume TRAN
*/

#ifndef BSQ_H_
# define BSQ_H_

int	get_length(int map);
int	get_width(int map);
void	fill_border(int **map, int length, int width);
void	get_min(int i, int j, int *min, int **map);
void	replace_map(int **map, int length, int width, int max[3]);
void	place_square(int max[3], int **map);
void	my_algo(int **map, int length, int width);
int	**my_initialize_map(int width, int length);
int	my_fill_map(int **map, char *filename, int width, int length);
void    display_map(int **map, int length, int width);
int	check_map(int **map, int length, int width);

#endif /* !BSQ_H_ */
