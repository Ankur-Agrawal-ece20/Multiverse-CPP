all:
	g++ -std=c++17 file.cpp -o file

VARIABLE=""
test:
	chmod +x file
	./file > $(VARIABLE)

.PHONY: check
check:
    ifneq (,$(findstring  SUCCESS, $(VARIABLE)) )
        $(error Few Test Cases Failed $(VARIABLE))
    endif

clean:
	$(RM) file output.txt
