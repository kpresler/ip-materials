void toUpper(char * orig){

    while (*orig){
        if (*orig >=97 && *orig <= 122) *orig -= 32;
        orig++;
    }



}
