def solution(s):
    stack = []
    for i in s:
        if i == '(':
            stack.append(i)
        else:
            if stack:
                stack.pop()
            else:
                return False
    return len(stack) == 0


# Test
print(solution("()()"))  # 반환값 : True
print(solution("(())()"))  # 반환값 : True
print(solution(")()("))  # 반환값 : False
print(solution("(()("))  # 반환값 : False
