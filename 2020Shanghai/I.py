import math

a = input().split()
n = int(a[0])
m = int(a[1])
pi = math.pi
ans = 0
if m != 1 :
    ans = n * m * (n + 1)
t = math.floor(2 * m / pi)
x = t * (t + 1) * pi + 2 * m * (2 * (m - t - 1) + 1)
for j in range(n):
    r = j + 1
    ans+=x*r+2*x*r*(n-r)+2*m*m*(n-r)*(n-r+1)
print('%.10f'%ans)

