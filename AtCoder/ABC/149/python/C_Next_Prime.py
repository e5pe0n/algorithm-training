MAX_N = 10**6
X = int(input())

is_prime = [True] * MAX_N


def sieve():
    global is_prime
    for i in range(2, MAX_N):
        if is_prime[i]:
            for j in range(i + i, MAX_N, i):
                is_prime[j] = False


sieve()
for i in range(2, MAX_N):
    if is_prime[i] and i >= X:
        print(i)
        exit()
