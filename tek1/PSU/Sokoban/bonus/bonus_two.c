/*
** bonus_two.c for sokoban in /home/tran_-/Documents/rendu/PSU_2015_my_sokoban/bonus
**
** Made by Guillaume TRAN
** Login   <tran_-@epitech.net>
**
** Started on  Fri Jan 15 17:22:20 2016 Guillaume TRAN
** Last update Sun Jan 17 16:24:46 2016 Guillaume TRAN
*/

#include "sokoban.h"

void	my_fill_list(char list[3][8])
{
  list[0][0] = 'R';
  list[0][1] = 'E';
  list[0][2] = 'S';
  list[0][3] = 'U';
  list[0][4] = 'M';
  list[0][5] = 'E';
  list[0][6] = '\0';
  list[1][0] = 'R';
  list[1][1] = 'E';
  list[1][2] = 'S';
  list[1][3] = 'T';
  list[1][4] = 'A';
  list[1][5] = 'R';
  list[1][6] = 'T';
  list[1][7] = '\0';
  list[2][0] = 'E';
  list[2][1] = 'X';
  list[2][2] = 'I';
  list[2][3] = 'T';
  list[2][4] = '\0';
}

int     open_menu()
{
  WINDOW        *w;
  char          list[3][8];
  char          item[7];
  int   i;

  my_fill_list(list);
  w = newwin(8, 30, LINES/2-2, COLS/2-15);
  box(w, 0, 0);
  i = -1;
  while (++i < 3)
    {
      if (i == 0)
	wattron(w, A_STANDOUT);
      else
	wattroff(w, A_STANDOUT);
      sprintf(item, "%s",  list[i]);
      mvwprintw(w, i+2, 10, "%s", item);
    }
  wrefresh(w);
  noecho();
  keypad(w, TRUE);
  i = bonus_menu(w, list, item);
  delwin(w);
  return (i);
}

void     print_win()
{
  initscr();
  start_color();
  init_pair(14, COLOR_BLUE, COLOR_BLACK);
  mvprintw(LINES/2, COLS/2, "YOU WIN !");
  while (wgetch(stdscr) != 'q')
    {
      attron(COLOR_PAIR(14));
      mvprintw(LINES/2, COLS/2, "YOU WIN !");
    }
  endwin();
}

void    start_my_colors()
{
  start_color();
  init_pair(1, COLOR_BLACK, COLOR_YELLOW);
  init_pair(2, COLOR_WHITE, COLOR_WHITE);
  init_pair(3, COLOR_BLACK, COLOR_BLACK);
  init_pair(4, COLOR_BLACK, COLOR_YELLOW);
  init_pair(5, COLOR_WHITE, COLOR_BLACK);
  init_pair(6, COLOR_RED, COLOR_BLACK);
  init_pair(7, COLOR_BLUE, COLOR_BLACK);
  init_pair(8, COLOR_CYAN, COLOR_BLACK);
  init_pair(9, COLOR_MAGENTA, COLOR_BLACK);
  init_pair(10, COLOR_GREEN, COLOR_BLACK);
  init_pair(11, COLOR_YELLOW, COLOR_BLACK);
  init_pair(12, COLOR_WHITE, COLOR_BLACK);
  init_pair(13, COLOR_BLUE, COLOR_BLUE);
  init_pair(14, COLOR_RED, COLOR_RED);
  noecho();
  curs_set(0);
  keypad(stdscr, TRUE);
}

void    start_ncurses(t_info *sokoban, int movement, int restart)
{
  initscr();
  noecho();
  keypad(stdscr, TRUE);
  display_game(sokoban, movement, restart);
  curs_set(0);
}
