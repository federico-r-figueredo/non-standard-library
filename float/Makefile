build: float.c
	@cc -c -fpic -I/usr/local/include/c-non-standard-library float.c -o build/float.o
	@cc --shared build/float.o -o build/libfloat.so
	@echo "make: success building source files."
	
install:
	@install -m 0755 float.h /usr/local/include/c-non-standard-library
	@install -m 0755 build/libfloat.so /usr/local/lib/c-non-standard-library
	@sudo ldconfig
	@rm build/float.o && rm build/libfloat.so
	@echo "make: success installing shared libraries"

test:
	@cc test.c -I/usr/local/include/c-non-standard-library -L/usr/local/lib/c-non-standard-library -lfloat -lassert -lm -o build/test
	@export LD_LIBRARY_PATH=/usr/local/lib/c-non-standard-library/:$LD_LIBRARY_PATH && ./build/test