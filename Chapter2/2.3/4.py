import sys
from collections import Counter

input = sys.stdin.readline

def main():
    n = int(input())
    query = list(map(int, input().split()))
    counter = Counter(query)
    items = list(counter.items())
    items.sort(key=lambda x: (-x[1], x[0]))
    result = [items[0][0], items[1][0], items[2][0]]
    result.sort()
    print(*result)

if __name__ == "__main__":
    main()
    

