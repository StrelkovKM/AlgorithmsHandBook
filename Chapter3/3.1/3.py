import sys

input = sys.stdin.readline

def main():
    n = int(input())
    a = input()
    b = input()
    s = ''

    for i in range(n):
        s += a[i] + b[i]

    print(s)

if __name__ == "__main__":   main()