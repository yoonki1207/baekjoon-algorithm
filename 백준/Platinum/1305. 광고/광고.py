# 문자열 - 광고 (백준 플래4)
# 문제 링크: https://www.acmicpc.net/problem/1305

'''
KMP 문제
광고판 L의 prefix와 같은 suffix를 지운 문자가 제일 짧은 광고이다.
ABBAB이면 AB가 같으므로 ABB가 광고의 길이가 가장 긴 경우이다.
'''

# length prefix suffix
def build_lps(pattern: str):
    lps = [0] * len(pattern)
    length = 0 # 비교할 문장의 index. 즉, pattern
    i = 1 # 순회하는 index. 즉, string
    while i < len(pattern): # 순회
        if pattern[length] == pattern[i]: # 같으면
            length += 1 
            lps[i] = length # 증가된 길이 저장
            i += 1
        else: # 다르면
            if length == 0:
                lps[i] = 0
                i += 1
            else: # 다르면 순회하지 말 것. 점프 후 제자리부터 다시 검사해야함.
                length = lps[length - 1] # 점프
    return lps
                

N = int(input())
s = input()

print(len(s) - build_lps(s)[-1])