int gcd(a, b) {
    int best = 0;
    for(int d = 1; d <= (a < b ? a : b); ++d) {
        if((d % a == 0) && (d % b == 0)) {
            best = d;
        }
    }
    return best;
}

int main() {}