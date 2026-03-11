import sys

def main():
    data = sys.stdin.read().split()
    if not data:
        return
    
    a_str = data[0]
    b_str = data[1]
    
    res = bin(int(a_str, 2) + int(b_str, 2))
    
    print(res[2:])

if __name__ == "__main__":
    main()