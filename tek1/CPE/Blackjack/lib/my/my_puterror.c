/*
** my_puterror.c for my_puterror in /home/ladenb_p/Rendu/Projets/PSU/PSU_2015_minishell1/lib/my
**
** Made by Pierre Ladenburger
** Login   <ladenb_p@ladenb_p>
**
** Started on  Tue Feb  2 21:23:59 2016 Pierre Ladenburger
** Last update Tue Feb  2 21:25:16 2016 Pierre Ladenburger
*/

#include <unistd.h>
#include "lib.h"

void	my_puterror(char *str)
{
  if (str != NULL)
    write(2, str, my_strlen(str));
}
