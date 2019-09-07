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

void setMousePos(MousePos pos) {
  char buf[256];
  int i = 0;

  i += snprintf(buf+i, 256-i, "xdotool mousemove ");
  if (pos.use_screen)
    i += snprintf(buf+i, 256-i, "--screen %i ", pos.screen);
  if (pos.use_window)
    i += snprintf(buf+i, 256-i, "--window %i ", pos.window);
  i += snprintf(buf+i, 256-i, "%i %i", pos.x, pos.y);

  int ret = system(buf);
  if (ret)
    printf("ret value: %i\n", ret);
}

void click(void) {
  int ret = system("xdotool click 1");
  if (ret)
    printf("ret value: %i\n", ret);
}

void printMousePos(MousePos pos) {
  printf("x: %i y:%i", pos.x, pos.y);
  if (pos.use_screen)
    printf(" screen:%i", pos.screen);
  if (pos.use_window)
    printf(" window:%i", pos.window);
  putchar('\n');
}
