#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <malloc.h>

int main()
{
    setlocale(LC_ALL, "Rus");
    int n = 0, k = 0;
    printf("Введите длину векторов и их количество\n");
    scanf_s("%d %d", &n, &k);
    int** a;
    a = (int**)malloc(k * sizeof(int*));
    // Ввод элементов массива
    for (int i = 0; i < k; i++)  
    {
        a[i] = (int*)malloc(n * sizeof(int));
        printf("Введите координаты %d-го вектора \n", 1+i);
        for (int j = 0; j < n; j++) 
        {
            scanf_s("%d", &a[i][j]);
        }
    }
    /*Вывод элементов массива
    for (int i = 0; i < k; i++)  // цикл по строкам
    {
        for (int j = 0; j < n; j++)  // цикл по столбцам
        {
            printf("%5d ", a[i][j]); // 5 знакомест под элемент массива
        }
        printf("\n");
    }*/


    printf("\n");
    //обработка массива (очень грубо говоря, приводим к ступенчатому виду)
    for (int j = 0; j < n; j++) { // идем по столбцам
        int t = 0;              
        while (a[t][j] == 0) t++;   //находим первую строку с ненулевым значением
        for (int i = t+1; i < k; i++) { // идем по следующим строкам
            if (a[i][j] != 0) {     //если координата не нулевая,
                for (int s = j; s < n; s++) { //отнимаем от нее строку t с коэфицентом, чтобы получился 0
                    a[i][s] = a[i][s] - a[t][s] * (a[i][j] / a[t][j]);
                }
            }
            
        }

    }
    for (int i = 0; i < k; i++)  // выводим результат элементарных преобразований для наглядности
    {
        for (int j = 0; j < n; j++)  
        {
            printf("%5d ", a[i][j]); 
        }
        printf("\n");
    }
    int count = 0;
    int sum = 0;
    for (int i = 0; i < k; i++) 
    {
        sum = 0;
        for (int j = 0; j < n; j++)
        {
            sum += pow(a[i][j], 2); //считаем сумму квадратов
        }
        if (sum > 0) count++; //если есть хотя бы онин не ноль, увеличиваем счетчик
    }
    printf("Ранг системы векторов %d ", count);
    return 0;
}

