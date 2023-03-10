program: main.c
	gcc main.c -o merge

.PHONY: clean

clean: 
	rm merge
