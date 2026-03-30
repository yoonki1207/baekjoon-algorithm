
N, L, W, H = map(int, input().split())

def enough(a):
    return (L//a) * (W//a) * (H//a) >= N

def bin_search():
    MAX_A = 1000000000
    left = 0
    right = MAX_A
    last = left
    cnt = 0
    while round(left, 11) < round(right, 11) and cnt < 10000:
        cnt += 1
        mid = (left + right) / 2;
        if enough(mid):
            last = mid
            left = mid
        else:
            right = mid
    # print(left, right, mid)
    return round(last, 10)

a = bin_search()
print(a)
# print(((W*H*L)/N)**(1/3))