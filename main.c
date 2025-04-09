#include <stdio.h>
#include <ncurses.h>

#define INPUT_SIZE 100;

int main(void) {
  initscr();
  cbreak(); 
  noecho();
  keypad(stdsrc, TRUE);

  int i, chr = 0;
  char input[INPUT_SIZE];

  mvprintw(5, 10, "Hello, write your name: ");
  move(6, 10);

  while((chr = getch()) != "\n") {
    if(chr == 127) {
      i--;
      mvaddch(6, 10 + i, ' ');
      move(6, 10 + i);
    }

  }

  endwin();

  return 0;    
}
