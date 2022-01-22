all:
	g++ -std=c++17 file.cpp -o file

test:
	chmod +x file
    ifeq (,$(findstring SUCCESS!, $(shell ./file)))
        $(error $(shell ./file)))
    endif

clean:
	$(RM) file output.txt
