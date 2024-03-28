def solution(dirs):
    cur_x, cur_y = 0, 0
    s = set()

    for d in dirs:
        nxt_x, nxt_y = cur_x, cur_y
        if d == 'U':
            if cur_y < 5:
                nxt_y += 1
        elif d == 'D':
            if cur_y > -5:
                nxt_y -= 1
        elif d == 'R':
            if cur_x < 5:
                nxt_x += 1
        elif d == 'L':
            if cur_x > -5:
                nxt_x -= 1
        if cur_x != nxt_x or cur_y != nxt_y:
            s.add((cur_x, cur_y, nxt_x, nxt_y))
            s.add((nxt_x, nxt_y, cur_x, cur_y))
            cur_x, cur_y = nxt_x, nxt_y

    answer = len(s) // 2

    return answer