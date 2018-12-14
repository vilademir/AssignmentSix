#include <iostream>
#include <fstream>
#include "Sort.h"


using namespace std;

Sort::Sort(){}

Sort::Sort(string nameOfFile)
{
  readFile(nameOfFile);
}

Sort::~Sort()
{
  //delete[] creatArray;
}


void Sort::readFile(string nameOfFile)
{
  string fileLine;

  ifstream fileReader(nameOfFile);

  getline(fileReader, fileLine);

  arraySize = stoi(fileLine);

  creatArray = new double[arraySize];

  while(getline(fileReader, fileLine))
  {
    for(int x = 0; x < arraySize; x++)
    {
      creatArray[x] = stod(fileLine);
    }
  }
  fileReader.close();
}




void Sort::BubbleSort(double myArray[])
{
  for(int i = 0; i < arraySize; i++)
  {
    int temp = 0;
    for(int j = i; j < arraySize - 1; j++)
    {
      if(myArray[j] > myArray[j+1])
      {
        temp = myArray[j+1];

        myArray[j] = temp;

        myArray[j+1] = myArray[j];
      }
    }
  }
}


void Sort::InsertSort(double myArray[])
{
  for(int j = 1; j < arraySize; ++j)
  {
    double temp = myArray[j];
    int k = j;
    while (k > 0 && myArray[k-1] >= temp)
    {
      myArray[k] = myArray[k-1];
      --k;
    }
    myArray[k] = temp;
  }
}


void Sort::ShellSort(double myArray[])
{
  for (int gap = arraySize/2; gap > 0; gap /= 2)
  {
    for (int i = gap; i < arraySize; i += 1)
    {
      int temp = myArray[i];
      int j;
      for (j = i; j >= gap && myArray[j - gap] > temp; j -= gap)
      {
        myArray[j] = myArray[j - gap];
      }
      myArray[j] = temp;
    }
  }
}

//function that swaps numbers
void Sort::swapNumbers(double *a, double *b)
{
  double t = *a;
  *a = *b;
  *b = t;
}

//function partitions, declares pivot and sorts
int Sort::partition(double myArray[], double low, double high)
{
  int pivot = myArray[(int)high];
  int i = (low - 1);

  for (int j = low; j <= high- 1; j++)
  {
    if (myArray[j] <= pivot)
    {
      i++;
      swapNumbers(&myArray[i],&myArray[j]);
    }
  }
  swapNumbers(&myArray[(int)i + 1], &myArray[(int)high]);
  return (i + 1);
}

void Sort::QuickSort(double myArray[], int low, int high)
{

  if (low < high)
  {
    int pi = partition(myArray, low, high);

    QuickSort(myArray, low, pi - 1);
    QuickSort(myArray, pi + 1, high);
  }
}
