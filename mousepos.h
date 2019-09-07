typedef struct {
  int x, y, screen, window;
  SDL_bool use_screen, use_window;
} MousePos;

MousePos getMousePos(void);
void setMousePos(MousePos pos);
void click(void);
void printMousePos(MousePos pos);
