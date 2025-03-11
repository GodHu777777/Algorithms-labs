qf: quickfind.cpp statistics.py
	g++ -std=c++11 quickfind.cpp -o qf
	python3 statistics.py ./qf
	
wqu: weightedQuickUnion.cpp statistics.py
	g++ -std=c++11 weightedQuickUnion.cpp -o wqu
	python3 statistics.py ./wqu

qfTime: quickfind.cpp
	g++ -std=c++11 quickfind.cpp -o qf
	python3 statistics.py ./qf

wquTime: weightedQuickUnion.cpp
	g++ -std=c++11 weightedQuickUnion.cpp -o wqu
	python3 statistics.py ./wqu

clean:
	find . -maxdepth 1 -type f -executable -print0 | xargs -0 rm -f

visual:
	cat	output.txt

.PHONY: clean visual