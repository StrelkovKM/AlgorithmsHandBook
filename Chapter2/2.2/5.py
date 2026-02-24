import sys

def main():
    data = sys.stdin.read().split()
    if not data:
        return
    
    n = int(data[0])
    a = list(map(int, data[1:]))

    all_distinct_ors = set()
    current_ors = set()

    for x in a:
        current_ors = {val | x for val in current_ors}
        current_ors.add(x)
        
        all_distinct_ors.update(current_ors)

    print(len(all_distinct_ors))

if __name__ == "__main__":
    main()