compile: pipe_networking.c client.c server.c
	gcc -o client.out client.c pipe_networking.c
	gcc -o server.out server.c pipe_networking.c

clean:
	rm -rf *~
	rm -rf .out
