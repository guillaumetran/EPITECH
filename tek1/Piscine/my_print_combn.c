/*
** my_print_combn.c for my_print_combn in /home/tran/Documents/rendu/EPITECH/tek1/Piscine
**
** Made by Guillaume TRAN
** Login   <tran@epitech.net>
**
** Started on  Wed Oct  5 23:01:30 2016 Guillaume TRAN
** Last update Thu Oct  6 00:08:44 2016 Guillaume TRAN
*/

#include <stdio.h>

void clean_tab(int n, int *tab)
{
  int count;

  count = 1;
  while (count < n)
    {
      if (tab[n - count] == (11 - count))
	{
	  tab[n - count - 1]++;
	  tab[n - count] = tab[n - count - 1] + 1;
	}
      count++;
    }
  count = 1;
  while (count < n)
    {
      if (tab[count] == (11 - (n - count)))
	tab[count] = tab[count - 1] + 1;
      count++;
    }
}

void init_tab(int n, int *tab)
{
  int count;

  count = 0;
  while (count < n)
    {
      tab[count] = count;
      count++;
    }
}

void print_tab(int n, int *tab, int end)
{
  int count;

  count = 0;
  while (count < n)
    {
      printf("%d", tab[count]);
      count++;
    }
  if (end == 0)
    printf(", ");
}

int	check_end(int n, int *tab)
{
  int	count;

  count = 0;
  while (count < n)
    {
      if (tab[count] >= 10 - (n - count))
	count++;
      else
	return (1);
    }
  return (0);
}

int	my_print_combn(int n)
{
  int	tab[n + 1];

  n++;
  init_tab(n, tab);
  while (check_end(n, tab) != 0)
    {
      while (tab[n - 1] <= 9)
	{
	  if (n == 1 && tab[0] == 9)
	    {
	      print_tab(n, tab, 1);
	      return (0);
	    }
	  print_tab(n, tab, 0);
	  tab[n - 1]++;
	}
      clean_tab(n, tab);
    }
  print_tab(n, tab, 1);
  return (0);
}
