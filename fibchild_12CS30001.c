#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main()

{



int a=0, b=1, n,i;
int x;


printf("Enter the number of a Fibonacci Sequence:\n");
scanf("%d", &x);



//printf("number : %d \n", n); // make a child print this too

for(i = 0;i < x ;i++){

    pid_t pid = fork();
    
    if((pid == 0)){
        if(i == 0)
            printf("Fib(%d) : %d \n",i+1, b);
        else{
            n=a+b;
            printf("Fib(%d) : %d \n",i+1, n);
            a=b;
            b=n; 
        }       
    }
    else{
        //printf("Parent in %d waits \n", i);
        waitpid(pid, NULL, 0 );
        //printf("Parent in %d ends\n",i );
        return 0;    
    }

}
// if (pid == 0)
// {
    // printf("Child is make the Fibonacci\n");
    // printf("0 %d ",n);
    // while (i>0) {
    //     n=a+b;
    //     printf("%d ", n);
    //     a=b;
    //     b=n;
    //     i--;
    //     if (i == 0) {
    //         printf("\nChild ends\n");
    //     }
//     }
// }
//     else 
//     {
//         printf("Parent is waiting for child to complete...\n");
//         waitpid(pid, NULL, 0);
//         printf("Parent ends\n");
//     }
    return 0;
}