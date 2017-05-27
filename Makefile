all:
	g++ -std=c++1y -static -Isrc -O2 -lm main.cpp src/* -o bot

.PHONY: clean
clean:
	rm -rf bin/*
