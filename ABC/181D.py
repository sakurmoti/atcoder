import itertools

s = input()

if len(s) <= 2:
    # そのままか、逆順かだけ見ればよい
    if int(s)%8 == 0 or int(s[::-1])%8 == 0:
        print('Yes')
    else:
        print('No')

else:
    mp = dict()
    for i in range(len(s)):
        mp[int(s[i])] = mp.get(int(s[i]),0) + 1
    
    # print(mp)

    l = list()
    for x in mp:
        for y in range(min(mp[x],3)):
            l.append(x)
    
    # print(l)

    for v in itertools.permutations(l,3):
        if (100*v[0]+10*v[1]+v[2])%8 == 0:
            print('Yes')
            exit()

    print('No')