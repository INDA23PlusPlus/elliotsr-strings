def build_table(pattern):
    table = [-1] * (len(pattern) + 1)
    i = 1
    j = 0
    while i < len(pattern):
        if pattern[i] == pattern[j]:
            table[i] = table[j]
        else:
            table[i] = j
            while j >= 0 and pattern[i] != pattern[j]:
                j = table[j]
        i += 1
        j += 1
    table[i] = j
    return table

def solve(s):
    n = len(s)
    table = build_table(s)
    lps = table[-1]
    k = n - lps
    if lps > 0 and n % k == 0:
        return n // k
    else:
        return 1

while (s := input()) != '.':
    print(solve(s))