def solution(s):
    answer = 0

    def check(s):
        stack = []
        for c in s:
            if c in ['(', '{', '[']:
                stack.append(c)
            else:
                if len(stack) == 0:
                    return False
                if c == ')' and stack[-1] == '(':
                    stack.pop()
                elif c == '}' and stack[-1] == '{':
                    stack.pop()
                elif c == ']' and stack[-1] == '[':
                    stack.pop()
                else:
                    return False
        return len(stack) == 0

    for i in range(len(s)):
        new_s = s[i:] + s[:i]
        if check(new_s):
            answer += 1

    return answer