/*
** movement.c for sokoban in /home/tran_-/Documents/rendu/PSU_2015_my_sokoban
**
** Made by Guillaume TRAN
** Login   <tran_-@epitech.net>
**
** Started on  Wed Jan  6 20:01:03 2016 Guillaume TRAN
** Last update Thu Jan  7 16:35:29 2016 Guillaume TRAN
*/

#include "sokoban.h"
#include "my.h"

void    move_player(char **map, int coord[2], int key)
{
  if (key == KEY_UP)
    move_up(map, coord);
  else if (key == KEY_DOWN)
    move_down(map, coord);
  else if (key == KEY_LEFT)
    move_left(map, coord);
  else if (key == KEY_RIGHT)
    move_right(map, coord);
}

void    move_up(char **map, int coord[2])
{
  if (map[coord[0]-1][coord[1]] == 'X')
    {
      if (map[coord[0]-2][coord[1]] != '#' && map[coord[0]-2][coord[1]] != 'X')
	{
	  map[coord[0]][coord[1]] = ' ';
	  coord[0] -= 1;
	  map[coord[0]][coord[1]] = 'P';
	  map[coord[0]-1][coord[1]] = 'X';
	}
    }
  else if (map[coord[0]-1][coord[1]] != '#')
    {
      map[coord[0]][coord[1]] = ' ';
      coord[0] -= 1;
      map[coord[0]][coord[1]] = 'P';
    }
}

void	move_down(char **map, int coord[2])
{
  if (map[coord[0]+1][coord[1]] == 'X')
    {
      if (map[coord[0]+2][coord[1]] != '#' && map[coord[0]+2][coord[1]] != 'X')
	{
	  map[coord[0]][coord[1]] = ' ';
	  coord[0] += 1;
	  map[coord[0]][coord[1]] = 'P';
	  map[coord[0]+1][coord[1]] = 'X';
	}
    }
  else if (map[coord[0]+1][coord[1]] != '#')
    {
      map[coord[0]][coord[1]] = ' ';
      coord[0] += 1;
      map[coord[0]][coord[1]] = 'P';
    }
}

void	move_left(char **map, int coord[2])
{
  if (map[coord[0]][coord[1]-1] == 'X')
    {
      if (map[coord[0]][coord[1]-2] != '#' && map[coord[0]][coord[1]-2] != 'X')
	{
	  map[coord[0]][coord[1]] = ' ';
	  coord[1] -= 1;
	  map[coord[0]][coord[1]] = 'P';
	  map[coord[0]][coord[1]-1] = 'X';
	}
    }
  else if (map[coord[0]][coord[1]-1] != '#')
    {
      map[coord[0]][coord[1]] = ' ';
      coord[1] -= 1;
      map[coord[0]][coord[1]] = 'P';
    }
}

void	move_right(char **map, int coord[2])
{
  if (map[coord[0]][coord[1]+1] == 'X')
    {
      if (map[coord[0]][coord[1]+2] != '#' && map[coord[0]][coord[1]+2] != 'X')
	{
	  map[coord[0]][coord[1]] = ' ';
	  coord[1] += 1;
	  map[coord[0]][coord[1]] = 'P';
	  map[coord[0]][coord[1]+1] = 'X';
	}
    }
  else if (map[coord[0]][coord[1]+1] != '#')
    {
      map[coord[0]][coord[1]] = ' ';
      coord[1] += 1;
      map[coord[0]][coord[1]] = 'P';
    }
}
