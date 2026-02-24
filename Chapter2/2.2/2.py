import sys

input = sys.stdin.readline

def main():
    n = int(input())
    s = set()
    for _ in range(n):
        vec = list(map(int, input().split()))
        s.update(vec[1:])

    print(len(s))

if __name__ == "__main__": main()