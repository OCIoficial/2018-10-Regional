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

#Octavo argumento: Limite inferior de V
V_l=int(sys.argv[9])
#Noveno argumento: Limite superior de V
V_r=int(sys.argv[10])

#Decimo argumento: Limite inferior de v
v_l=int(sys.argv[11])
#Onceavo argumento: Limite superior de v
v_r=int(sys.argv[12])

i=0
if WIN==2:
    n=random.randint(n_l, n_r)
    R=random.randint(R_l, R_r)
    w=random.randint(w_l, max(w_l, n-w_r))
    V=random.randint(V_l, V_r)
    print(str(n))
    print(str(w)+" "+str(V))
    print(str(R))
    while i<R:
        vi=random.randint(v_l, v_r)
        wi=random.randint(0, n-1)
        print(str(wi)+" "+str(vi))
        i=i+1
elif WIN==0:
    n=random.randint(n_l, n_r)
    R=random.randint(R_l, R_r)
    w=random.randint(w_l, max(w_l, n-w_r))
    V=random.randint(V_l, min(V_r, n-w-1))
    print(str(n))
    print(str(w)+" "+str(V))
    print(str(R))
    looser=random.randint(0, R-1)
    while i<R:
        if (i==looser):
            vi=277
            wi=w+V-vi
            print(str(wi)+" "+str(vi))
            i=i+1
            continue
        vi=random.randint(v_l, v_r)
        wi=random.randint(0, n-1)
        print(str(wi)+" "+str(vi))
        i=i+1
else:
    n=random.randint(n_l, n_r)
    R=random.randint(R_l, R_r)
    w=random.randint(w_l, max(w_l, n-w_r))
    V=random.randint(V_l, V_r)
    st=(n-w+V-1)/V
    print(str(n))
    print(str(w)+" "+str(V))
    print(str(R))
    while i<R:
        vi=random.randint(v_l, v_r)
        wi=random.randint(0, n-2)
        if V==vi and wi==w and st>1:
           wi=wi+1
        elif V!=vi:
            if ((wi-w)%(V-vi)==0):
                if ((wi-w)/(V-vi)<=0 or (wi-w)/(V-vi)>=st):
                    wi=wi+1
        print(str(wi)+" "+str(vi))
        i=i+1
