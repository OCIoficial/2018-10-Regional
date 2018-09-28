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
