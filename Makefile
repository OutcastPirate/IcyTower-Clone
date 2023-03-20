CXX = clang++
CXX_FLAGS = -Wall -Wextra -pedantic -Werror -fsanitize=undefined -std=c++20

main:
	$(CXX) $(CXX_FLAGS) -c src/main.cpp
	$(CXX) $(CXX_FLAGS) main.o -o game -lsfml-graphics -lsfml-window -lsfml-system

docs_clean:
	rm -r docs

docs:
	doxygen resources/doxygen.conf

clean:
	rm game main.o


