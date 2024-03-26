def solution(answers):
    answer = []

    p1 = [1, 2, 3, 4, 5]
    p2 = [2, 1, 2, 3, 2, 4, 2, 5]
    p3 = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5]
    score = [0, 0, 0]

    for i in range(len(answers)):
        score[0] += p1[i % len(p1)] == answers[i]
        score[1] += p2[i % len(p2)] == answers[i]
        score[2] += p3[i % len(p3)] == answers[i]

    max_score = max(score)

    for i in range(3):
        if score[i] == max_score:
            answer.append(i + 1)

    return answer
