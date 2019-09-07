joyclick: *.c
	$(CC) -o joyclick $^ `sdl2-config --cflags --libs`
