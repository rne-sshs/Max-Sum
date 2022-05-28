Max-Sum
========
2022 SSHS R&E 

* 김선웅(seonu)
* 이지후(numbering)
* 박세진(exabyte)
* 정현우(andy)

내용
--------

### Max-Sum Algorithm
Max-Sum Belief Propagation: Factor Graph에서 노드 간 메세지를 통해 목적 함수의 합을 최대화하는 알고리즘.  
이를 Group Blind Date 상황에 적용 -> 모두의 만족도 합을 최대화하는 것이 목적.  
![image](https://user-images.githubusercontent.com/35063338/170415829-e2c5c1bb-147b-4d9a-ac1f-114f0ea98894.png)

### Input
남자와 여자를 좌표평면의 점으로 표현한 후, 남자와 여자 사이의 만족도를 유클리드 거리로 설정.  
<img src="https://user-images.githubusercontent.com/35063338/170417792-c08cb4cb-4052-4e70-88ea-d40a5f5f572b.png" width="300" height="200"/>

### Process
Max-Sum Belief Propagation으로 얻은 다음의 점화식을 수렴할 때까지 실행  
<img src="https://user-images.githubusercontent.com/35063338/170418111-c38a2e22-983c-4171-9cb3-e657d3cb2c71.png" width="330" height="100"/>  
수렴하면 고정된 $i$에 대하여 <img src="https://user-images.githubusercontent.com/35063338/170420172-e7f55132-b45b-45ae-acaf-7c0b31d39ad8.png" width="65" height="20"/>의 값이 양수가 되는 $j$와 연결

### Results 
#### $n$=250, $\lambda$=0.3 인 경우 iter에 따라
iter=1
![maxsum_2d_n=250_it=1](https://user-images.githubusercontent.com/89206053/170835771-59801d90-4e56-4abc-8d0a-d32069824919.png)
이어지지 않은 점이 많이 있다.  
   
iter=20
![maxsum_2d_n=250_it=20](https://user-images.githubusercontent.com/89206053/170835901-be91199a-1a9d-4e1d-9d64-b674585b1d71.png)
거의 모든 점이 이어져 있다.

iter=500(수렴)
![maxsum_2d_n=250_it=500](https://user-images.githubusercontent.com/89206053/170835945-55c83bb6-92a0-4c7d-b3e4-3bbd0155a0fe.png)
모든 붉은 점과 푸른 점이 쌍을 이루고 있다.

#### 3D Results

![maxsum_3d_n=50](https://user-images.githubusercontent.com/89206053/170775631-ec6cb3a0-6167-4599-bbae-1c55414f85ce.png)

![maxsum_3d_n=250](https://user-images.githubusercontent.com/89206053/170775026-34bd6777-a2e4-4c87-8f6c-e7dbdd038000.png)

![maxsum_3d_n=500](https://user-images.githubusercontent.com/89206053/170775971-04b3d4b4-6813-4c47-8b8f-22936cc07c6e.png)