all: server

server:
	gcc -static -g ./server-client/server.c -o server.bin
	gcc -static -g ./server-client/client.c -o client.bin
	chmod +x *.bin

reset:
	gcc -static -g ./conn-reset-by-peer/server.c -o server.bin
	gcc -static -g ./conn-reset-by-peer/client.c -o client.bin
	chmod +x *.bin

refused:
	gcc -static -g ./conn-refused/server.c -o server.bin
	gcc -static -g ./conn-refused/client.c -o client.bin
	chmod +x *.bin

clean: 
	rm -fr *bin