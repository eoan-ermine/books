#include <assert.h>
#define FNAME "test.c"

int main() {
    #line 777 FNAME
    assert(2 + 2 == 4);
    assert(2 + 2 == 5);
}