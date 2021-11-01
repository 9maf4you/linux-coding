all: logger

logger:
	gcc -g ./logger.c -o logger.bin
	gcc -g ./client.c -o client.bin
	chmod +x *.bin

clean: 
	rm -fr *bin