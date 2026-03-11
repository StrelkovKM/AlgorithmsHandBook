import sys

input = sys.stdin.readline

class Polinomial:
    def __init__(self, coefficients, degree):
        self.coefficients = coefficients
        self.degree = degree
    
    def __add__(self, other):
        # Определяем, какой многочлен длиннее
        if self.degree >= other.degree:
            big, small = self, other
        else:
            big, small = other, self

        # Создаем копию коэффициентов длинного многочлена
        res_coeffs = big.coefficients[:]
        
        # Разница в длине списков
        diff = big.degree - small.degree
        
        # Складываем коэффициенты, начиная с нужного смещения
        # Идем от 0 до small.degree включительно
        for i in range(small.degree + 1):
            # Индекс для big: i + diff
            # Индекс для small: i
            res_coeffs[i + diff] += small.coefficients[i]
        
        # Вычисляем реальную степень (могла уменьшиться, если старшие члены сократились)
        new_degree = len(res_coeffs) - 1
        # Опционально: можно убрать ведущие нули, если это требует задача
        
        return Polinomial(res_coeffs, new_degree)

def main():
    # Считываем данные
    try:
        deg_a = int(input())
        coeffs_a = list(map(int, input().split()))
        deg_b = int(input())
        coeffs_b = list(map(int, input().split()))
    except ValueError: return

    a = Polinomial(coeffs_a, deg_a)
    b = Polinomial(coeffs_b, deg_b)

    result = a + b

    print(result.degree)
    print(*(result.coefficients))

if __name__ == "__main__":
    main()