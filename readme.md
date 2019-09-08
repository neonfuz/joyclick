# JoyClick

Map a controller button to click on a window in a certain
spot.

## dependencies
 - [gcc]
 - [libsdl2-dev]
 - [xdotool]

## Compiling
Just run `make`

## Usage
Simply run the program, position your mouse, and press your desired
button. Usage will eventually be expanded but it's simple for now.

## Nix
For users of the [Nix] package manager, there is a development
environment defined in [shell.nix] which includes all required
dependencies. To use, run `nix-shell`.

[gcc]: https://gcc.gnu.org/
[libsdl2-dev]: https://www.libsdl.org/
[Nix]: https://nixos.org/nix/
[shell.nix]: ./shell.nix
[xdotool]: https://github.com/jordansissel/xdotool
