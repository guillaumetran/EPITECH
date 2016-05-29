/*
** lib.h for lib in /home/ladenb_p/Rendu/Projets/PSU/PSU_2015_minishell1/minishell/lib/my
**
** Made by Pierre Ladenburger
** Login   <ladenb_p@ladenb_p>
**
** Started on  Mon Feb  1 20:59:14 2016 Pierre Ladenburger
** Last update Wed Mar 23 17:35:57 2016 Pierre Ladenburger
*/

#ifndef LIB_H_
# define LIB_H_

char	*epur_str(char *);
void	my_putchar(char);
int	my_getnbr(char *);
char	*my_strcat(char *, char *);
char	*my_strcat_for_shell(char *, char *, char);
char	*my_strcpy(char *, char *);
int	my_strcmp(char *, char *);
int	str_match(const char *, const char *);
int	my_strncmp(char *, char *, int);
int	my_strlen(char *);
char	*my_strdup(char *);
void	my_putstr(char *);
void	my_revstr(char *);
char	**my_str_to_wordtab(char *, char);
char	**my_str_to_wordtab_two(char *, char, char);
int	my_put_nbr(int);
void	my_puterror(char *);
char	*my_strcp(char *);
char	*get_next_line(const int);
int	my_printf(const char *, ...);

#endif /* !LIB_H_ */
