"""
steps.py receives the desired values for M, N and a list of steps. Each
step starts in the position passed in sys.argv[i] (inclusive), has height
sys.argv[i+1] and ends in the position sys.argv[i+2] (not inclusive). All
steps are consecutive so the ending position of one step is the starting
position of the next. The starting position of the first step is always 0
so it is omitted, and the ending position of the last step is always N so
it is omitted too.

Example:

$ python steps.py 12 10 2 4 1 7 3

Generates:
12 10
2 2 2 2 1 1 1 3 3 3
"""
import sys


m = int(sys.argv[2])
n = int(sys.argv[3])

if len(sys.argv) % 2 == 0 or len(sys.argv) < 5:
  exit(-1)

print(m, n)

samples = [0] * n

i_v = 4
i_r = 5
i_s = 0

for i_s in range(n):
  while i_r < len(sys.argv) and i_s >= int(sys.argv[i_r]):
    i_r += 2
    i_v += 2
  samples[i_s] = sys.argv[i_v]

print(' '.join(samples))
