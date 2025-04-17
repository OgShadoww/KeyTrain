#include <stdio.h>
#include <ncurses.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

char *read_file(const char *filepath, size_t *len)
{
  FILE *f = fopen(filepath, "rb");
  if (!f) {
    fprintf(stderr, "fopen() failed: %s %s\n", filepath, strerror(errno));
    exit(1);
  }

  if (fseek(f, 0, SEEK_END) != 0) {
    fprintf(stderr, "fseek() failed: %s\n", strerror(errno));
    exit(1);
  }

  long m = ftell(f);
  if (m == -1) {
    fprintf(stderr, "ftell() failed: %s\n", strerror(errno));
    exit(1);
  }
  rewind(f);

  char *s = malloc(m + 1);
  if (fread(s, 1, m, f) != (size_t) m) {
    fprintf(stderr, "fread() failed: %s\n", strerror(errno));
    exit(1);
  }
  s[m] = 0;

  fclose(f);

  *len = m;
  return s;
}

#define TEXT_DIR "text"

void center_text(char *text, size_t text_len) {
  int width = getmaxx(stdscr);
  int str_len = width / 2;
  char *buff = malloc(str_len);
  int y = 5;
  int x = (width - strlen(buff)) / 2;
  int k = 0;

  for(size_t i = 0; i < text_len; i++) {
    buff[k] = text[i];
    if(text[i] == ' ') {
      if(k >= str_len - 2) {
        mvprintw(y++, x, buff);
        free(buff);
        k = 0;
      }
    }
    k++;
  }

  return;
}

int main(int argc, char **argv) {
  // TODO: parse args
  (void) argc;
  (void) argv;

  size_t text_len; // hardcode for now
  char *text = read_file(TEXT_DIR"/lorem.txt", &text_len);
  
  initscr();

  // Print center text  
  center_text(text, text_len);   
  getch();

  endwin();

  free(text);  

  return 0;    
}
