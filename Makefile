all:
	g++ -std=c++17 file.cpp -o file

test:
	chmod +x file
	./file > output.txt

.PHONY: check
check:
    ifeq ( $(grep  "SUCCESS" output.txt), "" )
        echo "Few Test Cases Failed"
        exit 1
    endif

clean:
	$(RM) file output.txt
