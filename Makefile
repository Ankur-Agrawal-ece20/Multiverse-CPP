all:
	g++ -std=c++17 file.cpp -o file

test:
	chmod +x file
	./file

clean:
	$(RM) hello helloTest