#include <stdint.h>

#define DO_RANDOM_STUFF(type) do {	\
	type *p = buf;					\
	for(int i = 0; i < len; ++i)	\
		p[i] = p[i] * k;			\
} while(0)

enum Request {
	INT8,
	INT16,
	INT32
};

int func(void *buf, int len, float k, int request) {
	if		(request == INT8) 	DO_RANDOM_STUFF(int8_t);
	else if	(request == INT16)	DO_RANDOM_STUFF(int16_t);
	else if	(request == INT32)	DO_RANDOM_STUFF(int32_t);
}

int main() { }
