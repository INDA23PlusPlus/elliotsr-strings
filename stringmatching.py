from sys import stdin    

def find_all(text, pattern):

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

    found = []
    table = build_table(pattern)
    i = 0
    j = 0
    while i < len(text):
        if pattern[j] == text[i]:
            i += 1
            j += 1
            if j == len(pattern):
                found.append(i - j)
                j = table[j]
        else:
            j = table[j]
            if j == -1:
                i += 1
                j += 1
    return found

flipflop = True
for line in stdin:
    if flipflop:
        pattern = line.rstrip()
    else:
        text = line.rstrip()
        found = find_all(text, pattern)
        print(' '.join(str(x) for x in found))
    flipflop = not flipflop