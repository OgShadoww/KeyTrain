#include <stdio.h>
#include <ncurses.h>

#define INPUT_SIZE 100

int main(void) {
  initscr();
  cbreak(); 
  noecho();
  keypad(stdscr, TRUE);

  char input[INPUT_SIZE];

  mvprintw(5, 10, "Hello, write your name: ");
  refresh();
  move(6, 10);

  echo();
  getnstr(input, INPUT_SIZE);
  noecho();

  mvprintw(8, 10, "Your name is: %s", input);
  refresh();
  getch();

  endwin();

  return 0;    
}
