build: assert.c
	@cc -c -Wall -Werror -fpic assert.c -o build/assert.o
	@cc --shared build/assert.o -o build/libassert.so
	@echo "make: success building source files."

install: build/libassert.so
	@install -m 0755 assert.h /usr/local/include/c-non-standard-library
	@install -m 0755 build/libassert.so /usr/local/lib/c-non-standard-library
	@sudo ldconfig
	@rm build/assert.o && rm build/libassert.so
	@echo "make: success installing shared libraries"

test: test.c
	@cc test.c -I/usr/local/include/c-non-standard-library -L/usr/local/lib/c-non-standard-library -lassert -o build/test
	@export LD_LIBRARY_PATH=/usr/local/lib/c-non-standard-library/:$LD_LIBRARY_PATH && ./build/test