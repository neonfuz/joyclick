whenpress: *.c
	$(CC) -o whenpress $^ `sdl2-config --cflags --libs`
