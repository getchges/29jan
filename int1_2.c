//5. Write a C / python code to implement Shortest job first CPU scheduling algorithm. 
//Solution: 
//SJF using Non-preemitive mode without Arrival Time 
 
#include<stdio.h> 
int main()  
{     
    int n,p[20],bt[20],wt[20],tat[20]; 
    int i,j; 
    int temp1=0,temp2=0; 
    int pos;     
    float avg_wt,avg_tat; 
     
    printf("Enter number of process:");     
    scanf("%d",&n); 
  
    printf("\nEnter Burst Time:\n");     
    for(i=0;i<n;i++) {    
        printf("p%d:",i+1);        
        scanf("%d",&bt[i]);         
        p[i]=i+1;           //it contains process number for table form   
    } 
    //sorting burst time in ascending order using selection sort 
    int temp;  
    for(i=0;i<n;i++) {
        pos=i;         
        for(j=i+1;j<n;j++) {             
            if(bt[j]<bt[pos])                 
                pos=j;        
        } 
        // BurstTime moving one position to another position 
        temp=bt[i];     
        bt[i]=bt[pos];      
        bt[pos]=temp; 
        // at the same time process also  
        temp=p[i];         
        p[i]=p[pos];        
        p[pos]=temp;    
    } 
  
    //calculate waiting time 
     
    wt[0]=0;   //waiting time for first process will be zero     
    for(i=1;i<n;i++) {      
        wt[i]=0;  
        for(j=0;j<i;j++)       
            wt[i]+=bt[j]; 
        temp1+=wt[i]; 
    } 
    avg_wt=(float)temp1/n;   //average waiting time 
    printf("\nProcess\t    Burst Time    \tWaiting Time\t Turnaround Time"); 
    for(i=0;i<n;i++) {         
        tat[i]=bt[i]+wt[i];  //calculate turnaround time        
        temp2+=tat[i];        
        printf("\np%d\t\t  %d\t\t    %d\t\t\t%d",p[i],bt[i],wt[i],tat[i]); 
    }
    avg_tat=(float)temp2/n;     //average turnaround time   
    printf("\n\nAverage Waiting Time=%f",avg_wt);    
    printf("\nAverage Turnaround Time=%f\n",avg_tat); 
}