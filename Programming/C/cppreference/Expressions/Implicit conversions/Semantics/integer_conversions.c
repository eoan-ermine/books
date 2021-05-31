int main() {
    // if the target type can represent the value, the value is unchanged
    
    // otherwise, if the target is unsigned, the value 2^b is reapetedly
    // subtracted or added to the source value until the result fits
    // in the target type

    // otherwise, if the target type is signed, the behavior is implementation-defined

    char x = 'a';
    unsigned char n = -123456; // the target is unsigned, result is 192
    signed char m = 123456; // result is impl-defined
    assert(sizeof(int) > -1);   // assert fails:
                                // operator > requests conversion of -1 to size_t
                                // target is unsigned, result is SIZE_MAX
}