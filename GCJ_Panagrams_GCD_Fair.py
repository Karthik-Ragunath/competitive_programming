from math import gcd
from collections import deque
import string
from collections import defaultdict

testcases = int(input())
for i in range(testcases):
	(max_prime, n) = [int(val) for val in input().split()]
	inputs = list(map(int, input().split()))
	dq = deque()
	prime_set = set()
	mid_val, gcd_val_mid = 0, 0
	for k in range(n - 1):
		if inputs[k] != inputs[k + 1]:
			mid_val = k
			gcd_val_mid = gcd(inputs[k], inputs[k + 1])
			dq.append(gcd_val_mid)
			prime_set.add(gcd_val_mid)
			break

	gcd_val = gcd_val_mid
	for m in range(mid_val - 1, -1, -1):
		gcd_val = inputs[m] / gcd_val
		dq.appendleft(gcd_val)
		prime_set.add(gcd_val)

	gcd_val = gcd_val_mid
	for m in range(mid_val + 1, n):
		gcd_val = inputs[m] / gcd_val
		dq.append(gcd_val)
		prime_set.add(gcd_val)

	dq.appendleft(inputs[0]/dq[0])
	prime_set.add(dq[0])
	prime_set_sorted = sorted(prime_set)
	prime_to_alphabet_dict = defaultdict(str)
	for prime, alphabet in zip(prime_set_sorted, list(string.ascii_uppercase)):
		prime_to_alphabet_dict[prime] = alphabet
	solution_list = []
	for prime in dq:
		solution_list.append(prime_to_alphabet_dict[prime])
	print("Case #" + str(i + 1) + ': ' + ''.join(solution_list))



