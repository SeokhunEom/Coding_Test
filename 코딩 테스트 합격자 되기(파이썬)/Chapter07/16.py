import math


def solution(progresses, speeds):
    answer = []

    tmp = []
    for i in range(len(progresses)):
        tmp.append(math.ceil((100 - progresses[i]) / speeds[i]))

    idx = 0
    for i in range(len(tmp)):
        if tmp[i] > tmp[idx]:
            answer.append(i - idx)
            idx = i
    answer.append(len(tmp) - idx)

    return answer