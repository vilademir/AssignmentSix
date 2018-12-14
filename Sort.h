#include <iostream>

using namespace std;

class Sort{
public:
  Sort();
  Sort(string nameOfFile);
  ~Sort();

  void readFile(string nameOfFile);
  void BubbleSort(double myArray[]);
  void InsertSort(double myArray[]);
  void ShellSort(double myArray[]);
  void QuickSort(double myArray[], int low, int high);

  void swapNumbers(double *a, double *b);

  int partition(double myArray[], double low, double high);

  double *creatArray;
  int arraySize = 0;

};
