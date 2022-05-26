Max-Sum
========
2022 SSHS R&E 
(김선웅, 이지후, 박세진, 정현우)

내용
--------

### Max-Sum Algorithm
Max-Sum Belief Propagation: Factor Graph에서 노드 간 메세지를 통해 목적 함수의 합을 최대화하는 알고리즘.  
이를 Group Blind Date 상황에 적용 -> 모두의 만족도 합을 최대화하는 것이 목적.  
![image](https://user-images.githubusercontent.com/35063338/170415829-e2c5c1bb-147b-4d9a-ac1f-114f0ea98894.png)

### Input
남자와 여자를 좌표평면의 점으로 표현한 후, 남자와 여자 사이의 만족도를 유클리드 거리로 설정.  
![image](https://user-images.githubusercontent.com/35063338/170417792-c08cb4cb-4052-4e70-88ea-d40a5f5f572b.png)

### Process
Max-Sum Belief Propagation으로 얻은 다음의 점화식을 수렴할 때까지 실행
![image](https://user-images.githubusercontent.com/35063338/170418111-c38a2e22-983c-4171-9cb3-e657d3cb2c71.png)
수렴하면 고정된 $i$에 대하여 $\rho_{ij}+\alpha_{ij}$의 값이 최대가 되는 $j$와 연결

### Result
![image](https://user-images.githubusercontent.com/35063338/170419394-af59ed98-cf0a-4415-b140-668ba7679efd.png)

