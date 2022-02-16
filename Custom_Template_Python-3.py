from sortedcontainers import SortedList, SortedSet, SortedDict
import heapq

li = [(3, 353), (34, 543), (1, 345), (345, 1)]
sorted_li = sorted(li, key=lambda item : item[0])
print(sorted_li)

li = [(3, 353), (34, 543), (1, 345), (345, 1)]
sorted_set = SortedSet(li, key = lambda item: item[0])
print(sorted_set)

set_li = set(li)
sorted_sets = SortedSet(set_li, key = lambda item: item[0])
print(sorted_sets)

# SortedSet([(1, 345), (3, 353), (34, 543), (345, 1)], key=<function <lambda> at 0x7f83a93af670>)

pq = []
heapq.heappush(pq, (34, 45))
heapq.heappush(pq, (34, 78))
heapq.heappush(pq, (34, 78))
# [(34, 45), (34, 78), (34, 78)]