/*************************
 * Автор: Захаров Никита *
 * Вариант: 6            *
 * ***********************/
 
#include <iostream>
#include <cmath>

using namespace std;

//Максимально допустимый размер массива
const int maxRows = 100;
const int maxColumns = 100;

//Минимально допустимый размер массива
const int minRows = 1;
const int minColumns = 1;

//Функция для вычисления суммы всех элементов массива
double sumOfArrayElements(double arrayR[maxRows][maxColumns], int rows, int columns) {
  double sum = 0;
  for (int rowIndex = 0; rowIndex < rows; ++rowIndex) {
    for (int columnIndex = 0; columnIndex < columns; ++columnIndex) {
      sum += arrayR[rowIndex][columnIndex];
    }
  }
  
  return sum;
}

//Функция для вычисления суммы квадратных корней всех элементов массива
double sumSquareRootOfArrayElements(double arrayR[maxRows][maxColumns], int rows, int columns) {
  double sumSquareRoot = 0;
  double zero = 0;  //С помощью данной переменной мы сможем определить знак числа
    for (int rowIndex = 0; rowIndex < rows; ++rowIndex) {
      for (int columnIndex = 0; columnIndex < columns; ++columnIndex) {
        double arrayElement = arrayR[rowIndex][columnIndex];
        if (arrayElement >= zero) {
          sumSquareRoot += sqrt(arrayElement);
        } else {
          sumSquareRoot += sqrt(-arrayElement);
        }
      }
    }
    
  return sumSquareRoot;
}

int main() {
    
  int rows; 
  cout << "Введите количество строк массива (макс. строк - 100): ";
  cin >> rows;
  
  int columns;
  cout << "Введите количество столбцов массива (макс. столбцов - 100): ";
  cin >> columns;
  
  if (rows > maxRows || rows < minRows || columns > maxColumns || columns < minColumns) {
    cout << "Некорректный размер массива" << endl;
    return 1;
  }
  
  double arrayR[maxRows][maxColumns];

  //Ввод элементов массива
  cout << "Введите элементы массива:" << endl;
  for (int rowIndex = 0; rowIndex < rows; ++rowIndex) {
    for (int columnIndex = 0; columnIndex < columns; ++columnIndex) {
      cout << "R[" << rowIndex << "][" << columnIndex << "] = ";
      cin >> arrayR[rowIndex][columnIndex];
    }
  }

  //Итоговая сумма элементов массива
  double totalSum;
  //Итоговая сумма квадратных корней элементов массива
  double totalSquareRootSum;
  
  //Вычисление результатов
  totalSum = sumOfArrayElements(arrayR, rows, columns);
  totalSquareRootSum = sumSquareRootOfArrayElements(arrayR, rows, columns);

  cout << "Сумма элементов массива: " << totalSum << endl
       << "Сумма квадратных корней элементов массива: " << totalSquareRootSum << endl;
  
  return 0;
}