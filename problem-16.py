def binExp(a, b):
  ans = 1
  while b > 0:
    if b%2==1:
      ans *= a
    a = a*a
    b = b // 2
  return ans
def sumOfDig(n):
  sum = 0
  while (n > 0):
    sum += n%10
    n = int(n // 10)
  return sum
print(sumOfDig(binExp(2,1000)))
