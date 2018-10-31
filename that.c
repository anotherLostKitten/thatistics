#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<time.h>
void sizinga(int i, char*p) {
  if(i){
    sizinga(i>>10,p+1);
    if(i&1023)printf("%d %s ",i&1023,*p+p);
  }
}
int main() {

  char*filename="a.out";

  struct stat*that=malloc(sizeof(struct stat));
  stat(filename,that);
  printf("your file:\n%s\nthis fella got a size of:\n",filename);
  char*sizes="\5\n\23\34%bytes\0kilobytes\0megabytes\0gigabytes\0tetrabytes";
  sizinga(that->st_size,sizes);
  printf("\nperms:\n");
  char*perms="-xwrxwrxwr";
  printf("%c",that->st_mode&S_IFDIR?'d':'-');
  for(int i=10;--i;)printf("%c",perms[i*(that->st_mode*2>>i&1)]);
  printf("\nlastaccessed\n%s\n", ctime(&(that->st_atime)));
  return 0;
}
