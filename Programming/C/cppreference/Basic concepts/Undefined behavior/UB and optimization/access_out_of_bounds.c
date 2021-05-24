int table[4] = {0};
int exists_in_table(int v) {
    for(int i = 0; i <= 4; ++i) {
        if(table[i] == v) return 1;
    }
    return 0;
}

// May be compiled as

//  exists_in_table:
//      movl $1, %eax
//      ret

// 'Cause of compiler assume
// we won't make UB, so, v is 0