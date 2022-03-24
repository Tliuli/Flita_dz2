// report1.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main()
{
  FILE *f1, *f2; // ������� ����������, ��������������� �����. � f1 ���������� �������� �������, � f2 - ��������������� ���� ��� graphviz
  char arr[1001][1001], s; // ���������� ������, � ������� �������� �������
  int i = 0, j = 0; // ������� ��� �������
  f1 = fopen("matrix_of_incendence12.txt", "r");
  while (!feof(f1))
  {
    fscanf(f1, "%c", &s);// "%c" - ��������� �� ������ �������
    if (s != ' ' && s != '\n')
    {
      arr[i][j] = s;
      j++;
      if (j == 17)// 17 - ��������� �������� � ������.
      {
        i++;
        j = 0;
      }
    }
  }
  char flag;// ���� ��� ����, ����� ����������, ������� ����� ��������� ����� ������.
  f2 = fopen("res.gv", "w");
  fprintf(f2, "graph grath {\n");// ��� graphviz ����� ��������� graph name {
  for(int d = 0; d < 5; d++){ // ��������� ������� (�� 5)
    fprintf(f2, "%d\n", d + 1);// ���������� ������ ������� � ������ 
  }
  for (int a = 0; a < 17; a++) // ���� ���� ���� �� ��������, ����� �� ��� ���� ���� ���������� ����� ������� ��������� ����� 
  {
    flag = -1;
    for (int y = 0; y < 5; y++)// ���� ���� �� ������� ����
    {
      if (arr[y][a] != '0')
      {
        if (flag == -1)
        {
          fprintf(f2, "%d", y + 1); // ���������� �������
          printf("%d", y + 1); // �� �� �����, ������ ��� ������ � �������
          flag = 0; // �������� ����� ������, ��� ������ ��� ����� ��������� 1 �������
        }
        else
        {
          printf(" -- %d", y + 1);
          fprintf(f2, " -- %d [label = ""%d""]", y + 1, a+1);// ���� ����  = 0, �� ���������� 2-�� �������, ������� ��������� �����
        }
      }
    }
    fprintf(f2, "\n");// ������� �������, ��� ���� ���� grathviz ����, ��� ������� �������
    printf("\n");
  }
  fprintf(f2, "}");// ��������� graph name {
  fclose(f2);
  system("dot res.gv -Tpng -o g.png");
  system("g.png");
}
