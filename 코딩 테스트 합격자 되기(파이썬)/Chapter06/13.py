def solution(board, moves):
    answer = 0
    N = len(board)
    stack = []

    for move in moves:
        for i in range(N):
            if board[i][move - 1] != 0:
                if stack and stack[-1] == board[i][move - 1]:
                    stack.pop()
                    answer += 2
                else:
                    stack.append(board[i][move - 1])
                board[i][move - 1] = 0
                break

    return answer