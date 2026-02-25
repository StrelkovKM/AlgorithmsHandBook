import sys
from collections import Counter

def solve():
    input_data = sys.stdin.read().split()

    n = int(input_data[0])
    words = input_data[1:]

    word_counts = Counter(words)
    unique_words = list(word_counts.keys())

    total_interesting_pairs = 0

    for i in range(len(unique_words[0])):
        masks = {}
        for word in unique_words:
            mask = word[:i] + "*" + word[i+1:] #aaa -> *aa
            count = word_counts[word]

            masks[mask] = masks.get(mask, 0) + count

        for mask in masks:
            k = masks[mask]
            total_interesting_pairs += k * (k - 1) // 2


    same_word_pairs = 0
    for word in word_counts:
        count = word_counts[word]
        if count > 1:
            same_word_pairs += (count * (count - 1) // 2)

    total_interesting_pairs -= same_word_pairs * len(unique_words[0])

    print(total_interesting_pairs)

solve()