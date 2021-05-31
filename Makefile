all:
	gcc -static -g ./stp/3.5/getpid.c -o getpid.bin


clean:
	rm ./*.bin || true
