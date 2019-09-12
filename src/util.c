#include <SDL2/SDL.h>

char *vformat(const char *fmt, va_list args) {
  va_list sizeprint_args;
  va_copy(sizeprint_args, args);
  size_t bufsize = vsnprintf(NULL, 0, fmt, sizeprint_args) + 1;
  va_end(sizeprint_args);
  char *buf = malloc(bufsize);
  vsprintf(buf, fmt, args);
  return buf;
}

char *format(const char *fmt, ...) {
  va_list args;
  va_start(args, fmt);
  char *buf = vformat(fmt, args);
  va_end(args);
  return buf;
}

int systemf(const char *fmt, ...) {
  va_list args;
  va_start(args, fmt);
  char *command = vformat(fmt, args);
  va_end(args);
  return system(command);
}

FILE *popenf(const char *type, const char *fmt, ...) {
  va_list args;
  va_start(args, fmt);
  char *command = vformat(fmt, args);
  FILE *fp = popen(command, type);
  free(command);
  return fp;
}
