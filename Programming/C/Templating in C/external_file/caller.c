#include <stdint.h>

#define TEMPLATE_U16
#include "evil_template.c"
#undef TEMPLATE_U16

#define TEMPLATE_U32
#include "evil_template.c"
#undef TEMPLATE_U32

#define TEMPLATE_FLT
#include "evil_template.c"
#undef TEMPLATE_FLT

#define TEMPLATE_DBL
#include "evil_template.c"
#undef TEMPLATE_DBL

int main() {}
