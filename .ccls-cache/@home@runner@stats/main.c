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

double getMin(double *input){
  double min = SENTINEL;
  for(int i = 0; i < getSize(input); i++){
    if(input[i] < min){
      min = input[i];
    }
  }
  return min;
}

//methode for get mode
double getMax(double *input){
  double max = 0.0;
  for(int i = 0; i < getSize(input); i++){
    if(input[i] > max){
      max = input[i];
    }
  }
  return max;
}

//methode for get mode
double getMean(double *input){
  double sum = 0.0;
  for(int i = 0; i < getSize(input); i++){
    sum = sum + input[i];
  }
  double mean = sum / (getSize(input));
  return mean;
}


//main methode heres the place programme start executing
int main() {
    double input[] = 
  {
  0,
  1.0, 
  2.0, 
  3.0, 
  4.0, 
  5.0, 
  6.0, 
  7, 
  8.0, 
  SENTINEL};
  
    printf("-------------------------------\n");
    printf("Five Number Summery\n");
    printf("1. Min : %lf\n" , getMin(input));
    printf("2. Q1 : %lf\n" , getQ(input,1));
    printf("3. Q2 : %lf\n" , getQ(input,2));
    printf("4. Q3 : %lf\n" , getQ(input,3));
    printf("5. Max : %lf\n" , getMax(input));
    printf("-------------------------------\n");
    printf("Central Tendency\n");
    printf("6. Mean : %lf\n" , getMean(input));
    printf("7. Median : %lf\n" , getQ(input,2));
    printf("-------------------------------\n");
    return 0;



  //------|     |     |----------------
  //0.0   1.5   4.0   6.5           8.0
}
