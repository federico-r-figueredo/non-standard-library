install:
	@install -m 0755 integer.h /usr/local/include/c-non-standard-library
	@sudo ldconfig
	@echo "make: success installing shared libraries"

test:
	@cc test.c -I/usr/local/include/c-non-standard-library -L/usr/local/lib/c-non-standard-library -o build/test
	@export LD_LIBRARY_PATH=/usr/local/lib/c-non-standard-library/:$LD_LIBRARY_PATH && ./build/test