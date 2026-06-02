#include <iostream>
#include <iomanip>

void conv2d_math(const float* input, const float* kernel, float* output, int N, int K) {
    int padding = K / 2;
    for (int i_in = padding; i_in < N - padding; i_in++) {
        for (int j_in = padding; j_in < N - padding; j_in++) {
            float sum = 0.0f;
            for (int i_k = -padding; i_k <= padding; i_k++) {
                for (int j_k = -padding; j_k <= padding; j_k++) {
                    sum += input[(i_in - i_k) * N  + (j_in - j_k)] 
                         * kernel[K * (i_k + padding) + (j_k + padding)];
                }
            }
            output[i_in * N + j_in] = sum;
        }
    }
}

void conv2d_ml(const float* input, const float* kernel, float* output, int N, int K) {
    int padding = K / 2;
    for (int i_in = padding; i_in < N - padding; i_in++) {
        for (int j_in = padding; j_in < N - padding; j_in++) {
            float sum = 0.0f;
            for (int i_k = -padding; i_k <= padding; i_k++) {
                for (int j_k = -padding; j_k <= padding; j_k++) {
                    sum += input[(i_in + i_k) * N  + (j_in + j_k)] 
                         * kernel[K * (i_k + padding) + (j_k + padding)];
                }
            }
            output[i_in * N + j_in] = sum;
        }
    }
}

void print_matrix(const float* mat, int N, const char* name) {
    std::cout << "--- " << name << " ---" << std::endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << std::setw(4) << mat[i * N + j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    const int N = 5;
    const int K = 3;

    float input[N * N] = {0};
    input[1 * N + 1] = 1.0f;

    float kernel[K * K] = {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    float out_math[N * N] = {0};
    float out_ml[N * N] = {0};

    conv2d_math(input, kernel, out_math, N, K);
    conv2d_ml(input, kernel, out_ml, N, K);

    print_matrix(input, N, "Input Image (5x5)");
    print_matrix(kernel, K, "Kernel (3x3)");
    print_matrix(out_math, N, "Math Convolution Output (Your code with '-')");
    print_matrix(out_ml, N, "ML Cross-Correlation Output (Code with '+')");

    return 0;
}