#include <iostream>
#include <vector>
#include <omp.h>
#include <climits>

using namespace std;

void min_reduction(vector<int>& arr) {
  int min_value = INT_MAX;
  #pragma omp parallel for reduction(min: min_value)
  for (int i = 0; i < arr.size(); i++) {
    if (arr[i] < min_value) {
      min_value = arr[i];
    }
  }
  cout << "\nMinimum value: " << min_value << endl;
}

void max_reduction(vector<int>& arr) {
  int max_value = INT_MIN;
  #pragma omp parallel for reduction(max: max_value)
  for (int i = 0; i < arr.size(); i++) {
    if (arr[i] > max_value) {
      max_value = arr[i];
    }
  }
  cout << "Maximum value: " << max_value << endl;
}

void sum_reduction(vector<int>& arr) {
  int sum = 0;
   #pragma omp parallel for reduction(+: sum)
   for (int i = 0; i < arr.size(); i++) {
    sum += arr[i];
  }
  cout << "Sum: " << sum << endl;
}

void average_reduction(vector<int>& arr) {
  int sum = 0;
  #pragma omp parallel for reduction(+: sum)
  for (int i = 0; i < arr.size(); i++) {
    sum += arr[i];
  }
  cout << "Average: " << (double)sum / arr.size() << endl;
}

int main() {
  vector<int> arr;
  int size,ele;
  cout<<"\nEnter the number of element:";
  cin>>size;
  for(int i=0;i<size;i++)
  {
  	cout<<"Enter element: ";
  	cin>>ele;
  	arr.push_back(ele);
  }
  cout<<"\n************OUTPUT*************";

  min_reduction(arr);
  max_reduction(arr);
  sum_reduction(arr);
  average_reduction(arr);
  
  cout<<"\n*******************************";
}

/*
 ~/Desktop/asmeeeee/ g++ -fopenmp parallel_reduction.cpp -o reduction
 ~/Desktop/asmeeeee/ ./reduction                                     

Enter the number of element:5
Enter element: 23
Enter element: 34
Enter element: 56
Enter element: 12
Enter element: 89

************OUTPUT*************
Minimum value: 12
Maximum value: 89
Sum: 214
Average: 42.8

*******************************%    
*/
