{ stdenv, makeWrapper, SDL2, xdotool }:

stdenv.mkDerivation rec {
  pname = "joyclick";
  version = "0.1";

  src = ./.;

  nativeBuildInputs = [ makeWrapper ];

  buildInputs = [ SDL2 xdotool ];

  installPhase = ''
    mkdir $out
    cp -r ./bin/ $out
    wrapProgram $out/bin/joyclick --prefix PATH ":" ${xdotool}/bin ;
  '';

  meta = with stdenv.lib; {
    description = "Program to click places with game controller";
    longDescription = ''
      Click defined locations on your screen with game controller
      button presses.
    '';
    homepage = https://github.com/neonfuz/joyclick;
    maintainers = [ maintainers.neonfuz ];
    platforms = platforms.linux;
  };
}
