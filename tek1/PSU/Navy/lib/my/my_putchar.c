/*
** my_putchar.c for my_putchar in /home/tran_-/Documents/rendu/PSU_2015_my_printf_bootstrap
**
** Made by Guillaume TRAN
** Login   <tran_-@epitech.net>
**
** Started on  Wed Nov  4 16:41:00 2015 Guillaume TRAN
** Last update Wed Nov  4 19:14:57 2015 Guillaume TRAN
*/
#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}
