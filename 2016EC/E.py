import math
T = int(input())

for step in range(T):
    n = int(input())
    Sco = []
    for i in range(n):
        data = input().split(":")
        a = int(float(data[0]) * 10000)
        b = int(float(data[1]) * 10000)
        b = a + b
        Sco.append((int(a),int(b)))
    for i in range(n-1):
        for j in range(n-1):
            if Sco[j][0]*Sco[j+1][1]>Sco[j][1]*Sco[j+1][0]:
                tmp = Sco[j]
                Sco[j]=Sco[j+1]
                Sco[j+1]=tmp
    tot = (0,1)
    f = 0
    for i in range(n):
        tot = (int(tot[0]*Sco[i][1]+tot[1]*Sco[i][0]),int(tot[1]*Sco[i][1]))
        if tot[0]>=tot[1]:
            print("Case #"+str(step+1)+": "+str(i))
            f = 1
            break
    if f == 0 :
        print("Case #"+str(step+1)+": "+str(n))