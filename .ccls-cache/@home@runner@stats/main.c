#include <stdio.h>  // input output
#include <stdlib.h> //malloc and free
#include <stdbool.h> //bool
#include <math.h> // rounds

//definging Largest finite positive value of double
#define SENTINEL (double)1.7976931348623157e+308
#define verbose false

//methode for change (swap) value in variable
void swap(double *a, double *b) {
    double temp = *a;
    *a = *b;
    *b = temp;
}

//https://www.geeksforgeeks.org/bubble-sort/
void bubbleSort(double arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

double* sortArray(double input[]) {
    int size = 0;
    while (input[size] != SENTINEL) {
        size++;
    }

    // Allocating memory for sorting
    double* output = (double*)malloc((size + 1) * sizeof(double));
    if (output == NULL) {
        printf("Memory allocation error!");
        return NULL;
    }

    // Copy the input array into the output array
    for (int i = 0; i < size; i++) {
        output[i] = input[i];
    }
    output[size] = SENTINEL; // Set the sentinel value at the end

    // Bubble sort the output array
    bubbleSort(output, size);

    if(verbose){
      printf("----------------\nSorting Array\n");
      for (int i = 0; i < size; i++) {
        printf("[%.2lf],", output[i]);
      }
      printf("\n--------------\n");
    }

    return output;
}


//methode for get size of array
int getSize(double *array) {
    int n = 0;
    while (array[n] != SENTINEL) {
        n++;
    }
    return n;
}

double getQ(double *input, int Q){
  double qValue;
  //sorting the input array
  double* sortedArray = sortArray(input);

  //getting size of array
  int size = getSize(sortedArray);

  double possition = (size + 1) / (4 /(double)Q );

  if(verbose){
      printf("--------------\nGetting Q\n");
      printf("Array size : %d\n", size);
      printf("Q : %d\n", Q);
      printf("possition : %lf\n", possition);
      printf("--------------\n");
  }

  double roundedNum = round(possition);
  bool iswhole = possition == roundedNum;
  
  if(verbose){
      printf("--------------\nChecking isWhole\n");
      printf("before round : %lf\n", possition);
      printf("after rounding : %lf\n", roundedNum);
      printf("iswholoe %b\n", iswhole);
      printf("--------------\n");
  }
  
  int intPos = (int) possition;

  if (iswhole  == true){
    qValue = sortedArray[intPos - 1]; 
    //since arrays starting from 0
  }else{
    double valueOne = sortedArray[intPos - 1];
    double valueTwo = sortedArray[intPos];

    qValue = ( valueOne + valueTwo )/2;
    
  }

  return qValue;
}

//methode for get mode
double getMode(double *input){
  double mode = 0.0;
  for(int i = 0; i < getSize(input) - 1; i++){
    if(input[i] > mode){
      mode = input[i];
    }
  }
  return mode;
}

//methode for get mode
double getMean(double *input){
  double sum = 0.0;
  for(int i = 0; i < getSize(input) - 1; i++){
    sum = sum + input[i];
  }
  double mean = sum / (getSize(input) - 1);
  return mean;
}


//main methode heres the place programme start executing
int main() {
    //we have to mark last value of the arry due to langwage limitation
    double input[] = {0.5, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, SENTINEL};
    printf("-------------------------------\n");
    printf("Five Number Summery\n");
    printf("1. Q1 : %lf\n" , getQ(input,1));
    printf("2. Q2 : %lf\n" , getQ(input,2));
    printf("3. Q3 : %lf\n" , getQ(input,3));
    printf("4. Mode : %lf\n" , getMode(input));
    printf("5. Mean : %lf\n" , getMean(input));
    printf("-------------------------------\n");
    return 0;
}
