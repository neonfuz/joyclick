#include <SDL2/SDL.h>
#include <assert.h>

#include "mousepos.h"

MousePos pos = { 0 };
int button;

void read_pos_and_button()
{
  SDL_Event e;
  while (SDL_WaitEvent(&e)) {
    switch (e.type) {
    case SDL_QUIT:
      exit(0);
      break;
    case SDL_CONTROLLERBUTTONDOWN:
      button = e.cbutton.button;
      printf("button:%i ", button);
      pos = getMousePos();
      printMousePos(pos);
      return;
    }
  }
}

void mainloop()
{
  while (SDL_WaitEvent(&e)) {
    switch (e.type) {
    case SDL_QUIT:
      exit(0);
      break;
    case SDL_CONTROLLERBUTTONDOWN:
      printf("%i\t%i\n", e.cbutton.button, e.cbutton.timestamp);
      if (e.cbutton.button == button) {
        MousePos prev = getMousePos();
        setMousePos(pos);
        click();
        setMousePos(prev);
      }
      break;
    case SDL_JOYAXISMOTION:
    case SDL_JOYBUTTONUP:
    case SDL_JOYBUTTONDOWN:
    case SDL_CONTROLLERBUTTONUP:
      /* Ignore */
      break;
    default:
      fprintf(stderr, "unknown event:\t0x%x\n", e.type);
      break;
    }
  }
}

int main(int argc, char **argv)
{
  SDL_Init(SDL_INIT_JOYSTICK | SDL_INIT_GAMECONTROLLER);
  assert(0 == atexit(SDL_Quit));

  /* Open the first available controller. */
  SDL_GameController *controller = NULL;
  for (int i = 0; i < SDL_NumJoysticks(); ++i) {
    if (SDL_IsGameController(i)) {
      controller = SDL_GameControllerOpen(i);
      if (controller) {
        printf("Opened controller %i\n", i);
        break;
      }
    }
  }
  if (controller == NULL) {
    fprintf(stderr, "Failed to open game controller.\n");
    exit(1);
  }

  printf("Position mouse and press desired button...\n");
  read_pos_and_button();

  mainloop();

  exit(0);
}
