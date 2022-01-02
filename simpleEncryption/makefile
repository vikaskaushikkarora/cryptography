all: enc dec

enc: encrypt.c
	gcc encrypt.c -o encrypt.out -lm && ./encrypt.out

dec: decrypt.c
	gcc decrypt.c -o decrypt.out -lm && ./decrypt.out

clean:
	rm *.out
