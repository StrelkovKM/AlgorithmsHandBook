import sys

input = sys.stdin.readline

def main():
    line = input().strip()
    if not line: return
    n = int(line)

    sets = []
    counts = {}
    
    for _ in range(n):
        row = list(map(int, input().split()))
        elements = row[1:]
        sets.append(elements)
        for x in elements:
            counts[x] = counts.get(x, 0) + 1

    core_size = 0
    for x in counts:
        if counts[x] == n:
            core_size += 1
        elif counts[x] > 1:

            print("NO")
            return


    print("YES")
    print(core_size)
    
    ans = [len(s) - core_size for s in sets]
    print(*ans)

if __name__ == "__main__":
    main()