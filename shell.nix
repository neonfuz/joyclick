with import <nixpkgs> {}; {
  joyclickEnv = gcc8Stdenv.mkDerivation {
    name = "joyclick-env";
    buildInputs = [ stdenv
                    gcc
                    SDL2
                    xdotool
                  ];
  };
}
