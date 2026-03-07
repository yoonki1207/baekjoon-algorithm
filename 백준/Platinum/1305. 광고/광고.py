# 문자열 - 광고 (백준 플래4)
# 문제 링크: https://www.acmicpc.net/problem/1305

def build_lps(pattern: str):
    lps = [0] * len(pattern)
    length = 0
    i = 1
    while i < len(pattern):
        if pattern[length] == pattern[i]:
            length += 1
            lps[i] = length
            i += 1
        else:
            if length == 0:
                lps[i] = 0
                i += 1
            else:
                length = lps[length - 1]
    return lps
                

N = int(input())
s = input()

print(len(s) - build_lps(s)[-1])