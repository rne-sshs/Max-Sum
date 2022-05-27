import random

n=500
is_3d = True

filename = 'maxsum_3dtest1'
maxcoor = 1000
file = open(filename+'.txt','w')
file.write(str(n)+"\n")
if not is_3d:
    for i in range(n):
        r1=random.uniform(0,maxcoor)
        r2=random.uniform(0,maxcoor)
        file.write(f"{r1} {r2}\n")
else:
    for i in range(n):
        r1=random.uniform(0,maxcoor)
        r2=random.uniform(0,maxcoor)
        r3=random.uniform(0,maxcoor)
        file.write(f"{r1} {r2} {r3}\n")
file.close()
