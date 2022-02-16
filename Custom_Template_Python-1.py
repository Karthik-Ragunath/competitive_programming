# your code goes here
import numpy as np
import heapq

a = np.random.rand(3,2)
b = np.random.rand(4,5)
c = np.random.rand(6,5)
d = np.random.rand(7,3)
np_list = [a,b,c,d]
pq = []
index_list = [-5,-6,-2,-3]
for i in range(4):
	if len(pq) < 2:
		heapq.heappush(pq, (index_list[i], np_list[i]))
	else:
		heapq.heappushpop(pq, (index_list[i], np_list[i]))
		
print(pq)


