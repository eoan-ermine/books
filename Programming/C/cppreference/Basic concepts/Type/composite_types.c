// Given the following two file scope declarations:
int f(int (*)(), double (*)[3]);
int f(int (*)(char *), double (*)[]);
// The resulting composite type for the function is:
int f(int (*)(char *), double (*)[3]);