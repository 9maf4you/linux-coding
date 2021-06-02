all:
	gcc -static -g ./stp/3.5/getpid.c -o getpid.bin
	gcc -static -g ./stp/3.5/fork.c -o fork.bin


clean:
	rm ./*.bin || true
