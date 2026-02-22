#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// this function takes a message in binary form (i.e., a message that only includes
// 0s and 1s) as a string and returns decimal equivalent of it as an integer.
// Example: string message "111101" return 61 as an int, since 61 is decimal
// equivalent of "111101".  
int str_to_int(char msg[], int len) {
  
  // TODO: FINISH IMPLEMENTATION
  int value = 0;
  for (int i = 0; i < len; ++i) {
    value = value << 1;
    value += (msg[i] == '0' ? 0 : 1);
  }
  return value; // STUB: REPLACE THIS
}

// alternate str_to_int implementation
int str_to_int_alt(char msg[], int len) {
  
  // TODO: FINISH IMPLEMENTATION
  int value = 0;
  for (int i = 0; i < len; ++i) {
    // note: ascii code of '1' is 49, '0' is 48
    value += ((int)(msg[len-1-i] - 48) << i);
  }
  
  return value; // STUB: REPLACE THIS
}


// this function takes a decimal value as an integer and creates a string
// including 0s and 1s that is the binary representation of the integer number.
// Example: number 61 (as an int) results in "111101", since "111101" is
// binary representation of the decimal value 61.  
void int_to_str(int num_encrypted, char msg_encrypted[], int len) {

  // TODO: FINISH IMPLEMENTATION
  for (int i = 0; i < len; ++i) {
    // note: ascii code of '1' is 49, '0' is 48
    msg_encrypted[i] = ((num_encrypted >> (len-1-i)) & 1) + '0';
  }
}


int main() {

  int num_msg = 0; // the binary message as an int
  char msg[33] = {'\0'}; // this will hold the binary message as a string
  int n = -1; // n used in encryption

  // test if "111101" is coverted to 61
  printf("Debug test: %d\n", str_to_int("111101", 6)); 
  // test if 61 is converted to "111101"
  char test[33] = {'\0'};
  int_to_str(61, test, 6);
  printf("Debug test: %s\n", test);

  printf ("Enter the message to be encrypted in binary format (max 32 bit): ");
  if (scanf(" %s", msg) != 1) { // read the binary message as a string
    printf("Could not read the message!\n");
    return 1;
  }  

  int len = strlen(msg); // length of the binary message
  
  // convert the string binary message to an integer
  num_msg = str_to_int(msg, len);
  
  // read n
  printf ("Enter n: ");
  if (scanf("%d", &n) != 1) {
    printf("Could not read n!\n");
    return 1;
  }

  int num_encrypted = num_msg;
  // TODO: NOW PERFORM THE ENCRYPTION BY SHIFTING "msg" n - 1
  // TIMES AND XORING THE CORRESPONDING COLUMNS 
  for (int i = 1; i < n; ++i) {
    num_encrypted = num_encrypted ^ (num_msg << i);
  }

  char msg_encrypted[33] = {'\0'};
  int encrypted_len = len + n - 1;

  // convert the encrypted message back to a string
  int_to_str(num_encrypted, msg_encrypted, encrypted_len);

  // print out the original and encrypted messages as strings
  printf("Plain binary message is %s and encrypted message is %s \n", msg, msg_encrypted);
  return 0;

}
