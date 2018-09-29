import sys
import random

random.seed(hash(str(sys.argv)))
#Primer argumento: Subtask
#   0: Subtask 1
#   1: Subtask 2
#   2: Other
S=int(sys.argv[2])

#Segundo argumento: Sobre la respuesta
#   0: NO
#   1: SI
#   2: random
Win=int(sys.argv[3])

#Tercer argumento: Limite inferior de n
n_l=int(sys.argv[4])

#Cuarto argumento: Limite superior de n
n_r=int(sys.argv[5])

#Quinto argumento: Limite inferior de k
k_l=int(sys.argv[6])

#Sexto argumento: Limite superior de k
k_r=int(sys.argv[7])

#Septimo argumento: Limite inferior de los movimientos de los lasers
m_l=int(sys.argv[8])

#Octavo argumento: Limite superior de los movimientos de los lasers
m_r=int(sys.argv[9])

#Noveno argumento: Limite inferior de L
L_l=int(sys.argv[10])

#Decimo argumento: Limite superior de L
L_r=int(sys.argv[11])

#Onceavo argumento: Segmento de posicion de x
#   x se situa en [1:onX]
onX=int(sys.argv[12])

n=random.randint(n_l, n_r)
x=random.randint(1, min(onX, n-1)-2)
L=random.randint(L_l, min(n-x, L_r))
k=random.randint(k_l, k_r)

#segundos para llegar ganar
st=int((n-x+L-1)/L)
print(str(n)+" "+str(x)+" "+str(L)+" "+str(k))
i=0

#Subtask 1
if S==0:
    ci=1
    mi=2
    if WIN==0:
        looser=random.randint(0, k-1)
        while i<k:
            if i==looser:
                ai=random.randint(2*x-n+2, x-1)
                print(str(ai)+" "+str(mi)+" "+str(ci))
                i=i+1
                continue
            ai=random.randint(0, n-1)
            print(str(ai)+" "+str(mi)+" "+str(ci))
            i=i+1
    elif WIN==1:
        while i<k:
            ai=random.randint(x, n-1)
            if 2*x-n+2>=0 and i%2==0:
                ai=random.randint(0, 2*x-n+2)
            print(str(ai)+" "+str(mi)+" "+str(ci))
            i=i+1
    else:
        while i<k:
            ai=random.randint(0, n-1)
            print(str(ai)+" "+str(mi)+" "+str(ci))
            i=i+1

#Subtask 2
if S==1:
    ci=-1
    mi=1
    if WIN==0:
        looser=random.randint(0, k-1)
        while i<k:
            if i==looser:
                ai=random.randint(x+2, n-2)
                distance=ai-x
                if distance%2==1:
                    ai=ai+1
                print(str(ai)+" "+str(mi)+" "+str(ci))
                i=i+1
                continue
            ai=random.randint(0, n-1)
            print(str(ai)+" "+str(mi)+" "+str(ci))
            i=i+1
    elif WIN==1:
        while i<k:
            ai=random.randint(0, x)
            if i%2==0:
                ai=random.randint(x, n-2)
                distance=ai-x
                if distance%2==0 and distance!=0:
                    ai=ai+1
            print(str(ai)+" "+str(mi)+" "+str(ci))
            i=i+1
    else:
        while i<k:
            ai=random.randint(0, n-1)
            print(str(ai)+" "+str(mi)+" "+str(ci))
            i=i+1

#Other
if WIN==0 or WIN==2:
    looser=random.randint(0, k-1)
    if WIN==2:
        looser=-1
    while i<k:
        if i==looser:
            PosicionFinal=x+L*(st-1)
            ai=PosicionFinal-st+1
            mi=1
            ci=1
            print(str(ai)+" "+str(mi)+" "+str(ci))
            i=i+1
            continue
        ai=random.randint(0, n-1)
        ci=-1
        cI=random.randint(0, 1)
        ci=ci+cI*2
        mi=random.randint(m_l, m_r)
        print(str(ai)+" "+str(mi)+" "+str(ci))
        i=i+1
elif WIN==1:
    while i<k:
        ai=0
        mi=0
        flag=True
        ci=-1
        cI=random.randint(0, 1)
        ci=ci+cI*2
        mi=random.randint(m_l, m_r)
        while flag:
            flag=False
            ai=random.randint(0, n-1)
            if ai>=x:
                distance=ai-x
                module=L-ci*mi
                if module==0 and ai==x and x+L<n and ai+ci*mi==x+L:
                    flag=True
                if module>0 and distance%module==0 and distance/module<st:
                    flag=True
            else:
                distance=x-ai
                module=ci*mi-L
                if module>0 and distance%module==0 and distance/module<st:
                    flag=True
        print(str(ai)+" "+str(mi)+" "+str(ci))
        i=i+1
