def solution(arr):
    new_arr = list(set(arr))
    new_arr.sort(reverse=True)
    return new_arr


# Test
print(solution([4, 2, 2, 1, 3, 4]))  # 반환값 : [4, 3, 2, 1]
print(solution([2, 1, 1, 3, 2, 5, 4]))  # 반환값 : [5, 4, 3, 2, 1]
