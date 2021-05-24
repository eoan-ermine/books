#include <stdio.h>

// envp is implementation-defined element of signature
int main(int argc, char *argv[], char *envp[]) {
    printf("argc = %d\n", argc);
    for(int ndx = 0; ndx != argc; ++ndx)
        printf("argv[%d] --> %s\n", ndx,argv[ndx]);
    printf("argv[argc] = %p\n\n", (void*)argv[argc]);

    for(int n = 0;; ++n) {
        if(envp[n] == NULL) break;
        printf("%s\n", envp[n]);
    }
}