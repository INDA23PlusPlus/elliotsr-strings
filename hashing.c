#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 300000

typedef __uint64_t u64;
typedef __uint128_t u128;

static const u64 M = 207790001816285477;
static const u64 R = 811;

u128 ppow[N];
u128 phash[N + 1];

void init_power_table(void) {
    ppow[0] = 1;
    for(int i = 1; i < N; i++) {
        ppow[i] = ppow[i - 1] * R % M;
    }
}

void init_hash_table(const char* s) {
    int n = strlen(s);
    for (int i = 0; i < n; i++) {
        phash[i + 1] = (phash[i] * R % M + (s[i] - 'a' + 1)) % M;
    }
}

int main(void) {

    char s[N + 1];
    u64 q;
    u64 l, r;

    init_power_table();

    scanf("%s", s);
    init_hash_table(s);

    scanf("%lu", &q);
    for (int i = 0; i < q; i++) {
        scanf("%lu %lu", &l, &r);
        u128 left = phash[l] * ppow[r - l] % M;
        u128 right = phash[r] % M;
        u128 hash = (M + right - left) % M;
        printf("%llu\n", hash);
    }
}