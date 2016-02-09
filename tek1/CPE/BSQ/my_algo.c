/*
** my_algo.c for my_algo in /home/tran_-/Documents/rendu/CPE_2015_BSQ
**
** Made by Guillaume TRAN
** Login   <tran_-@epitech.net>
**
** Started on  Mon Dec 21 18:24:59 2015 Guillaume TRAN
** Last update Tue Dec 22 20:31:46 2015 Guillaume TRAN
*/

void	fill_border(int **map, int length, int width)
{
  int	i;

  i = 0;
  while (i < width)
    {
      if (map[0][i] == 'o')
	map[0][i] = 0;
      else
	map[0][i] = 1;
      i++;
    }
  i = 0;
  while (i < length)
    {
      if (map[i][0] == 'o' || map[i][0] == 0)
	map[i][0] = 0;
      else
	map[i][0] = 1;
      i++;
    }
}

void	get_min(int i, int j, int *min, int **map)
{
  int	a;
  int	b;
  int	c;

  a = map[i][j-1];
  b = map[i-1][j];
  c = map[i-1][j-1];
  if (a <= b && a <= c)
    {
      min[0] = i;
      min[1] = j-1;
    }
  else if (b <= a && b <= c)
    {
      min[0] = i-1;
      min[1] = j;
    }
  else if (c <= a && c <= b)
    {
      min[0] = i-1;
      min[1] = j-1;
    }
}

void	replace_map(int **map, int length, int width, int max[3])
{
  int	i;
  int	j;

  i = 0;
  max[2] = 0;
  while (i < length)
    {
      j = 0;
      while (j < width)
	{
	  if (map[i][j] > max[2])
	    {
	      max[2] = map[i][j];
	      max[0] = i;
	      max[1] = j;
	    }
	  if (map[i][j] == 0)
	    map[i][j] = 'o';
	  else
	    map[i][j] = '.';
	  j++;
	}
      i++;
    }
}

void	place_square(int max[3], int **map)
{
  int	size;
  int	i;
  int	j;

  i = 0;
  size = max[2];
  while (i < size)
    {
      j = 0;
      while (j < size)
	{
	  map[max[0]-i][max[1]-j] = 'x';
	  j++;
	}
      i++;
    }
}

void	my_algo(int **map, int length, int width)
{
  int	i;
  int	j;
  int	min[2];

  i = 1;
  while (i < length)
    {
      j = 1;
      while (j < width)
	{
	  if (map[i][j] == 'o')
	    map[i][j] = 0;
	  else
	    {
	      get_min(i, j, min, map);
	      map[i][j] = map[min[0]][min[1]] + 1;
	    }
	  j++;
	}
      i++;
    }
}
