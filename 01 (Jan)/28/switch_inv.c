#include <stdio.h>

// Driver Code
int main(){
    int day;
    printf("Please enter a day of the week (1-indexed): ");

    scanf("%d", &day);

    printf("The day with number %d is ", day);
    switch (day) {
      case 1:
          printf("Monday");
          break;
      case 2:
          printf("Tuesday");
          break;
      case 3:
          printf("Wednesday");
          break;
      case 4:
          printf("Thursday");
          break;
      case 5:
          printf("Friday");
          break;
      case 6:
          printf("Saturday");
          break;
      case 7:
          printf("Sunday");
          break;
      default:
          printf("Invalid Input");
          break;
      }
    printf("\n");
    return 0;
}
