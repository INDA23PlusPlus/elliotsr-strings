#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 300000
#define R 33
#define M 5381

int table[MAX_LEN];

void build_table(char* s) {
    int n = strlen(s);
    table[0] = 5381;
    for (int i = 0; i < n; i++) {
        int prev = i > 0 ? table[i - 1] : 0;
        table[i] = (prev * R + s[i]) % M;
    }
}

// Computes n to the power of p modulo m
int modpow(int n, int p, int m) {
    if (m == 1) return 0;
    int r = 1;
    for (int i = 0; i < p; i++) {
        r = (r * n) % m;
    }
    return r;
}

int query_table(int l, int r) {
    return (table[r] % M) - modpow(R, (r - l + 1), M) * (table[l - 1] % M);
}

int main(void) {
    char s[MAX_LEN];
    int q;
    int l, r;
    scanf("%s", s);
    build_table(s);
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        scanf("%d %d", &l, &r);
        int result = query_table(l, r);
        printf("%d\n", result);
    }
    return 0;
}