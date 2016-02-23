/*
** main.c for Allum1 in /home/tran_-/Documents/rendu/CPE_2015_Allum1
**
** Made by tran_-
** Login   <tran_-@epitech.net>
**
** Started on  Mon Feb  8 12:20:48 2016 tran_-
** Last update Mon Feb 22 01:05:52 2016 Guillaume TRAN
*/

#include "allum1.h"

void	start_game(char *name)
{
  int	i;
  int	k;

  srand(time(NULL));
  i = 0;
  k = rand()%(11-5) +5;
  while (name[i])
    {
      attron(COLOR_PAIR(k));
      mvprintw(LINES/2 - 7/2 - 7, COLS/2 - 2 + i, "%c", name[i]);
      i++;
      if (k == 11)
	k = 5;
      k++;
    }
}

void	start_my_colors()
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

void	loading()
{
  int	k;

  k = 0;
  attron(COLOR_PAIR(7));
  mvprintw(LINES/2 - 6, COLS/2 - 3, "Loading");
  attron(COLOR_PAIR(2));
  while (k < 24)
    {
      mvprintw(LINES/2 - 4, COLS/2 + k - 11, ".");
      refresh();
      usleep(90000);
      k++;
    }
}

int	game(t_allum *allum)
{
  int	key;

  start_game("Allum1");
  refresh();
  sleep(1);
  loading();
  clear();
  while (key != 32)
    {
      start_game("Allum1");
      display_map(allum);
      attron(COLOR_PAIR(7));
      mvprintw(LINES/2 - 6, COLS/2 - 4, "Your turn");
      mvprintw(LINES/2 + 6, COLS/2 - 15, "Press Enter to select | Arrow to move");
      key = getch();
      part_one(allum, key);
      if (part_two(allum) == 1)
	return (0);
    }
  return (1);
}

int		main(int ac, char **av)
{
  t_allum	allum;

  allum.selector = 0;
  allum.mselector = 0;
  allum.status = 0;
  ac = ac;
  av = av;
  allum.width = 7;
  allum.height = 4;
  allum.map = my_initialize_map(allum.width, allum.height);
  my_fill_map(&allum);
  initscr();
  start_my_colors();
  game(&allum);
  endwin();
  return (0);
}
