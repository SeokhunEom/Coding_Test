def solution(N, stages):
    answer = [0] * N

    total = len(stages)
    player = [0] * (N + 2)
    fail = {}
    for stage in stages:
        player[stage] += 1

    for i in range(1, N + 1):
        if player[i] == 0:
            fail[i] = 0
        else:
            fail[i] = player[i] / total
            total -= player[i]

    answer = sorted(fail, key=lambda x: fail[x], reverse=True)
    print(answer)

    return answer