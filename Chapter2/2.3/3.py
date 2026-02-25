import sys
import math
from collections import Counter

def main():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    n = int(input_data[0])
    fractions = []
    
    ptr = 1
    for _ in range(n):
        num = int(input_data[ptr])
        den = int(input_data[ptr+1])
        ptr += 2
        
        common = math.gcd(num, den)
        num //= common
        den //= common
        
        fractions.append((num, den))
    
    counts = Counter(fractions)
    
    max_freq = max(counts.values())
    
    candidates = [f for f, freq in counts.items() if freq == max_freq]
    
    
    from functools import cmp_to_key
    
    def compare_fractions(f1, f2):
        v1 = f1[0] * f2[1]
        v2 = f2[0] * f1[1]
        if v1 < v2: return -1
        if v1 > v2: return 1
        return 0

    best_fraction = min(candidates, key=cmp_to_key(compare_fractions))
    
    print(f"{best_fraction[0]} {best_fraction[1]}")

if __name__ == "__main__":
    main()