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


fib[0] = 1;
fib[1] = 1;

for(i = 2 ; i < n ; i++){
    pid_t pid = fork();
    
    if((pid == 0)){
        fib[i] = fib[i - 1] + fib [i - 2];
    }
    else{
        //printf("Parent in %d waits \n", i);
        waitpid(pid, NULL, 0 );
        //printf("Parent in %d ends\n",i );
        return 0;
    }    
}

for(i =0; i< n;i++)
    printf("%d ",fib[i] );
printf("\n");
return 0;
}