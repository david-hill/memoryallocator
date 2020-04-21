#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]){
 int *ptr;
 unsigned long i,j,n,s;
 char *p;

 setbuf(stdout, NULL); /* disable buffering for printf */

 if(argc==1) {
   printf("Enter number of MB you want to allocate: ");
   scanf("%lu",&n);
 } else {
   n = strtol(argv[1], &p, 10);
   if(n == 0) {
     printf("Error while converting 1st commandline parameter to interger.\n");
     exit(0);
   }
 } 
 n*=256 ; n*=1024;

 i=32; ptr==NULL; n+=4194304;
 while((i-- > 0) && (ptr==NULL)) {
   n-=4194304;
   printf("Attempting to allocate %lu MB ...\n",n*sizeof(int)/1048576);
   ptr=(int*)malloc(n*sizeof(int));
 }
 if (ptr==NULL){
   printf("ERROR!Memory not allocated!\n");
   exit(0);
 }

 printf("Filling memory.....\n");
 for (i = 0; i < n; i++){
    ptr[i] = 1;
 }

 printf("Sleeping ...\n");
 for ( i = 1; i < 15; i++) {
   for ( j = 0; j < 12; j++) { sleep(5); printf("."); }
   s = i*60;
   printf(" %4i seconds.\n", s);
 }

 printf("Free memory.\n");
 free(ptr);

 return 0;
}

