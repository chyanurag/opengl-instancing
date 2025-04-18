all:
	g++ -lGL -lGLEW -lglfw -lglm main.cc -o main
clean:
	rm -f main
