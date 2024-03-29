#include "ft.h"

// выделение памяти под первичный массив
char **arr_create(char **argv) {
  int x = 0;
  char **result = NULL;

  result = (char **)malloc(sizeof(char *) * 9);
  while (x < 9) {
    int y = 0;
    result[x] = (char *)malloc(sizeof(char) * 9);
    while (y < 9) {
      if (argv[x][y] == '.')
        result[x][y] = 0;
      else
        result[x][y] = argv[x][y] - '0';
      y++;
    }
    x++;
  }
  return result;
}

// копирование массива
char **arr_cpy(char **arr_old) {
  int x = 0;
  char **result = NULL;

  result = (char **)malloc(sizeof(char *) * 9);
  while (x < 9) {
    int y = 0;
    result[x] = (char *)malloc(sizeof(char) * 9);
    while (y < 9) {
      result[x][y] = arr_old[x][y];
      y++;
    }
    x++;
  }
  return result;
}

// печать массива
void arr_print(char **arr) {
  for (int x = 0; x < 9; ++x) {
    for (int y = 0; y < 9; ++y) {
      ft_putchar(arr[x][y] + '0');
    }
    ft_putchar('\n');
  }
  ft_putchar('\n');
}

// очистка памяти массива
char **arr_delete(char **arr) {
  int x = 0;

  while (x < 9) {
    free(arr[x]);
    arr[x] = NULL;
    x++;
  }
  free(arr);
  return NULL;
}