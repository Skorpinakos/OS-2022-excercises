#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/mman.h>
int main(){
    int numbers=1000000;

    //scanf("%d" , &n);
    int n=4;
    int i,j;
    
    
    pid_t pid1,pid2;
    //int arr[4]={0,0,0,0};
    int start;
    int end;
    
    int id;
    int returnStatus=0;
    long long int *sum;
    sum = (long long int*)mmap ( NULL, n*sizeof(long long int),PROT_READ | PROT_WRITE,MAP_SHARED | MAP_ANONYMOUS, 0, 0 );

    
        
        pid1 = fork();
        pid2 = fork();
        //long long int sum[1]={0};
        if(!pid1 && !pid2){
            id=0;
            //parent parent 0
        }
        if(!pid1 && pid2){
            id=1;
            //parent child 1
        }
        if(pid1 && !pid2){
            id=2;
            //child parent 2
        }
        if(pid1 && pid2){
            id=3;
            //child  child 3
        }

        //sum[id]=0;
        long long int temp=0;
        start=id*(numbers/n);
        end=(id+1)*(numbers/n);
        for (j=start+1; j<=end;j++){
            temp=temp+j;
        }
        //printf("im the %d process and i calculated :%li\n",id,temp);
        sum[id]=temp;
        //arr[id*size_t(arr[0])]=sum;

        if (!pid1 && !pid2){
            wait(NULL);

            printf("final reults from all processes:\n%li\n%li\n%li\n%li\n",sum[0],sum[1],sum[2],sum[3]);
            long long int final_sum=0;
            for(i=0;i<=n;i++){
                final_sum=final_sum+sum[i];
            }
            long long int test =500000500000;
            printf("calculated: %li\n  supposed: %li\n",final_sum,test);
        }
        
        

        

    
}