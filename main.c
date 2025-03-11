#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rows;
int cols;

typedef struct {
    int x;
    int y;
} Position;

int generateNumber(int min, int max) { return rand() % (max - min + 1) + min; }

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

Position getPosition(int arr[rows][cols], int target) {
    Position position;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (target == arr[i][j]) {
                position.x = i;
                position.y = j;
                break;
            }
        }
    }
    return position;
}

void printArray(int arr[rows][cols]) {
    printf("\n---------------\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("---------------\n");
}

void fillArray(int arr[rows][cols]) {
    int min, max;

    printf("Enter range of numbers (min max): ");
    scanf("%d %d", &min, &max);

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

    srand(time(NULL));
    fillArray(arr);
    printArray(arr);
    int largest = getLargestValue(arr);
    Position position = getPosition(arr, largest);
    printf("\nLargest Value: %d | Position: [%d][%d]\n", largest, position.x,
           position.y);

    return 0;
}
