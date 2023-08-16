/* assert.h non-standard header */
#undef assert   

#ifdef NDEBUG   // NDEBUG defined
    #define assert(expression) ((void) 0)
#else           // NDEBUG not defined
    // macro definition
    #define _STR(x) _VAL(x)
    #define _VAL(x) #x
    #define assert(expression) ((expression) ? (void) 0 : _assert(__FILE__":"_STR(__LINE__) " " #expression))
#endif

extern void _assert(const char * message);