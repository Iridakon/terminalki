#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <malloc.h>

void sort(int** a, int ip, int jp , int n, int k) {
    int verh = ip;

    for (int i = ip; i < k; i++) {
        if (a[i][jp] != 0) {
            
            for (int l = 0; l < n; l++) {
                int b = a[i][l];
                a[i][l] = a[verh][l];
                a[verh][l]=b;
            }
            verh++;
        }
    }
}


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
        printf("Введите координаты %d-го вектора \n", 1 + i);
        for (int j = 0; j < n; j++)
        {
            scanf_s("%d", &a[i][j]);
        }
    }
    
    //for (int i = 0; i < k; i++)  // цикл по строкам
    //{
    //    for (int j = 0; j < n; j++)  // цикл по столбцам
    //    {
    //        sort(a,i,j,n,k); 
    //    }
    //    printf("\n");
    //}


    sort(a, 0, 0, n, k);

    //Вывод элементов массива
    for (int i = 0; i < k; i++)  // цикл по строкам
    {
        for (int j = 0; j < n; j++)  // цикл по столбцам
        {
            printf("%5d ", a[i][j]); // 5 знакомест под элемент массива
        }
        printf("\n");
    }
    printf("\\\\\n");

    int smi=0;
    for (int j = 0; j < n; j++) {
        int t = j - smi;
        sort(a, t, j, n, k);
        while (a[t][j] == 0) {
            t--;
            if (t < 0) break;
        }
        if (t >= 0) {
            for (int i = t + 1; i < k; i++) {
                if (a[i][j] != 0) {     //если координата не нулевая,
                    float kof = a[i][j] / (float)a[t][j]; //находим коэфицент
                    for (int s = j; s < n; s++) { //отнимаем от нее строку t с этим коэфицентом, чтобы получился 0
                        a[i][s] = a[i][s] - a[t][s] * (kof);
                    }

                }
                
            }
            for (int r = 0; r < k; r++)  // выводим результат элементарных преобразований для наглядности
            {
                for (int l = 0; l < n; l++)
                {
                    printf("%5d ", a[r][l]);
                }
                printf("\n");
            }
            printf("\n");
        }
        else smi++;
        printf("-----\n");
    }


    ////Вывод элементов массива
    //for (int i = 0; i < k; i++)  // цикл по строкам
    //{
    //    for (int j = 0; j < n; j++)  // цикл по столбцам
    //    {
    //        printf("%5d ", a[i][j]); // 5 знакомест под элемент массива
    //    }
    //    printf("\n");
    //}
    //printf("\\\\\n");



    printf("\n");
    


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

