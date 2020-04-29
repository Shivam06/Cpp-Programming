#include "../../helper_functions.cpp"

// Given heights of the building, task is to find max consecutive steps which 
// can be taken which results in increase of altitude.

int maxSteps(int a[], int n) {
   
   int i = 0, max = 0, steps = 0;
   
   while (i < n-1) {
       if (a[i+1] > a[i]) {
           steps++;
           if (steps > max) {
                max = steps;
           }
           i++;
           continue;
       }
       
       steps = 0;
       i++;
   }
   
   return max;
}

int main() {

	int a[] = {1,2,2,3,2};
	cout << maxSteps(a, 5) << endl;
	return 0;
}