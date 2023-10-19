# 0x09강 - BFS

## 0x00 알고리즘 설명

- BFS(Breadth First Search, 너비 우선 탐색)는 다차원 배열에서 각 칸을 방문할 때 너비를 우선으로 방문하는 알고리즘이다.

## 0x01 예시

1. 시작하는 칸을 큐에 넣고 방문했다는 표시를 남긴다.
2. 큐에서 원소를 꺼내어 그 칸에 상하좌우로 인접한 칸에 대해 3번을 진행한다.
3. 해당 칸을 처음 방문했다면 방문했다는 표시를 남기고 해당 칸을 큐에 삽입한다.
4. 큐가 빌 때 까지 2번을 반복한다.

- 모든 칸이 큐에 1번씩 들어가므로 시간복잡도는 칸이 N개일 때 O(N)이다.

## 0x02 응용 1 - 거리 측정

- BFS를 이용하면 시작점에서 연결된 다른 모든 점으로의 최단 경로를 찾을 수 있다.

## 0x03 응용 2 - 시작점이 여러 개일 때

- 시작점이 여러 개일 때는 모든 시작점을 큐에 넣고 BFS를 돌면 된다.
- 이렇게 진행하게 되면 큐에 쌓이는 순서는 반드시 거리 순이게 된다.

## 0x04 응용 3 - 시작점이 두 종류일 때

- 시작점이 두 종류일 때는 각 시작점에 대해서 BFS를 따로 돌려주면 된다.
- 다만 두개의 BFS가 서로에게 영향을 준다면 백트래킹 기법을 알고 있어야 해결할 수 있다.

## 0x05 응용 4 - 1차원에서의 BFS

- 1차원에서도 동일하게 큐를 이용해서 BFS를 돌면 된다.
- 이 때, BFS를 범위를 어디까지로 해야할 지 고민해 봐야 한다.

## 0x06 연습문제

| 문제 제목                                                    | 내 코드                                                      |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [1926. 그림](https://www.acmicpc.net/problem/1926)           | [1926.cpp](https://github.com/tommya98/Coding-test/blob/main/Baekjoon%20code/1926.cpp) |
| [2178. 미로 탐색](https://www.acmicpc.net/problem/2178)      | [2178.cpp](https://github.com/tommya98/Coding-test/blob/main/Baekjoon%20code/2178.cpp) |
| [7576. 토마토](https://www.acmicpc.net/problem/7576)         | [7576.cpp](https://github.com/tommya98/Coding-test/blob/main/Baekjoon%20code/7576.cpp) |
| [4179. 불!](https://www.acmicpc.net/problem/4179)            | [4179.cpp](https://github.com/tommya98/Coding-test/blob/main/Baekjoon%20code/4179.cpp) |
| [1697. 숨바꼭질](https://www.acmicpc.net/problem/1697)       | [1697.cpp](https://github.com/tommya98/Coding-test/blob/main/Baekjoon%20code/1697.cpp) |
| [1012. 유기농 배추](https://www.acmicpc.net/problem/1012)    | [1012.cpp](https://github.com/tommya98/Coding-test/blob/main/Baekjoon%20code/1012.cpp) |
| [10026. 적록색약](https://www.acmicpc.net/problem/10026)     | [10026.cpp](https://github.com/tommya98/Coding-test/blob/main/Baekjoon%20code/10026.cpp) |
| [7569. 토마토](https://www.acmicpc.net/problem/7569)         | [7569.cpp](https://github.com/tommya98/Coding-test/blob/main/Baekjoon%20code/7569.cpp) |
| [7562. 나이트의 이동](https://www.acmicpc.net/problem/7562)  | [7562.cpp](https://github.com/tommya98/Coding-test/blob/main/Baekjoon%20code/7562.cpp) |
| [5427. 불](https://www.acmicpc.net/problem/5427)             | [5427.cpp](https://github.com/tommya98/Coding-test/blob/main/Baekjoon%20code/5427.cpp) |
| [2583. 영역 구하기](https://www.acmicpc.net/problem/2583)    | [2583.cpp](https://github.com/tommya98/Coding-test/blob/main/Baekjoon%20code/2583.cpp) |
| [2667. 단지번호붙이기](https://www.acmicpc.net/problem/2667) | [2667.cpp](https://github.com/tommya98/Coding-test/blob/main/Baekjoon%20code/2667.cpp) |
| [5014. 스타트링크](https://www.acmicpc.net/problem/5014)     | [5014.cpp](https://github.com/tommya98/Coding-test/blob/main/Baekjoon%20code/5014.cpp) |
| [2468. 안전 영역](https://www.acmicpc.net/problem/2468)      | [2468.cpp](https://github.com/tommya98/Coding-test/blob/main/Baekjoon%20code/2468.cpp) |
| [6593. 상범 빌딩](https://www.acmicpc.net/problem/6593)      | [6593.cpp](https://github.com/tommya98/Coding-test/blob/main/Baekjoon%20code/6593.cpp) |
| [2206. 벽 부수고 이동하기](https://www.acmicpc.net/problem/2206) | -                                                            |
| [9466. 텀 프로젝트](https://www.acmicpc.net/problem/9466)    | -                                                            |
| [2573. 빙상](https://www.acmicpc.net/problem/2573)           | -                                                            |
| [2146. 다리 만들기](https://www.acmicpc.net/problem/2146)    | -                                                            |
| [13549. 숨바꼭질 3](https://www.acmicpc.net/problem/13549)   | -                                                            |
| [1600. 말이 되고픈 원숭이](https://www.acmicpc.net/problem/1600) | -                                                            |
| [13913. 숨바꼭질 4](https://www.acmicpc.net/problem/13913)   | -                                                            |
| [14442. 벽 부수고 이동하기 2](https://www.acmicpc.net/problem/14442) | -                                                            |
| [16933. 벽 부수고 이동하기 3](https://www.acmicpc.net/problem/16933) | -                                                            |
| [16920. 확장 게임](https://www.acmicpc.net/problem/16920)    | -                                                            |
| [11967. 불켜기](https://www.acmicpc.net/problem/11967)       | -                                                            |
| [17071. 숨바꼭질 5](https://www.acmicpc.net/problem/17071)   | -                                                            |
| [9328. 열쇠](https://www.acmicpc.net/problem/9328)           | -                                                            |
| [3197. 백조의 호수](https://www.acmicpc.net/problem/3197)    | -                                                            |
| [20304. 비밀번호 제작](https://www.acmicpc.net/problem/20304) | -                                                            |

