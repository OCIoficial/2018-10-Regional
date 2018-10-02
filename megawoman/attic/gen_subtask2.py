import sys
import random

random.seed(hash(str(sys.argv)))

#Primer argumento: Sobre la respuesta
#   0: NO
#   1: SI
#   2: random
WIN=int(sys.argv[2])

#Segundo argumento: Limite inferior de n
n_l=int(sys.argv[3])
#Tercer argumento: Limite superior de n
n_r=int(sys.argv[4])

#Cuarto argumento: Limite inferior de R
R_l=int(sys.argv[5])
#Quinto argumento: Limite superior de R
R_r=int(sys.argv[6])

#Sexto argumento: Limite inferior de w
w_l=int(sys.argv[7])
#Septimo argumento: Limite superior de w
w_r=int(sys.argv[8])

vi=-1
V=1
n=random.randint(n_l, n_r)
R=random.randint(R_l, R_r)
w=random.randint(w_l, max(w_l, n-w_r))

print(str(n))
print(str(w)+" "+str(V))
print(str(R))
st=n-w

i=0
if WIN==0:
    looser=random.randint(0, R-1)
    while i<R:
        if looser==i:
            wi=n-2
            if (wi-w)%2==1:
                wi=wi+1
            print(str(wi)+" "+str(vi))
            i=i+1
            continue
        wi=random.randint(0, n-1)
        print(str(wi)+" "+str(vi))
        i=i+1
elif WIN==1:
    while i<R:
        wi=random.randint(0, n-2)
        if wi==w:
            wi=wi-1
        if wi>w:
            if (wi-w)%2==0:
                wi=wi+1
        print(str(wi)+" "+str(vi))
        i=i+1
else:
    while i<R:
        wi=random.randint(0, n-1)
        print(str(wi)+" "+str(vi))
        i=i+1
        
