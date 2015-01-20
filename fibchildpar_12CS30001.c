#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()

{

int n,i;

printf("Enter the number of a Fibonacci Sequence:\n");
scanf("%d", &n);

int *fib = (int *)malloc(n*sizeof(int));
pid_t parID = getpid();

int a = 1;
int b = 1,c;
int x = 1; 
int temp = 0;
int temp2;
for(i = 1 ; i <= n ; i++){
    pid_t pid = fork();
    
    if((pid == 0)){
        while(x<=i){
            temp = a;
            c = a + b;
            a = b;
            b = c;
            x++;
        }
        //printf("returning %d\n",temp );
        exit(temp);
    }
    
}

for(i =0; i< n;i++){
    pid_t child = wait(&temp2);
    //printf("recieved: %d\n",temp2 >> 8 );

    //printf("parent: %d child: %d\n",parID,child );
    fib[i] = temp2 >> 8;
}

int temp3,d ;
for (c = 1 ; c <= n - 1; c++) {
    d = c;
 
    while ( d > 0 && fib[d] < fib[d-1]) {
      temp3          = fib[d];
      fib[d]   = fib[d-1];
      fib[d-1] = temp3;
 
      d--;
    }
}
    
for(i =0; i< n;i++)
    printf("Fib(%d) : %d \n",i+1, fib[i]);
printf("\n");
return 0;
}