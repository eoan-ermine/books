// Ident is arbitrarily long sequence
// of digits, underscores, lowercase
// and uppercase Latin letters, and Unicode
// characters specified using \u and \U

// First char == non-digit character

int main() {
    const char *\U0001f431 = "cat";
    const char *🐕  = "dog"; // implementation-defined
}