#include <string.h>
#include "string_functions.h"

/*
    Returns in the third argument the concatenation of the first
    argument and the second argument, provided that there is
    sufficient space in third argument, as specified by the fourth.
    e.g.
        concat("alpha", "beta", result, 10) puts "alphabeta" into result and returns 0
        concat("alpha", "gamma", result, 10) puts nothing into result and returns 1
*/
int concat(const char word1[], const char word2[], char result[], int result_capacity){

   //TODO: replace the following stub with a correct function body so that 
   //      this function behaves as indicated in the comment above
   //
   //NOTE: you may not use the strcat or strcpy library functions in your solution!

  if (result_capacity < (int) (strlen(word1) + strlen(word2) + 1)) {
    result[0] = '\0';
    return 1;
  }

    int idx = 0;
    for (size_t i = 0; i < strlen(word1); ++i) {
     result[idx++] = word1[i];
    }
    for (size_t i = 0; i < strlen(word2); ++i) {
     result[idx++] = word2[i];
    }

    result[idx] = '\0';
    return 0;

}

