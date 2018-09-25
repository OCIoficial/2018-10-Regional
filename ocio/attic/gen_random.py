import sys
import random

random.seed(hash(str(sys.argv)))

cond1 = sys.argv[2] == '1'

if cond1:
    M = random.choice(range(50))+1;
else:
    M = random.choice(range(100000))+1;

print(M)
