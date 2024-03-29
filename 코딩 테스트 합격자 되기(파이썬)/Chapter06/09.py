def solution(n):
    stack = []
    while n > 0:
        stack.append(n % 2)
        n //= 2

    result = ''.join(str(x) for x in reversed(stack))

    return result


# Test
print(solution(10))  # 반환값 :  1010
print(solution(27))  # 반환값 :  11011
print(solution(12345))  # 반환값 : 11000000111001
