typedef struct {
  int x, y, screen, window;
  SDL_bool use_screen, use_window;
} MousePos;

MousePos getMousePos(void);
void printMousePos(MousePos pos);
