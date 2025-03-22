#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rows;
int cols;

typedef struct {
    int row;
    int col;
} Position;

int generateNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int getLargestValue(int arr[rows][cols]) {
    int largest = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (largest < arr[i][j]) {
                largest = arr[i][j];
            }
        }
    }
    return largest;
}

int getSmallestValue(int arr[rows][cols]) {
    // Compare with largest value to get smallest
    int smallest = getLargestValue(arr);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (smallest > arr[i][j]) {
                smallest = arr[i][j];
            }
        }
    }
    return smallest;
}

Position getPosition(int arr[rows][cols], int target) {
    Position position;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (target == arr[i][j]) {
                position.row = i;
                position.col = j;
                break;
            }
        }
    }
    return position;
}

void printArray(int arr[rows][cols]) {
    printf("\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void fillArray(int arr[rows][cols]) {
    int min, max;
    printf("Enter range of numbers (min max): ");
    scanf("%d %d", &min, &max);

    srand(time(NULL));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = generateNumber(min, max);
        }
    }
}

int main() {
    printf("Enter the size of the 2D array you want: ");
    scanf("%d %d", &rows, &cols);

    int arr[rows][cols];
    fillArray(arr);
    printArray(arr);

    int largest = getLargestValue(arr);
    int smallest = getSmallestValue(arr);
    Position largestPosition = getPosition(arr, largest);
    Position smallestPosition = getPosition(arr, smallest);
    printf("\nSmallest Value: %d | Position: [%d][%d]\n", smallest,
           smallestPosition.row, smallestPosition.col);
    printf("Largest Value: %d | Position: [%d][%d]\n", largest,
           largestPosition.row, largestPosition.col);

    return 0;
}
