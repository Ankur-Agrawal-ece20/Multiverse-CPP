all:
	g++ -std=c++17 file.cpp -o file

test:
	chmod +x file
	./file > output.txt

.PHONY: check
check:
    if [ grep -Fxq "FAILURE" output.txt ]; then \
        echo "Few Test Cases Failed"; \
        exit 1; \
    fi

clean:
	$(RM) file output.txt
