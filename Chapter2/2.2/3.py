import sys

input = sys.stdin.readline

def main():
    n = int(input())

    vec = list(map(int, input().split()))
    glob = set(vec[1:])

    for _ in range(1, n):
        vec = list(map(int, input().split()))
        loc = set(vec[1:])
        
        glob &= loc

    print(len(glob))


if __name__ == "__main__": main()
