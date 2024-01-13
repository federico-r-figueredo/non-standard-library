CC = cc
CFLAGS = -Wall -Werror
INSTALL = install -m 0755

build: is-alphabetic.c is-alphanumeric.c is-control.c is-digit.c is-graphical.c is-hexadecimal.c is-lower-case.c is-printable.c is-spacing.c is-upper-case.c to-lower-case.c to-upper-case.c x-character-type.c x-to-lower-case.c x-to-upper-case.c
	@$(CC) -c $(CFLAGS) -fpic is-alphabetic.c -o build/is-alphabetic.o
	@$(CC) -c $(CFLAGS) -fpic is-alphanumeric.c -o build/is-alphanumeric.o
	@$(CC) -c $(CFLAGS) -fpic is-control.c -o build/is-control.o
	@$(CC) -c $(CFLAGS) -fpic is-digit.c -o build/is-digit.o
	@$(CC) -c $(CFLAGS) -fpic is-graphical.c -o build/is-graphical.o
	@$(CC) -c $(CFLAGS) -fpic is-hexadecimal.c -o build/is-hexadecimal.o
	@$(CC) -c $(CFLAGS) -fpic is-lower-case.c -o build/is-lower-case.o
	@$(CC) -c $(CFLAGS) -fpic is-upper-case.c -o build/is-upper-case.o
	@$(CC) -c $(CFLAGS) -fpic is-printable.c -o build/is-printable.o
	@$(CC) -c $(CFLAGS) -fpic is-punctuation.c -o build/is-punctuation.o
	@$(CC) -c $(CFLAGS) -fpic is-spacing.c -o build/is-spacing.o
	@$(CC) -c $(CFLAGS) -fpic to-lower-case.c -o build/to-lower-case.o
	@$(CC) -c $(CFLAGS) -fpic to-upper-case.c -o build/to-upper-case.o
	@$(CC) -c $(CFLAGS) -fpic x-character-type.c -o build/x-character-type.o
	@$(CC) -c $(CFLAGS) -fpic x-to-lower-case.c -o build/x-to-lower-case.o
	@$(CC) -c $(CFLAGS) -fpic x-to-upper-case.c -o build/x-to-upper-case.o

	@$(CC) --shared build/is-alphabetic.o -o build/libis-alphabetic.so
	@$(CC) --shared build/is-alphanumeric.o -o build/libis-alphanumeric.so
	@$(CC) --shared build/is-control.o -o build/libis-control.so
	@$(CC) --shared build/is-digit.o -o build/libis-digit.so
	@$(CC) --shared build/is-graphical.o -o build/libis-graphical.so
	@$(CC) --shared build/is-hexadecimal.o -o build/libis-hexadecimal.so
	@$(CC) --shared build/is-lower-case.o -o build/libis-lower-case.so
	@$(CC) --shared build/is-upper-case.o -o build/libis-upper-case.so
	@$(CC) --shared build/is-printable.o -o build/libis-printable.so
	@$(CC) --shared build/is-punctuation.o -o build/libis-punctuation.so
	@$(CC) --shared build/is-spacing.o -o build/libis-spacing.so
	@$(CC) --shared build/to-lower-case.o -o build/libto-lower-case.so
	@$(CC) --shared build/to-upper-case.o -o build/libto-upper-case.so
	@$(CC) --shared build/x-character-type.o -o build/libx-character-type.so
	@$(CC) --shared build/x-to-lower-case.o -o build/libx-to-lower-case.so
	@$(CC) --shared build/x-to-upper-case.o -o build/libx-to-upper-case.so

	@echo "make: success building source files."

install:
	@$(INSTALL) -m 0755 character-type.h /usr/local/include/c-non-standard-library
	@$(INSTALL) -m 0755 build/libis-alphabetic.so /usr/local/lib/c-non-standard-library
	@$(INSTALL) -m 0755 build/libis-alphanumeric.so /usr/local/lib/c-non-standard-library
	@$(INSTALL) -m 0755 build/libis-control.so /usr/local/lib/c-non-standard-library
	@$(INSTALL) -m 0755 build/libis-digit.so /usr/local/lib/c-non-standard-library
	@$(INSTALL) -m 0755 build/libis-graphical.so /usr/local/lib/c-non-standard-library
	@$(INSTALL) -m 0755 build/libis-hexadecimal.so /usr/local/lib/c-non-standard-library
	@$(INSTALL) -m 0755 build/libis-lower-case.so /usr/local/lib/c-non-standard-library
	@$(INSTALL) -m 0755 build/libis-upper-case.so /usr/local/lib/c-non-standard-library
	@$(INSTALL) -m 0755 build/libis-printable.so /usr/local/lib/c-non-standard-library
	@$(INSTALL) -m 0755 build/libis-punctuation.so /usr/local/lib/c-non-standard-library
	@$(INSTALL) -m 0755 build/libis-spacing.so /usr/local/lib/c-non-standard-library
	@$(INSTALL) -m 0755 build/libto-lower-case.so /usr/local/lib/c-non-standard-library
	@$(INSTALL) -m 0755 build/libto-upper-case.so /usr/local/lib/c-non-standard-library
	@$(INSTALL) -m 0755 build/libx-character-type.so /usr/local/lib/c-non-standard-library
	@$(INSTALL) -m 0755 build/libx-to-lower-case.so /usr/local/lib/c-non-standard-library
	@$(INSTALL) -m 0755 build/libx-to-upper-case.so /usr/local/lib/c-non-standard-library

	@sudo ldconfig

	@rm build/is-alphabetic.o && rm build/libis-alphabetic.so
	@rm build/is-alphanumeric.o && rm build/libis-alphanumeric.so
	@rm build/is-control.o && rm build/libis-control.so
	@rm build/is-digit.o && rm build/libis-digit.so
	@rm build/is-graphical.o && rm build/libis-graphical.so
	@rm build/is-hexadecimal.o && rm build/libis-hexadecimal.so
	@rm build/is-lower-case.o && rm build/libis-lower-case.so
	@rm build/is-upper-case.o && rm build/libis-upper-case.so
	@rm build/is-printable.o && rm build/libis-printable.so
	@rm build/is-punctuation.o && rm build/libis-punctuation.so
	@rm build/is-spacing.o && rm build/libis-spacing.so
	@rm build/to-lower-case.o && rm build/libto-lower-case.so
	@rm build/to-upper-case.o && rm build/libto-upper-case.so
	@rm build/x-character-type.o && rm build/libx-character-type.so
	@rm build/x-to-lower-case.o && rm build/libx-to-lower-case.so
	@rm build/x-to-upper-case.o && rm build/libx-to-upper-case.so

	@echo "make: success installing shared libraries"

test: test.c
	@$(CC) $(CFLAGS) test.c -I/usr/local/include/c-non-standard-library -L/usr/local/lib/c-non-standard-library \
		-lassert -lis-alphabetic -lis-alphanumeric -lis-control -lis-digit -lis-hexadecimal -lis-lower-case -lis-upper-case \
		-lis-printable -lis-spacing -lto-lower-case -lto-upper-case -lx-character-type -lx-to-lower-case -lx-to-upper-case \
		-lis-punctuation -lis-graphical -o build/test
	@export LD_LIBRARY_PATH=/usr/local/lib/c-non-standard-library/:$LD_LIBRARY_PATH && ./build/test
