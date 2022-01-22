all:
	g++ -std=c++17 file.cpp -o file

test:
	chmod +x file
	./file > output.txt

.PHONY: check
FILE=output.txt
VARIABLE=$(file < $(FILE))
check:
    ifneq (,$(findstring  SUCCESS, $(VARIABLE)) )
        $(error Few Test Cases Failed $(VARIABLE))
    endif

clean:
	$(RM) file output.txt
