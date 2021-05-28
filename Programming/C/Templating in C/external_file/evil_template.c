#include <stdint.h>

#if defined(TEMPLATE_U16)

#	define	RENAME(N)		N ## _u16
#	define	TYPE			uint16_t
#	define	SUM_TYPE		uint32_t
#	define	XDIV(x, n)		(((x) + ((1 << (n)) - 1)) >> (n))

#elif defined(TEMPLATE_U32)

#    define RENAME(N)   N ## _u32
#    define TYPE        uint32_t
#    define SUM_TYPE    uint64_t
#    define XDIV(x, n)  (((x) + ((1<<(n))-1)) >> (n))

#elif defined(TEMPLATE_FLT)

#    define RENAME(N)   N ## _flt
#    define TYPE        float
#    define SUM_TYPE    float
#    define XDIV(x, n)  ((x) / (float)(1<<(n)))

#elif defined(TEMPLATE_DBL)

#    define RENAME(N)   N ## _dbl
#    define TYPE        double
#    define SUM_TYPE    double
#    define XDIV(x, n)  ((x) / (double)(1<<(n)))

#endif

TYPE RENAME(func) (const TYPE *p, int n) {
	int i;
	SUM_TYPE sum = 0;
	for(i = 0; i < 1 << n; ++i)
		sum += p[i];
	return XDIV(sum, n);
}

#undef RENAME
#undef TYPE
#undef SUM_TYPE
#undef XDIV
