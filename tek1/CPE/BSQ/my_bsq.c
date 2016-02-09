/*
** my_bsq.c for my_bsq in /home/tran_-/Documents/rendu/CPE_2015_BSQ
**
** Made by Guillaume TRAN
** Login   <tran_-@epitech.net>
**
** Started on  Mon Dec 21 15:49:14 2015 Guillaume TRAN
** Last update Mon Dec 28 13:42:01 2015 Guillaume TRAN
*/

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "bsq.h"

int	get_length(int map)
{
  char	*length;
  char	*buffer;
  int	result;
  int	i;

  if ((length = malloc(sizeof(*length) * 10)) == NULL)
    return (-1);
  if ((buffer = malloc(sizeof(*buffer) * 10)) == NULL)
    return (-1);
  i = -1;
  while ((read(map, buffer, 1)) && buffer[0] != '\n')
    length[++i] = buffer[0];
  if ((result = my_getnbr(length)) == -1)
    return (-1);
  free(length);
  free(buffer);
  return (result);
}

int	get_width(int map)
{
  char	*width;
  char	*buffer;
  int	result;
  int	i;

  if ((width = malloc(sizeof(*width) * 10000)) == NULL)
    return (-1);
  if ((buffer = malloc(sizeof(*buffer) * 10000)) == NULL)
    return (-1);
  i = -1;
  while ((read(map, buffer, 1)) && buffer[0] != '\n')
    width[++i] = buffer[0];
  free(width);
  free(buffer);
  return (i + 1);
}

int	main(int ac, char **av)
{
  int	length;
  int	width;
  int	fd;
  int	**map;
  int	max[3];

  if ((fd = open(av[1], O_RDONLY)) == -1)
    return (1);
  if ((length = get_length(fd)) == -1)
    return (1);
  width = get_width(fd);
  map = my_initialize_map(width, length);
  if ((my_fill_map(map, av[1], width, length)) == 1)
    return (1);
  if ((check_map(map, length, width)) == -1)
    return (1);
  fill_border(map, length, width);
  my_algo(map, length, width);
  replace_map(map, length, width, max);
  place_square(max, map);
  display_map(map, length, width);
  return (0);
}
