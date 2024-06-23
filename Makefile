ising: clean_ising ising.out
	@./ising.out

ising.out:
	@clang ising.c rand.c -o ising.out -O3 -Wall -Wextra -lraylib -lm

clean_ising:
	@rm -f ising.out
