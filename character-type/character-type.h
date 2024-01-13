/* character-type.h standard header */
#ifndef _CHARACTER_TYPE
#define _CHARACTER_TYPE

/* _character_type code bits */
#define _XA 0x200 /* extra alphabetic */
#define _XS 0x100 /* extra space */
#define _BB 0x80 /* BEL, BS, etc. */
#define _CN 0x40 /* CR, FF, HT, NL, VT */
#define _DI 0x20 /* '0'-'9' */
#define _LO 0x10 /* 'a'-'z' */
#define _PU 0x08 /* punctuation */
#define _SP 0x04 /* space */
#define _UP 0x02 /* 'A'-'Z' */
#define _XD 0x01 /* '0'-'9', 'A'-'F', 'a'-'f' */

/* declarations */
int is_alphanumeric(int), is_alphabetic(int), is_lowercase(int), is_upper_case(int);
int is_digit(int), is_hexadecimal(int), is_control(int), is_punctuation(int);
int is_spacing(int), is_graphical(int), is_printable(int);
int to_lowercase(int), to_uppercase(int);

extern const short *_character_type, *_to_lowercase, *_to_uppercase;

/* macro overrides */
#define is_alphanumeric(character) (_character_type[(int)(character)] & (_LO | _UP | _XA | _DI))
#define is_alphabetic(character)   (_character_type[(int)(character)] & (_LO | _UP | _XA))
#define is_lowercase(character)    (_character_type[(int)(character)] & _LO)
#define is_upper_case(character)   (_character_type[(int)(character)] & _UP)
#define is_digit(character)        (_character_type[(int)(character)] & _DI)
#define is_hexadecimal(character)  (_character_type[(int)(character)] & _XD)
#define is_control(character)      (_character_type[(int)(character)] & (_BB | _CN))
#define is_punctuation(character)  (_character_type[(int)(character)] & _PU)
#define is_spacing(character)      (_character_type[(int)(character)] & (_CN | _SP | _XS))
#define is_graphical(character)    (_character_type[(int)(character)] & (_LO | _UP | _XA | _DI | _PU))
#define is_printable(character)    (_character_type[(int)(character)] & (_LO | _UP | _XA | _DI | _PU | _SP))
#define to_lowercase(character)    (_to_lowercase[(int)(character)])
#define to_uppercase(character)    (_to_uppercase[(int)(character)])

#endif