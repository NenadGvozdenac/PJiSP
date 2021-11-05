#include <stdio.h>
#include <string.h>

#define KOD int main() { char str[50]; char str1[50]; printf("Unesite string: "); gets(str);  printf("%s", strcmp(strrev(strcpy(str1, str)), str) == 0 ? "Isti su" : "Nisu isti");  return 0; }



KOD;