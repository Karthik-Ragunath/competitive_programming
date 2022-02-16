# your code goes here
import bisect

a = [('dhiv', 1), ('anand', 3), ('raji', 2), ('karthik', 5)]
a_sorted = sorted(a, key = lambda tup: tup[1])
sorted_keys = [item[1] for item in a_sorted]
x = 3
bisect_left = a_sorted[bisect.bisect_left(sorted_keys, x)]
print(bisect_left)

bisect_right = a_sorted[bisect.bisect_right(sorted_keys, x)]
print(bisect_right)

# Output
# ('anand', 3)
# ('karthik', 5)