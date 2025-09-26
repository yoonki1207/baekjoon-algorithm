# [Gold V] Icy Perimeter - 17025 

[문제 링크](https://www.acmicpc.net/problem/17025) 

### 성능 요약

메모리: 66356 KB, 시간: 76 ms

### 분류

그래프 이론, 그래프 탐색, 너비 우선 탐색, 깊이 우선 탐색

### 제출 일자

2025년 9월 27일 00:11:16

### 문제 설명

<p>Farmer John is going into the ice cream business! He has built a machine that produces blobs of ice cream but unfortunately in somewhat irregular shapes, and he is hoping to optimize the machine to make the shapes produced as output more reasonable.</p>

<p>The configuration of ice cream output by the machine can be described using an $N \times N$ grid ($1 \leq N \leq 1000$) as follows:</p>

<pre>##....
....#.
.#..#.
.#####
...###
....##
</pre>

<p>Each '.' character represents empty space and each '#' character represents a $1 \times 1$ square cell of ice cream.</p>

<p>Unfortunately, the machine isn't working very well at the moment and might produce multiple disconnected blobs of ice cream (the figure above has two). A blob of ice cream is connected if you can reach any ice cream cell from every other ice cream cell in the blob by repeatedly stepping to adjacent ice cream cells in the north, south, east, and west directions.</p>

<p>Farmer John would like to find the area and perimeter of the blob of ice cream having the largest area. The area of a blob is just the number of '#' characters that are part of the blob. If multiple blobs tie for the largest area, he wants to know the smallest perimeter among them. In the figure above, the smaller blob has area 2 and perimeter 6, and the larger blob has area 13 and perimeter 22.</p>

<p>Note that a blob could have a "hole" in the middle of it (empty space surrounded by ice cream). If so, the boundary with the hole also counts towards the perimeter of the blob. Blobs can also appear nested within other blobs, in which case they are treated as separate blobs. For example, this case has a blob of area 1 nested within a blob of area 16:</p>

<pre>#####
#...#
#.#.#
#...#
#####
</pre>

<p>Knowing both the area and perimeter of a blob of ice cream is important, since Farmer John ultimately wants to minimize the ratio of perimeter to area, a quantity he calls the icyperimetric measure of his ice cream. When this ratio is small, the ice cream melts slower, since it has less surface area relative to its mass.</p>

### 입력 

 <p>The first line of input contains $N$, and the next $N$ lines describe the output of the machine. At least one '#' character will be present.</p>

### 출력 

 <p>Please output one line containing two space-separated integers, the first being the area of the largest blob, and the second being its perimeter. If multiple blobs are tied for largest area, print the information for whichever of these has the smallest perimeter.</p>

