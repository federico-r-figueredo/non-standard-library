CC = cc
CFLAGS = -Wall -Werror
INSTALL = install -m 0755

build: error-number.c
	@$(CC) -c $(CFLAGS) -fpic error-number.c -o build/error-number.o

	@$(CC) --shared build/error-number.o -o build/liberror-number.so

	@echo "make: success building source files."

install:
	@$(INSTALL) error-number.h /usr/local/include/c-non-standard-library
	@$(INSTALL) build/liberror-number.so /usr/local/lib/c-non-standard-library

	@sudo ldconfig

	@rm build/error-number.o && rm build/liberror-number.so

	@echo "make: success installing shared libraries"

test: test.c
	@$(CC) $(CFLAGS) test.c -I/usr/local/include/c-non-standard-library -L/usr/local/lib/c-non-standard-library -lassert -lerror-number -o build/test
	@export LD_LIBRARY_PATH=/usr/local/lib/c-non-standard-library/:$LD_LIBRARY_PATH && ./build/test