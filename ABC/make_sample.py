import random

N = random.randint(1, 200000)
Q = random.randint(1, 200000)

C = []
for i in range(N):
    C.append(random.randint(1, N))

query = []
for i in range(Q):
    a = random.randint(1, N)
    b = random.randint(1, N)
    while a == b:
        b = random.randint(1, N)
    query.append((a, b))

f = open('sample.txt', 'w')
f.write('{} {}\n'.format(N, Q))
f.write('{}\n'.format(' '.join(map(str, C))))
for a, b in query:
    f.write('{} {}\n'.format(a, b))