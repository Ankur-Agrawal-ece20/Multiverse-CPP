all:
	g++ -std=c++17 file.cpp -o file


.PHONY: check
check:
	chmod +x file
	VARIABLE = $(shell echo $("./file"))
    ifneq (,$(findstring  SUCCESS, $(VARIABLE)) )
        $(error Few Test Cases Failed $(VARIABLE))
    endif

clean:
	$(RM) file output.txt
