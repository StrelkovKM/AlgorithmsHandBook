import sys

input = sys.stdin.readline


def main():
    n = int(input())
    dict = {}
    result = []
    for _ in range(n):
        request = list(map(int, input().split()))
        if request[0] == 1:
            dict[request[1]] = request[2]
        elif request[0] == 2:
            if request[1] in dict:
                result.append(dict[request[1]])
            else:
                result.append(-1)
    
    print(*result, sep='\n')

if __name__ == "__main__":    main()