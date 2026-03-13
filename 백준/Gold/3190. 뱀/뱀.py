# 큐 - 뱀 (백준 골드4)
# 문제 링크: https://www.acmicpc.net/problem/3190

N = int(input())
apple_num = int(input())
board = [[0 for _ in range(N + 1)] for _ in range(N + 1)]
for i in range(apple_num):
    y, x = map(int, input().split())
    board[y][x] = 1
L = int(input())

commands = [0]* L
for i in range(L):
    time, cmd = input().split()
    commands[i] = (int(time), cmd)
commands.sort()

TOP = 0
LEFT = 1
BOTTOM = 2
RIGHT = 3
OFFSET = [(1, 0), (0, -1), (-1, 0), (0, 1)]

def rotateSnake(turn):
    global snake_direction
    if turn == 'L':
        snake_direction += 3
    else:
        snake_direction += 1
    snake_direction %= 4
    return

def checkRange(y, x):
    return y >= 1 and x >= 1 and y <= N and x <= N

snake_direction = RIGHT
snake_coord = (1, 1)
snake_path = [(1, 1)]
board[1][1] = 2
snake_size = 1
time_passed = 0
time_i = 0

while True:
    # turn
    if time_i < len(commands) and time_passed == commands[time_i][0]:
        rotateSnake(commands[time_i][1])
        time_i += 1
        pass
    # move
    ny = snake_coord[0] + OFFSET[snake_direction][0]
    nx = snake_coord[1] + OFFSET[snake_direction][1]
    # print(ny, nx)
    if not checkRange(ny, nx): # hit walls
        # Game Over: Hit
        # print("Wall hit!!")
        break
    if board[ny][nx] == 1: # apple
        # print("Eat Apple")
        # Eat apple
        snake_size += 1
        pass
    elif board[ny][nx] == 2: # hit body
        # print("Body shot")
        # Game Over: Hit
        break
    else: # move
        tail_y, tail_x = snake_path.pop(0)
        board[tail_y][tail_x] = 0
        pass
    snake_path.append((ny, nx))
    board[ny][nx] = 2
    snake_coord = (ny, nx)
    
    # push path

    time_passed += 1
    pass

print(time_passed + 1)