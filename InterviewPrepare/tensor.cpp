#include <iostream>
#include <algorithm>

class Tensor {
private:
    float* data;
    size_t size;

public:
    Tensor(size_t s) : size(s) {
        data = new float[size];
        std::cout << "Allocated " << size << " floats.\n";
    }

    // Деструктор
    ~Tensor() {
        delete[] data;
    }

    // ТВОЯ ЗАДАЧА:
    // 1. Напиши конструктор перемещения (Move Constructor)
    Tensor(Tensor&& other) noexcept {
        data = other.data;
        size = other.size;
        other.data = nullptr;
        other.size = 0;
    }
    // 2. Напиши оператор присваивания перемещением (Move Assignment Operator)
        Tensor& operator=(Tensor&& other) noexcept {
        // 1. Защита от самоприсваивания
        if (this != &other) {
            // 2. Освобождаем старую память текущего объекта
            delete[] data;
        
            // 3. Забираем ресурсы у other
            data = other.data;
            size = other.size;
        
            // 4. Оставляем other в валидном, но пустом состоянии
            other.data = nullptr;
            other.size = 0;
        }
        // 5. Возвращаем ссылку на себя
        return *this;
    }
};