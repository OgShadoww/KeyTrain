#include <stdio.h>
#include <ncurses.h>

#define INPUT_SIZE 100

int main(void) {
  initscr();
  cbreak(); 
  noecho();
  keypad(stdscr, TRUE);

  int i = 0, chr = 0;
  char input[INPUT_SIZE];

  mvprintw(5, 10, "Hello, write your name: ");
  refresh();
  move(6, 10);

  while((chr = getch()) != '\n' && i < 99) {
    if(chr == 127) {
      i--;
      mvaddch(6, 10 + i, ' ');
      move(6, 10 + i);
    }
    else if(chr >= 32 && chr <= 126) {
      input[i++] = chr;
      addch(chr);
    }
  }
  
  input[i] = '\0';

  mvprintw(8, 10, "Your name is: %s", input);
  refresh();
  getch();
  

  endwin();

  return 0;    
}
