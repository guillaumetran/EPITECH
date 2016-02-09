/*
** my.h for my in /home/tran_-/Documents/rendu/PSU_2015_my_printf_bootstrap/include
**
** Made by Guillaume TRAN
** Login   <tran_-@epitech.net>
**
** Started on  Wed Nov  4 11:46:52 2015 Guillaume TRAN
** Last update Thu Dec 10 12:29:10 2015 Guillaume TRAN
*/

#ifndef MY_H_
# define MY_H_
#include <stdarg.h>

int	my_strlen(char *str);
void	my_putstr(char *str);
int	check_for_int(int nb);
void	my_putchar(char c);
int     scan_format(char *format, va_list args);
int     my_printf(char *format, ...);
char	*my_putnbr_base(unsigned long nb, char *base);
int	my_putnbr_basev1(int nb, char *base);
int	my_malloc_basev1(int nb, char *base);
int	my_getnbr(char *str);
int     flag_s(va_list args);
int     flag_o(va_list args);
int     flag_x(va_list args);
int     flag_X(va_list args);
int     flag_b(va_list args);
int     flag_p(va_list args);
int     flag_c(va_list args);
int     flag_d(va_list args);
int     flag_u(va_list args);
int     flag_smaj(va_list args);
int     my_printf(char *format, ...);
int     call_function(int id, va_list args);
int     get_id(int i, char *format);
int     get_type(char *format, va_list args);

#endif /* !MY_H_ */
