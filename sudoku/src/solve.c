#include "ft.h"

// находим пустую ячейку
bool preparing(int *x, int *y, char **new_arr) {
  bool result = false;
  int x_temp = -1;
  int y_temp = 0;
  while (x_temp < 8) {
    x_temp += 1;
    y_temp = 0;
    while (new_arr[x_temp][y_temp] != 0 && y_temp < 8) {
      y_temp += 1;
    }
    if (new_arr[x_temp][y_temp] == 0) {
      result = true;
      break;
    }
  }
  if (result) {
    *x = x_temp;
    *y = y_temp;
  }
  return result;
}

// узел ветвления для всех допустимых чисел
void recur(char **new_arr, int x, int y, int *s_num) {
  int acc;

  acc = 1;
  while (acc < 10) {
    if (num_check(new_arr, x, y, acc)) {
      new_arr[x][y] = acc;
      // если не конец судоку, то запускаем новое решение
      if (x != 8 || y != 8) {
        solve(new_arr, s_num);
      }
    }
    acc++;
  }
}

// решение судоку
void solve(char **arr, int *s_num) {
  int x, y;
  char **new_arr;

  if (*s_num >= kMAX_SOLUTION) {
    return;
  }

  new_arr = arr_cpy(arr);
  // если найдена пустая ячейка, то проваливаемся
  if (preparing(&x, &y, new_arr)) {
    // если этот вариант не решаемый, тогда прекращаем работу с ним
    if (zero_check(new_arr, x, y) == 0) {
      new_arr = arr_delete(new_arr);
      return;
    }
    recur(new_arr, x, y, s_num);
  }
  // если нашли решение, то инкрементируем общий счётчик
  if (sud_check(new_arr) && *s_num < kMAX_SOLUTION) {
    *s_num += 1;
    arr_print(new_arr);
  }
  new_arr = arr_delete(new_arr);
}