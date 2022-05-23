build:
	g++ -g -std=c++17 $(name).cpp -o $(name)

vrun:
	valgrind --leak-check=full ./$(name)

fbuild:
	g++ -g -fsanitize=address -std=c++17 $(name).cpp -o $(name)

run:
	./$(name)

dbg:
	gdb ./$(name)

hck_dbg:
	edb --run $(name)
