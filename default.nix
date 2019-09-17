let
  pkgs = import <nixpkgs> {};
in with pkgs; {
  joyclick = callPackage ./joyclick.nix { };
}
