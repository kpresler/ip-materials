#include <stdio.h>

int getdate(int *mo, int *day, int *year);

int main() {

  int mon = 0;
  int day = 0;
  int yr = 0;
  char *months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun",
    "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

  while (getdate(&mon, &day, &yr) == 3) {
    printf("%s %d, %d\n", months[mon-1], day, yr);
  }
  
  return 0;
}

int getdate(int *mo, int *day, int *year) {
  printf("enter date in MM/DD/YYYY format: ");
  int count = scanf("%d/%d/%d", mo, day, year);
  return count;
}
