import sys

input = sys.stdin.readline

def main():
    n = int(input())

    query = list(map(int, input().split()))

    counter = [0] * (10**5 + 1)

    for v in query:
        counter[v] +=1 
    
    max_count = -1
    ans = -1

    for i in range(len(counter)):
        if counter[i] > max_count:
            max_count = counter[i]
            ans = i
            
    print(ans)

    if __name__ == "__main__":
        main()