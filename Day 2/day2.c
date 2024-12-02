#include <stdio.h>
#include <string.h>

int main() {
   FILE* fptr = fopen("input.txt", "r");

   // 20 colums, 1000 rows
   int arr[50][1000];
   char line[50];
   int num, count;
   int index = 0;
   while (fgets(line, sizeof(line), fptr)) {
      count = 0;
      char* token = strtok(line, " \t\n");
      printf("Index: %d\n", index);
      while (token != NULL) {
         if (sscanf(token, "%d", &num) == 1) {
            printf("\tNumber %d: %d\n", count, num);
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


}
