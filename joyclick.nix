{ stdenv, fetchFromGitHub, makeWrapper, SDL2, xdotool }:

stdenv.mkDerivation rec {
  pname = "joyclick";
  version = "0.1";

  src = ./.;
#  fetchFromGitHub {
#    owner = "neonfuz";
#    repo = "joyclick";
#    rev = "6a9cc28f1e718dff008cc73c56dde12c589c28b2";
#    sha256 = "0jj67yp00y8mnxys37xb39dq442k3xsxm2nd67vvggq0k8rqp2p2";
#  };

  nativeBuildInputs = [
    makeWrapper
  ];

  buildInputs = [
    SDL2 xdotool
  ];

  installPhase = ''
    mkdir $out
    cp -r ./bin/ $out
    wrapProgram $out/bin/joyclick --prefix PATH ":" ${xdotool}/bin ;
  '';

  #  doCheck = true;

  meta = with stdenv.lib; {
     description = "Program to click places with game controller";
    longDescription = ''
      Click defined locations on your screen with game controller
      button presses.
    '';
    homepage = https://github.com/neonfuz/joyclick;
#    license =
    maintainers = [ maintainers.neonfuz ];
    platforms = platforms.linux;
  };
}
