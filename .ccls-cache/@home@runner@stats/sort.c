void swap(double *a, double *b) {
    double temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(double arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

double* sortArray(double input[], int size) {
    double* output = (double*)malloc(size * sizeof(double));
    if (output == NULL) {
        printf("Memory allocation error!");
        return NULL;
    }

    // Copy the input array into the output array
    for (int i = 0; i < size; i++) {
        output[i] = input[i];
    }

    bubbleSort(output, size);

    return output;
}