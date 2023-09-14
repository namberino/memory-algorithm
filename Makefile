compile:
	gcc -std=c99 elevator/elevator.c -o elevator/elevator
	gcc -std=c99 first-fit/first-fit.c -o first-fit/first-fit
run:
	./elevator/elevator
	./first-fit/first-fit
