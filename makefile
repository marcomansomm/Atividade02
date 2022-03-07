bin: parent_in_children_out.c
	gcc $< -o $@

.PHONY: run clean

run:
	./bin

clean: 
	rm bin
