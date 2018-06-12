#include <stdio.h>
#include <string.h>


int main(int argc, char *argv[]){
char alpha[] = "abcdefghijklmnopqrstuvwxyz";
char input[100];
char message[100];
char keyword[100];
int indm;
int indk;
int indc;
char encryptm[100];
char lete;
char tempkey[100] = " ";

if (argc > 3){
  printf("please input a message and a keyword");
}

/*printf("Enter message: ");
fgets(input, 100, stdin);
sscanf(input, "%s", message);
printf("Enter keyword: ");
fgets(input, 100, stdin);
sscanf(input, "%s", keyword);*/
//printf("%d", strlen(keyword));
sscanf(argv[1], "%s", message);
sscanf(argv[2], "%s", keyword);

int rep = strlen(message) / strlen(keyword) + 2;

for (int k = 1; k < rep; k++){
  strcat(tempkey, keyword);
  //printf("%s\n", tempkey);
  tempkey[99] = '\0';
}

//printf("%s", tempkey);

int per = 0;
int indkm;
int dif;
int space;

for (int i = 0; i < strlen(message); i++){
  for (int j = 0; j < strlen(alpha); j++){
    if (message[i] == alpha[j]){
      indm = j;
     // printf("found m = %d", indm);
    }
    if (tempkey[i + 1] == alpha[j]){
      indk = j;
      //printf("found k = %d", indk);
    }
  }
  indkm = indk + indm;
  if (indkm >= 26){
    dif = indkm - 26;
    indkm = dif;
}
//printf("indkm = %d", indkm);

  lete = alpha[indkm];
  encryptm[per] = lete;
  encryptm[per + 1] = '\0';
  per++;

//  strcat(encryptm, lete);
  //printf("letter: %d", per);
  //printf("letter = %c", lete);
}
  printf("Encrypted Message: %s", encryptm);

}
