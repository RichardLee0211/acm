test3: test3.cpp
	clang++ -std=c++11 test3.cpp -o test3
	./test3 pi.txt
test1: test1.cpp
	clang++ -std=c++11 test1.cpp -o test1 -lpthread
	./test1

fancyOutput: fancyOutput.cpp
	clang++ -std=c++11 fancyOutput.cpp -o fancyOutput
	./fancyOutput

clean:
	rm -rf test test1 test2 fancyOutput
