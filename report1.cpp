// report1.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main()
{
  FILE *f1, *f2; // Зададим переменные, характеризующие файлы. В f1 содержится исходная матрица, а f2 - вспомогательный файл для graphviz
  char arr[1001][1001], s; // Двухмерный массив, в который сохраним матрицу
  int i = 0, j = 0; // Индексы для массива
  f1 = fopen("matrix_of_incendence12.txt", "r");
  while (!feof(f1))
  {
    fscanf(f1, "%c", &s);// "%c" - считываем по одному символу
    if (s != ' ' && s != '\n')
    {
      arr[i][j] = s;
      j++;
      if (j == 17)// 17 - последнее значение в строке.
      {
        i++;
        j = 0;
      }
    }
  }
  char flag;// Флаг для того, чтобы определять, сколько чисел связывает ребро вершин.
  f2 = fopen("res.gv", "w");
  fprintf(f2, "graph grath {\n");// Для graphviz нужно прописать graph name {
  for(int d = 0; d < 5; d++){ // Объявляем вершины (их 5)
    fprintf(f2, "%d\n", d + 1);// Записываем каждую вершину в файлик 
  }
  for (int a = 0; a < 17; a++) // Этот цикл идет по столбцам, нужен он для того чтоб определить какие вершины связывают ребра 
  {
    flag = -1;
    for (int y = 0; y < 5; y++)// Цикл идет по столбцу вниз
    {
      if (arr[y][a] != '0')
      {
        if (flag == -1)
        {
          fprintf(f2, "%d", y + 1); // Записываем вершину
          printf("%d", y + 1); // То же самое, только для вывода в консоль
          flag = 0; // Значение флага меняем, это значит что ребро связывает 1 вершину
        }
        else
        {
          printf(" -- %d", y + 1);
          fprintf(f2, " -- %d [label = ""%d""]", y + 1, a+1);// Если флаг  = 0, то записываем 2-ую вершину, которую связывает ребро
        }
      }
    }
    fprintf(f2, "\n");// Обычный перевод, для того чтоб grathviz знал, где вершины связаны
    printf("\n");
  }
  fprintf(f2, "}");// Закрываем graph name {
  fclose(f2);
  system("dot res.gv -Tpng -o g.png");
  system("g.png");
}
