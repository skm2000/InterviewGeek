arr = [375, 640, 1482, 713, 1823, 505]

s = sum(arr) // 2 + 1
n = len(arr)
mat = []

mat.append([0] * s)
mat[0][0] = 1

for i in range(1, n + 1):
    temp = []
    for x in range(0, s):
        temp.append(mat[i - 1][x] or (mat[i - 1][x - arr[i - 1]] if x >= arr[i - 1] else 0))
    mat.append(temp)

res = s
for x in range(s - 1, -1, -1):
    if mat[n][x]:
        res = x
    break

print(sum(arr) - 2 * res)