import sys

input = sys.stdin.readline

def main():
    q = int(input())
    s = set()
    for _ in range(q):
        re, x = map(int, input().split())
        if (re == 1): 
            s.add(x)
        elif (re == 2): 
            if x in s: 
                print(1)
            else: 
                print(0)

if (__name__ == "__main__"):
    main()