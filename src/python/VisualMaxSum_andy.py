import matplotlib.pyplot as plt
import random
import numpy as np

def randcolor():
    return "#"+''.join([random.choice('ABCDEF0123456789') for i in range(6)])

#region input
input_filename = "maxsum_3dtest1"
coordinates = open(input_filename + ".txt",'r')
coor = []
lines = coordinates.readlines()
coordinates.close()
for line in lines:
    coor.append(tuple(map(float,line.split())))
n=coor.pop(0)[0]
n=int(n+.5)
if len(coor[0])==2:
    is_3d=False
else:
    is_3d=True
#endregion


#region girlboy
n//=2
girl = [coor[i] for i in range(n)]
boy = [coor[i] for i in range(n,2*n)]
#endregion
if not is_3d:
    for i in range(n):
        plt.plot([girl[i][0]],[girl[i][1]],color = 'red', marker = '.')
        plt.plot([boy[i][0]],[boy[i][1]],color = 'blue', marker = '.')


    op = open(input_filename + '_maxsumoutput.txt','r')
    lines = op.readlines()
    for line in lines:
        i,j=map(int,line.split())
        plt.plot([girl[i][0],boy[j][0]],[girl[i][1],boy[j][1]], color = 'black')
    op.close()
    plt.title('Matching by Max-Sum Algorithm ('+r'$n=$'+str(n)+')',size=14)
    plt.savefig(f"maxsum_2d_n={n}.png", dpi = 800)
    plt.show()
else:
    fig = plt.figure(figsize=(9,6))
    ax = fig.add_subplot(111, projection = '3d')
    for i in range(n):
        ax.scatter([girl[i][0]],[girl[i][1]],[girl[i][2]],color = 'red', alpha = 0.8)
        ax.scatter([boy[i][0]],[boy[i][1]],[boy[i][2]],color = 'blue', alpha = 0.8)
    
    op = open(input_filename + '_maxsumoutput.txt','r')
    lines = op.readlines()
    for line in lines:
        i,j=map(int,line.split())
        ax.plot([girl[i][0],boy[j][0]], [girl[i][1],boy[j][1]], [girl[i][2],boy[j][2]], color = 'black')
    op.close()
    plt.title('Matching by Max-Sum Algorithm ('+r'$n=$'+str(n)+'), 3D', size = 14)
    plt.savefig(f"maxsum_3d_n={n}.png", dpi = 800)
    plt.show()
