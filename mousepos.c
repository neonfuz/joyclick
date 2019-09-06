#include <SDL2/SDL.h>
#include <string.h>
#include <assert.h>
#include "mousepos.h"

MousePos getMousePos(void) {
  MousePos pos = { 0 };
  FILE *fp;
  char line[256];

  fp = popen("xdotool getmouselocation", "r");
  if (fp == NULL) {
    fprintf(stderr, "failed to execute xdotool\n");
    exit(1);
  }
  int scanned = fscanf(
    fp,
    "x:%i y:%i screen:%i window:%i\n",
    &pos.x, &pos.y, &pos.screen, &pos.window
  );
  assert(scanned == 4);

  pos.use_screen = pos.use_window = 1;

  return pos;
}

void printMousePos(MousePos pos) {
  printf("x: %i y:%i", pos.x, pos.y);
  if (pos.use_screen)
    printf(" screen:%i", pos.screen);
  if (pos.use_window)
    printf(" window:%i", pos.window);
  putchar('\n');
}
