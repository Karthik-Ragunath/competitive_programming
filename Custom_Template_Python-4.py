# your code goes here
from collections import deque

a = deque()
a.append(5)
a.append(10)
a.append(15)
a.popleft()
a.pop()
print(a)

# deque([10])