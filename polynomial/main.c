#include<stdio.h>
int a[100],b[100],i,j,len,k,count=0;
int gh[]={1,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,1};

void div(){
    for(i=0;i<k;i++){
        j=0;
        if(b[i]==1){
            for(j=0;j<17;j++){
                b[i+j]=b[i+j]^gh[j];
            }
            count=0;
        }
    }
}

int main(){
    printf("Enter the length of the frame: ");
    scanf("%d",&len);
    printf("Enter the message:\n");
    for(i=0;i<len;i++)
        scanf("%d",&a[i]);
    
    for(i=0;i<16;i++)
        a[len++]=0;
    
    for(i=0;i<len;i++)
        b[i]=a[i];
    
    k=len;
    div();
    
    printf("Data to be transmitted is:\n");
    for(i=0;i<len;i++)
        printf("%d",b[i]);
    printf("\n");
    
    printf("Enter the received data:\n");
    for(i=0;i<len;i++)
        scanf("%d",&a[i]);
    
    div();
    
    for(i=0;i<len;i++)
        if(a[i]!=0){
            printf("Error in data\n");
            return 0;
        }
    
    printf("No error in data\n");
    return 0;
}
