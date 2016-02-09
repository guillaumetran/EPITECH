/*
** bonus.c for bonus in /home/tran_-/Documents/rendu/PSU_2015_my_sokoban/bonus
**
** Made by Guillaume TRAN
** Login   <tran_-@epitech.net>
**
** Started on  Wed Jan 13 20:35:41 2016 Guillaume TRAN
** Last update Sun Jan 17 16:29:39 2016 Guillaume TRAN
*/

#include "sokoban.h"

void	pick_color(t_info *sokoban, int i, int j)
{
  if (sokoban->map[i][j] == '#')
    wattron(stdscr, COLOR_PAIR(2));
  else if (sokoban->map[i][j] == 'X')
    {
      if ((check_isok(i, j, sokoban->goal, sokoban->o)) == 1)
	wattron(stdscr, COLOR_PAIR(13));
      else if ((is_placed(i, j, sokoban->goal, sokoban->o)) == 1)
	{
	  if ((is_blocked(i, j, sokoban->map)) == 1)
	    wattron(stdscr, COLOR_PAIR(14));
	  else
	    wattron(stdscr, COLOR_PAIR(3));
	}
    }
  else if (sokoban->map[i][j] == 'O')
    wattron(stdscr, COLOR_PAIR(4));
  else if (sokoban->map[i][j] == 'F')
    wattron(stdscr, COLOR_PAIR(3));
  else
    wattron(stdscr, COLOR_PAIR(1));
}

void    display_bonus(t_info *sokoban)
{
  int   i;
  int	j;

  i = 0;
  while (i < sokoban->height)
    {
      j = 0;
      while (j < sokoban->width)
	{
	  pick_color(sokoban, i, j);
	  mvprintw(LINES/2 + i - sokoban->height/2, COLS/2 + j
		   - sokoban->width/2, "%c", sokoban->map[i][j]);
	  j++;
	}
      i++;
    }
}

int	bonus_menu(WINDOW *w, char list[3][8], char item[7])
{
  int	ch;
  int	i;

  i = 0;
  while ((ch = wgetch(w)) != 10)
    {
      sprintf(item, "%-7s",  list[i]);
      mvwprintw( w, i+2, 10, "%s", item );
      if (ch == KEY_UP)
	{
	  i--;
	  i = (i < 0) ? 2 : i;
	}
      if (ch == KEY_DOWN)
	{
	  i++;
	  i = (i > 2) ? 0 : i;
	}
      wattron( w, A_STANDOUT );
      sprintf(item, "%-7s",  list[i]);
      mvwprintw( w, i+2, 10, "%s", item);
      wattroff( w, A_STANDOUT );
    }
  return (i);
}

void    display_game(t_info *sokoban, int movement, int restart)
{
  display_sokoban(sokoban->height);
  display_bonus(sokoban);
  attron(COLOR_PAIR(12));
  mvprintw(LINES/2 - sokoban->height/2 - 4,
	   COLS/2 - 5, "LEVEL %d", sokoban->level);
  mvprintw(LINES/2 - sokoban->height/2 - 2,
	   COLS/2 - 15, "| Movement : %d | RESTART : %d |", movement, restart);
  mvprintw(LINES/2 + sokoban->height/2 + 3,
	   COLS/2 - 14, "| Q == MENU | SPACE = RESTART |");
}

void    display_sokoban(int height)
{
  int   i;
  int   k;
  char  soko[7];

  soko[0] = 'S';
  soko[1] = 'O';
  soko[2] = 'K';
  soko[3] = 'O';
  soko[4] = 'B';
  soko[5] = 'A';
  soko[6] = 'N';
  soko[7] = '\0';
  srand(time(NULL));
  i = 0;
  k = rand()%(11-5) +5;
  while (soko[i])
    {
      attron(COLOR_PAIR(k));
      mvprintw(LINES/2 - height/2 - 7, COLS/2 - 4 + i, "%c", soko[i]);
      i++;
      if (k == 11)
	k = 5;
      k++;
    }
}
