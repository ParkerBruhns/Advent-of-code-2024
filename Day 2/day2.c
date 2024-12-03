#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_2d_arr(int** arr, int cols, int rows);

int main() {
   FILE* fptr = fopen("input.txt", "r");
   if (fptr == NULL) {
      fprintf(stderr, "Failed to open file");
      return EXIT_FAILURE;
   }

   // 20 colums, 1000 rows
   int rows = 1000;
   int cols = 20;

   // Rows memory allocation
   int** arr = (int**) malloc(rows * sizeof(int*));
   if (arr == NULL) {
      fprintf(stderr, "Memory allocation failed for rows\n");
      return EXIT_FAILURE;
   }

   // Colums memory allocation
   for (int i = 0; i < rows; i++) {
      arr[i] = (int*) malloc(cols * sizeof(int));
      if (arr[i] == NULL) {
         fprintf(stderr, "Memory allocation failed for cols");
         return EXIT_FAILURE;
      }
   }

   char line[50];
   int num;
   int current_row = 0;
   while (fgets(line, sizeof(line), fptr)) {
      char* token = strtok(line, " \t\n");

      int current_col = 0;
      while (token != NULL) {
         if (sscanf(token, "%d", &num) == 1) {
            arr[current_row][current_col] = num;
            current_col++;
         } else {
            puts("Failed");
            return EXIT_FAILURE;
         }
         token = strtok(NULL, " \t\n");
      }
      current_row++;
   }

   for (int i = 0; i < rows; i++) {
      int inc_dec = 0;
      int prev = 0;
      for (int j = 0; j < cols; j++) {
         if (inc_dec == 0) {
            prev = arr[i][j];
         } else if (inc_dec == 1) {

         } else if (inc_dec == 2) {

         }
      }
   }

   print_2d_arr(arr, cols, rows);

   for (int i = 0; i < rows; i++) {
      free(arr[i]);
   }
   free(arr);
}

void print_2d_arr(int** arr, int cols, int rows) {
   for (int i = 0; i < rows; i++) {
      printf("[");
      int printed_any = 0;
      for (int j = 0; j < cols; j++) {
         if (arr[i][j] != 0) {
            if (printed_any) {
               printf(", ");
            }
            printf("%d", arr[i][j]);
            printed_any = 1;
         }
      }
      printf("]\n");
   }

}
