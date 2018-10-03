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

#Octavo argmento: poner casos borde
L=int(sys.argv[9])

vi=2
V=1
n=random.randint(n_l, n_r)
R=random.randint(R_l, R_r)
w=random.randint(w_l, max(w_l, n-w_r))
if L==1:
    w=50010
print(str(n))
print(str(w)+" "+str(V))
print(str(R))
st=n-w
minwi=w-st+1
i=0
if WIN==0:
    if L==1:
        looser=int(R/2)
        while i<R:
            if i==looser:
                print("16 "+str(vi))
                i=i+1
            wi=random.randint(0, 5)
            print(str(wi)+" "+str(vi))
            i=i+1
    looser=random.randint(0, R-1)
    while i<R:
        if looser==i:
            wi=max(w-(st-1), 0)
            print(str(wi)+" "+str(vi))
            i=i+1
            continue
        wi=random.randint(0, n-1)
        print(str(wi)+" "+str(vi))
        i=i+1
elif WIN==1:
    if L==1:
        while i<R:
            wi=random.randint(0, 5)
            print(str(wi)+ "+str(vi))
            i=i+1
    while i<R:
        wi=random.randint(w+1, n-1)
        j=random.randint(0, 1)
        if minwi>0 and j==1:
            wi=random.randint(0, minwi-1)
        print(str(wi)+" "+str(vi))
        i=i+1
else:
    while i<R:
        wi=random.randint(0, n-1)
        print(str(wi)+" "+str(vi))
        i=i+1
        
