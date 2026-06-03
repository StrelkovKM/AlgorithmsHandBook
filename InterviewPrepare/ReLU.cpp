#include <iostream>
#include <algorithm>
#include <immintrin.h>

void relu_naive(float* data, int N) {
    for (int i = 0; i < N; i++) {
        data[i] = std::max(0.0f, data[i]);
    }
}

// ТВОЯ ЗАДАЧА:
void relu_avx(float* data, int N) {
    // Шаг 1. Создай вектор из 8 нулей (вынеси это ЗА цикл)
    __m256 zeros = _mm256_setzero_ps();
    __m256 buffer;
    __m256 max;
    
    
    // Шаг 2. Напиши основной цикл, который шагает по 8 элементов.
    // Внутри цикла: загрузи 8 чисел, найди максимум с нулем, сохрани обратно.
    
    for(int batch = 0; batch < N - N % 8; batch += 8) {
        buffer = _mm256_loadu_ps(data + batch);
        max = _mm256_max_ps(buffer, zeros);
        _mm256_storeu_ps(data + batch, max);
    }

    // Шаг 3. Обработай "хвост" массива обычным циклом, 
    // если N не делится на 8 нацело.

    buffer = _mm256_loadu_ps(data + (N - N % 8));
    max = _mm256_max_ps(buffer, zeros);
    _mm256_storeu_ps(data + (N - N % 8), max);
}