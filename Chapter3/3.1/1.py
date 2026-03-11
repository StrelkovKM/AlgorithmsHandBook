import sys

input = sys.stdin.readline

def sum(a, b):
    return a + b

def main():
    a, b = map(int, input().split())
    print(sum(a, b))

if __name__ == "__main__": main()