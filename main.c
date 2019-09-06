#include <SDL2/SDL.h>
#include <assert.h>

#include "mousepos.h"

MousePos pos = { 0 };

int main(int argc, char **argv)
{
  SDL_Init(SDL_INIT_JOYSTICK | SDL_INIT_GAMECONTROLLER);
  assert(0 == atexit(SDL_Quit));

  pos = getMousePos();
  printMousePos(pos);

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

  SDL_Event e;
  while (SDL_WaitEvent(&e)) {
    switch (e.type) {
    case SDL_QUIT:
      exit(0);
      break;
    case SDL_CONTROLLERBUTTONDOWN:
      printf("%i\t%i\n", e.cbutton.button, e.cbutton.timestamp);
      if (e.cbutton.button == 3) {
        system("./clickscript.sh");
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

  exit(0);
}
