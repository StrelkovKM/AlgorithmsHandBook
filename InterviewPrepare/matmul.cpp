#include <iostream>

// A [M, K]
// B [K, N]
// C [M, N]
void matmul(const float* A, const float* B, float* C, int M, int K, int N) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            float sum = 0.0f;
            for (int k = 0; k < K; k++) {
                sum += A[i * K + k] * B[j + N * k];
            }
            C[i * N + j] = sum;
        }
    }
}

void matmul_cache_friendly(const float* A, const float* B, float* C, int M, int K, int N) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            C[i * N + j] = 0.0f;
        }
    }

    for (int i = 0; i < M; i++) {
        for (int k = 0; k < K; k++) {
            float a_val = A[i * K + k];
            for (int j = 0; j < N; j++) {
                C[i * N + j] += a_val * B[j + N * k];
            }
        }
    }
}

int main() {
    const int M = 3, N = 3, K = 4;

    float A[M * K] = {
        1, 2, 3, 4,
        5, 6, 7, 8,
        9, 10, 11, 12
    };

    float B[K * N] = {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9,
        10, 11, 12
    };

    float C[M * N] = {0.0f};

    matmul(A, B, C, M, K, N);

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << C[ i * N + j] << ' ';
        }
        std::cout << '\n';
    }

    matmul_cache_friendly(A, B, C, M, K, N);

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << C[ i * N + j] << ' ';
        }
        std::cout << '\n';
    }
}