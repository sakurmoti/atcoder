def solve(W,D,N,a,seed=None):
    # 全て均等に領域を分割してみる
    M=0
    h=0
    w=0
    for X in range(1,W):
        for Y in range(1,W):
            if (W//X) * (W//Y) >= N and X*Y > M:
                M = X*Y
                h = Y
                w = X

    for d in range(D):
        x=0
        y=0
        for i in range(N):
            print(y,x,y+h,x+w)
            # with open(f'./output/{seed}.txt',mode='a') as f:
            #     f.write(f'{y} {x} {y+h} {x+w}\n')

            x+=w
            if x+w>W:
                x=0
                y+=h


if __name__ == '__main__':
    # ファイル読み込み
    # for num in range(0,10):
    #     seed = str(num).zfill(4)
    #     print(seed)
    #     with open(f'./input/{seed}.txt') as f:
    #         W,D,N = map(int,f.readline().split())
    #         a = list(map(int,f.readline().split()))
    #         solve(W,D,N,a,seed)


    W,D,N = map(int,input().split())
    a = list(map(int,input().split()) for _ in range(D))
    solve(W,D,N,a)

