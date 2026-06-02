#include <iostream>

void transpose_naive(const float* src, float* dst, int N, int M) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            dst[j * N + i] = src[i * M + j];
        }
    }
}

void transpose_optimize(const float* src, float* dst, int N, int M) {
    constexpr int B = 16; 

    for (int i_block = 0; i_block < N; i_block += B) {
        for (int j_block = 0; j_block < M; j_block += B) {
            
            int i_end = std::min(i_block + B, N);
            int j_end = std::min(j_block + B, M);

            for (int i = i_block; i < i_end; ++i) {
                for (int j = j_block; j < j_end; ++j) {
                    dst[j * N + i] = src[i * M + j];
                }
            }
        }
    }
}

