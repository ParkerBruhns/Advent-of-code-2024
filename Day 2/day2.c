#include <stdio.h>
#include <string.h>

void print_2d_arr(int arr[][1000], int arr_len, int arr_height);

int main() {
   FILE* fptr = fopen("input.txt", "r");

   // 50 colums, 1000 rows
   int arr_len = 50;
   int arr_height = 1000;
   int arr[50][1000];

   char line[50];
   int num, count;
   int index = 0;
   while (fgets(line, sizeof(line), fptr)) {
      count = 0;
      char* token = strtok(line, " \t\n");
      while (token != NULL) {
         if (sscanf(token, "%d", &num) == 1) {
            arr[count][index] = num;
            count++;
         } else {
            printf("Failed");
            return 1;
         }
         token = strtok(NULL, " \t\n");
      }
      index++;
   }

   print_2d_arr(arr, arr_len, arr_height);

}

void print_2d_arr(int arr[][1000], int arr_len, int arr_height) {
   for (int j = 0; j < arr_height; j++) {
      printf("[");
      for (int i = 0; i < arr_len; i++) {
         if (arr[i][j] != 0) {
            printf("%d", arr[i][j]);
            if (j != arr_len - 1) {
               printf(", ");
            }
         }
      }
      printf("]\n");
   }

}
