import math
from collections import defaultdict
import string

def fermat_factor(prime_number):
    a = math.ceil(math.sqrt(prime_number))
    b = a ** 2 - prime_number
    while(math.sqrt(b) != math.ceil(math.sqrt(b))):
        a = a + 1
        b = a ** 2 - prime_number
    return (a, math.sqrt(b))

test_cases = input()
test = int(test_cases)
for i in range(test):
    prime_dict = defaultdict(tuple)
    total_primes = set()
    second_line = input()
    second_line_list = list(map(int, second_line.split()))
    up_lim = second_line_list[0]
    n = second_line_list[1]
    third_line = input()
    input_list = list(map(int, third_line.split()))
    for val in input_list:
        (p1, p2) = fermat_factor(val)
        p1_int = int(p1)
        p2_int = int(p2)
        p1 = p1_int - p2_int if p1_int > p2_int else p2_int - p1_int
        p2 = p1_int + p2_int
        total_primes.add(p1)
        total_primes.add(p2)
        prime_dict[val] = (p1, p2)
    prime_list_sorted = sorted(total_primes)
    prime_alpha_dict = defaultdict(str)
    for prime, alphabet in zip(prime_list_sorted, list(string.ascii_uppercase)):
        prime_alpha_dict[prime] = alphabet
    solution_str = ""
    for inp in input_list:
        (p1, p2) = prime_dict[inp]
        char = prime_alpha_dict[p1]
        solution_str += char
    solution_str += prime_alpha_dict[p2]
    sol = "Case #" + str(i + 1) + ": " + solution_str
    print(sol)