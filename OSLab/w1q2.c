#include <unistd.h>
#include <stdio.h>
int main(){
    int p=fork();
    if(p==0){
        printf("Child: Process id: %d\n",getpid());
        printf("Process id of parent: %d\n",getppid());
    }
    else if(p>0){
        printf("Parent: Process id: %d\n",getpid());
        printf("Process id of child: %d\n",p);
    }
    else{
        printf("Fork failed.\n");
    }
    printf("\n");
    return 0;
}