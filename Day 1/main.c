#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void* a, const void* b);
char* int_arr_str(int arr[], int arr_len);

int main() {
   FILE* fptr;
   fptr = fopen("input.txt", "r");

   int arr1[1000];
   int arr2[1000];
   int arr_len = 1000;


   int i = 0;
   char line[20];
   while (fgets(line, 20, fptr)) {
      // Test code
      char fullLine[20];
      strcpy(fullLine, line);

      int num1, num2;

      if (sscanf(line, "%d   %d", &num1, &num2) == 2) {
         arr1[i] = num1;
         arr2[i] = num2;
         // printf("arr1[%d]: %d -- arr2[%d]: %d\n", i, arr1[i], i, arr2[i]);
         i++;
      } else {
         printf("Failed to parse numbers");
         return EXIT_FAILURE;
      }
   }
   // //Part 1
   // qsort(arr1, arr_len, sizeof(int), compare);
   // qsort(arr2, arr_len, sizeof(int), compare);
   //
   // int total = 0;
   // for (int i = 0; i < arr_len; i++) {
   //    total += abs(arr1[i] - arr2[i]);
   // }
   // printf("%d", total);

   // Part 2
   int final_arr[arr_len];
   for (int i = 0; i < arr_len; i++) {
      int pop = 0;
      for (int j = 0; j < arr_len; j++) {
         if (arr1[i] == arr2[j]) {
            pop++;
         }
      }
      final_arr[i] = arr1[i] * pop;
   }
   
   int total = 0;
   for (int i = 0; i < arr_len; i++) {
      total += final_arr[i];
   }
   printf("Total: %d\n", total);

   fclose(fptr);
}

char* int_arr_str(int arr[], int arr_len) {
   int est_size = arr_len * (10 + 2) + 2;
   char* str = malloc(est_size);
   strcat(str, "[");
   for (int i = 0; i < arr_len; i++) {
      char buff[20];
      sprintf(buff, "%d", arr[i]);
      strcat(str, buff);
      if (i != arr_len - 1) {
         strcat(str, ", ");
      }
   }
   strcat(str, "]");
   return str;
}

int compare(const void* a, const void* b) {
   return *(int*)a - *(int*)b;

}
