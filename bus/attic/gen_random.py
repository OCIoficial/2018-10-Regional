import sys
import random

random.seed(hash(str(sys.argv)))

# special tests:
#   0: anything
#   1: all ones
#   2: all even
#   3: all odd
sp = int(sys.argv[2])
max_n = int(sys.argv[3])

numbers = []
max_m = 48
while max_m > 0 and len(numbers) < max_n:
    m = random.randint(1, max_m)
    if sp == 1:
        m = 1
    elif sp == 2 and m % 2 != 0:
        m += 1
    elif sp == 3 and m % 2 == 0:
        m -= 1
    numbers.append(m)
    max_m -= m

print(len(numbers))
for elem in numbers:
    print elem
