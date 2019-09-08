all: joyclick

clean:
	rm joyclick

joyclick: *.c
	$(CC) -o joyclick $^ `sdl2-config --cflags --libs`

.PHONY: all clean
