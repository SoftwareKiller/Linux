.PHONY:all
all:client server

client:client.c
	gcc -g -o $@ $^

server:server.c
	gcc -g -o $@ $^

.PHONY:clean
clean:
	rm -f client server
