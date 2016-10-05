/*
** my_print_combn_v2.c for my_print_combn in /home/tran/Documents/rendu/EPITECH/tek1/Piscine
**
** Made by Guillaume TRAN
** Login   <tran@epitech.net>
**
** Started on  Wed Oct  5 23:50:35 2016 Guillaume TRAN
** Last update Thu Oct  6 00:06:23 2016 Guillaume TRAN
*/

#include <stdio.h>
#include <stdlib.h>

int	unity(int num, int pow)
{
  int	res;
  int	count;

  if (pow == 0)
    return (1);
  res = num;
  count = 0;
  while (count < pow - 1)
    {
      res *= num;
      count++;
    }
  return (res);
}

int	init_number(int n)
{
  int	number;
  int	count;

  number = 0;
  count = 0;
  n--;
  while (n - count > 0)
    {
      number += (n - count) * unity(10, count);
      count++;
    }
  return (number);
}

void	print_num(int num, int n)
{
  int	count;
  int	tmp;

  count = 0;
  while (count < n)
    {
      tmp = num / unity(10, n - 1 - count) % 10;
      printf("%d", tmp);
      count++;
    }
  printf(", ");
}

int	check_num(int num, int n)
{
  int	save;
  int	tmp;

  save = num;
  tmp = num % 10;
  if (n != 1 && num < unity(10, n - 2))
    return (1);
  while (save / 10 != 0)
    {
      save /= 10;
      if (tmp > save % 10)
	tmp = save % 10;
      else
	return (1);
    }
  return (0);
}

int	my_print_combn(int n)
{
  int	count;

  if (n > 10 || n == 0)
    return (1);
  count = init_number(n);
  if (n == 10)
    {
      print_num(count, n);
      return (0);
    }
  while (count / unity(10, n - 1) <= (10 - n))
    {
      if (check_num(count, n) == 0)
	print_num(count, n);
      count++;
    }
  return (0);
}
