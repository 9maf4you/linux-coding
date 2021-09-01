all: clean
	gcc -static -g ./shm_server.c -o server.bin
	gcc -static -g ./shm_client.c -o client.bin
	chmod +x *.bin

clean: 
	rm -fr *bin