from functools import cmp_to_key

def prepare_order(order):
    order = order.split(" ", 1)
    return order

def split_prime(orders):
    prime = []
    non_prime = []
    for order in orders:
        if ("a" <=order[1][0] <= "z"):
            prime.append(order)
        else:
            non_prime.append(order)
    return prime, non_prime

def compare(a, b):
    a_id, a_metadata = a
    b_id, b_metadata = b
    if (a_metadata == b_metadata):
        if (a_id < b_id):
            return -1
        return 1
    if a_metadata < b_metadata:
        return -1
    if a_metadata > b_metadata:
        return 1
    return 0

def solve(orders):
    orders = [prepare_order(order) for order in orders]
    primes, non_primes = split_prime(orders)
    primes.sort(key=cmp_to_key(compare))
    primes = [p[0] + " " + p[1] for p in primes]
    non_primes = [p[0] + " " + p[1] for p in non_primes]
    return primes + non_primes

t = int(input())

for a in range(t):
    n = int(input())
    orders = []
    for i in range(n):
        s = input()
        orders.append(s)
    print(solve(orders))