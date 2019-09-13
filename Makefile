all: bin/joyclick

clean:
	rm bin/joyclick

bin/joyclick: src/*.c
	mkdir -p ./bin
	$(CC) $(CFLAGS) -o bin/joyclick $^ `sdl2-config --cflags --libs`

.PHONY: all clean
