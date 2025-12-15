all: bin/Inventory-Management-Software

Inventory-Management-Software: bin/Inventory-Management-Software

bin/Inventory-Management-Software: $(patsubst src/%.c, bin/%.o, $(wildcard src/*.c))
	gcc -std=c99 -Wall -Iinclude $^ -o $@

bin/%.o: src/%.c
	gcc -std=c99 -Wall -Iinclude -c $< -o $@

clear: clean

clean:
	rm -f bin/*.o bin/Inventory-Management-Software

