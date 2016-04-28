/*
** my.h for my in /home/tran_-/Documents/rendu/PSU_2015_my_printf_bootstrap/include
**
** Made by Guillaume TRAN
** Login   <tran_-@epitech.net>
**
** Started on  Wed Nov  4 11:46:52 2015 Guillaume TRAN
** Last update Fri Apr 29 01:00:39 2016 Guillaume TRAN
*/

#ifndef MY_H_
# define MY_H_
# include <stdarg.h>

int	my_strlen(char *);
void	my_putstr(char *);
void	my_revstr(char *);
int	check_for_int(int);
int	my_getnbr(char *);
double	my_atof(char *);
int	my_strcmp(char *, char *);
void	my_putchar(char);
int     scan_format(char *, va_list);
int     my_printf(char *, ...);
int     flag_s(va_list);
int     flag_o(va_list);
int     flag_x(va_list);
int     flag_X(va_list);
int     flag_b(va_list);
int     flag_p(va_list);
int     flag_c(va_list);
int     flag_d(va_list);
int     flag_u(va_list);
int     flag_f(va_list);
int     flag_smaj(va_list);
int     call_function(int, va_list);
int     get_id(int, char *, char *);
int     get_type(char *, va_list);
char	*my_putnbr_base(unsigned long, char *);
int	my_getnbr(char *);
char	*get_next_line(char *);
char	**my_str_to_wordtab(char *, char);

#endif /* !MY_H_ */
