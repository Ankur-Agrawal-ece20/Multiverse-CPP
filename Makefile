all:
	g++ -std=c++17 file.cpp -o file

test:
	chmod +x file
	./file > output.txt

.PHONY: check
FILE=output.txt
VARIABLE=`cat $(FILE)`
check:
    ifneq (,$(findstring  "SUCCESS", $(VARIABLE)) )
        $(error Few Test Cases Failed)
    endif

clean:
	$(RM) file output.txt
