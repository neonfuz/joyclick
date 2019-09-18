all: bin/joyclick

clean:
	rm bin/joyclick

bin/joyclick: src/*.c src/*.h
	mkdir -p ./bin
	$(CC) $(CFLAGS) -o bin/joyclick src/*.c `sdl2-config --cflags --libs`

.PHONY: all clean
