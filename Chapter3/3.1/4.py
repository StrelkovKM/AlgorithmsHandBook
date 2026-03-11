import sys 

# Читаем все данные разом, это быстрее для больших матриц
input = sys.stdin.read().split()

def main():
    if not input:
        return
    
    # Используем итератор для удобного забора чисел
    data = iter(input)
    n = int(next(data)) # строки
    m = int(next(data)) # столбцы

    # Считываем первую матрицу
    matrix1 = []
    for _ in range(n):
        row = [int(next(data)) for _ in range(m)]
        matrix1.append(row)

    # Считываем вторую матрицу и сразу складываем
    for i in range(n):
        # Генерируем строку результата "на лету"
        row_result = [matrix1[i][j] + int(next(data)) for j in range(m)]
        # Печатаем сразу, чтобы не тратить память на хранение второй матрицы
        print(*row_result)

if __name__ == "__main__":
    main()