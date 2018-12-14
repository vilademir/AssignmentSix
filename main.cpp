#include <iostream>
#include <fstream>
#include <ctime>
#include "Sort.h"

using namespace std;

int main(int argc, char ** argv)
{

  if(argc > 1)
  {
    string fileName = argv[1];

    ifstream doesFileExist(fileName);

    if(doesFileExist.good())
    {
      double timeOne;
      double timeTwo;
      Sort emhi; //object of class

      emhi.readFile(fileName);
      timeOne = clock();  //start clock
      emhi.BubbleSort(emhi.creatArray);
      timeTwo = clock(); //end clock

      std::cout << "Bubble Sort Time: " << timeTwo - timeOne << " seconds "<< '\n';

      emhi.readFile(fileName);
      timeOne = clock();
      emhi.InsertSort(emhi.creatArray);
      timeTwo = clock();

      std::cout << "Insert Sort Time: " << timeTwo - timeOne << " seconds" <<'\n';

      emhi.readFile(fileName);
      timeOne = clock();
      emhi.ShellSort(emhi.creatArray);
      timeTwo = clock();

      std::cout << "Shell Sort Time: " << timeTwo - timeOne << " seconds"<<'\n';

      emhi.readFile(fileName);
      timeOne = clock();
      emhi.QuickSort(emhi.creatArray, 0.0, emhi.arraySize);
      timeTwo = clock();

      std::cout << "Quick Sort Time " << timeTwo - timeOne << " seconds" <<'\n';

    }
  }
}
