#include <stdint.h>

#define DECLARE_FUNC(n)												\
static void func_##n(int##n##_t *p, int len, float k)		\
{																			\
	for(int i = 0; i < len; ++i)									\
		p[i] = p[i] * k;												\
}

DECLARE_FUNC(8)
DECLARE_FUNC(16)
DECLARE_FUNC(32)

int main() { }

