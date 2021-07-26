all:
	gcc -static -g ./stp/3.5/getpid.c -o getpid.bin
	gcc -static -g ./stp/3.5/fork.c -o fork.bin
	gcc -static -g ./stp/3.5/zombie.c -o zombie.bin
	gcc -static -g ./stp/3.5/process.c -o process.bin
	gcc -static -g ./stp/4.1/pipes.c -o pipes.bin


clean:
	rm ./*.bin || true
