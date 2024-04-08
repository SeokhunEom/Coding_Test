def solution(n, k, cmd):
    ans = ['O'] * n
    up = [i - 1 for i in range(n + 2)]
    down = [i + 1 for i in range(n + 2)]
    stack = []
    k = k + 1

    for c in cmd:
        arr = c.split(' ')
        if arr[0] == 'U':
            X = int(arr[1])
            for _ in range(X):
                k = up[k]
        elif arr[0] == 'D':
            X = int(arr[1])
            for _ in range(X):
                k = down[k]
        elif arr[0] == 'C':
            stack.append(k)
            up[down[k]] = up[k]
            down[up[k]] = down[k]
            k = up[k] if n < down[k] else down[k]
        elif arr[0] == 'Z':
            t = stack.pop()
            down[up[t]] = t
            up[down[t]] = t

    for i in stack:
        ans[i - 1] = 'X'
    answer = "".join(ans)

    return answer