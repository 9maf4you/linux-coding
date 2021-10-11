all: clean
	gcc -static -g ./server.c -o server.bin
	gcc -static -g ./client.c -o client.bin
	chmod +x *.bin

clean: 
	rm -fr *bin