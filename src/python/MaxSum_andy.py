import math, statistics


#flag이면 한줄에 두개씩 coordinates 들어오는 txt파일
#!flag이면 s 행렬을 읽는다
flag = True




lmda = 0

input_filename = "maxsum_3dtest1"
if flag:
    # #region input
    
    coordinates = open(input_filename + ".txt",'r')
    coor = []
    lines = coordinates.readlines()
    coordinates.close()
    for line in lines:
        coor.append(tuple(map(float,line.split())))
    n=coor.pop(0)[0]
    n=int(n+.5)//2
    if len(coor[0])==2:
        is_3d=False
    else:
        is_3d=True
    # #endregion

    #region girlboy
    girl = [coor[i] for i in range(n)]
    boy = [coor[i] for i in range(n,2*n)]
    #endregion
    def simil(p1,p2):
        return -math.sqrt((p1[0]-p2[0])**2+(p1[1]-p2[1])**2+(0 if not is_3d else (p1[2]-p2[2])**2))
    s=[[0]*n for i in range(n)]
    for i in range(n):
        for j in range(n):
            s[i][j]=simil(girl[i],boy[j])
else:
    s=[]
    txtfile = open(input_filename + ".txt",'r')
    lines = txtfile.readlines()
    n=lines.pop(0)
    n=int(int(n)+.5)//2
    for line in lines:
        s.append(list(map(float,line.split())))
    


a=[[0]*n for i in range(n)]
rho=[[0]*n for i in range(n)]

#iter iterations
iter = 100
for it in range(iter):
    print(f"{100*it/iter}%")
    for i in range(n):
        twomax = [-math.inf, -math.inf]
        ind_twomax = [-1,-1]
        for kk in range(n):
            tmp = s[i][kk]+a[i][kk]
            if tmp>twomax[0]:
                twomax[1]=twomax[0]
                twomax[0]=tmp
                ind_twomax[1]=ind_twomax[0]
                ind_twomax[0]=kk
            elif tmp>twomax[1]:
                twomax[1]=tmp
                ind_twomax[1]=kk
        #print(twomax,ind_twomax,s[i],a[i])
        for j in range(n):
            if ind_twomax[0]==j:
                rho[i][j]*=lmda
                rho[i][j]+=(s[i][j]-twomax[1])*(1-lmda)
            else:
                rho[i][j]*=lmda
                rho[i][j]+=(s[i][j]-twomax[0])*(1-lmda)
    #a[i][j]
    for j in range(n):
        #region twomax rho[kk][j]
        twomax = [-math.inf, -math.inf]
        ind_twomax = [-1,-1]
        for kk in range(n):
            tmp = rho[kk][j]
            if tmp>twomax[0]:
                twomax[1]=twomax[0]
                twomax[0]=tmp 
                ind_twomax[1]=ind_twomax[0]
                ind_twomax[0]=kk
            elif tmp>twomax[1]:
                twomax[1]=tmp
                ind_twomax[1]=kk
        #endregion

        for i in range(n):
            if i==ind_twomax[0]:
                a[i][j]*=lmda
                a[i][j]+=(-twomax[1])*(1-lmda)
            else:
                a[i][j]*=lmda
                a[i][j]+=(-twomax[0])*(1-lmda)

lines = []
mat = [[0]*n for i in range(n)]
for i in range(n):
    for j in range(n):
        if a[i][j]+rho[i][j]>0:
            mat[i][j]=1
            lines.append((i,j))
for i in range(n):
    for j in range(n):
        mat[i][j]=a[i][j]+rho[i][j]
# print(a)
# print(rho)
# print(mat)
print(len(lines))
# print(girl,boy)
print(*lines)
output_file = open(input_filename+'_maxsumoutput.txt','w')
for x in lines:
    output_file.write(f"{x[0]} {x[1]}\n")
output_file.close()

