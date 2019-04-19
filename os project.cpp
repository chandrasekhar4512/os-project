

#include<unistd.h>
#include<stdio.h>
  int main()
{

sleep(3);
int count,j,n,time,remaining,flag=0,qt=1;
int wt=0,tat=0,at[10],bt[10],rt[10];
printf("Enter The Total Number of Process:\t "); 
scanf("%d",&n);
remaining=n; 
for(count=0;count<n;count++)
{

printf("Enter Arrival Time %d :",count+1); 
scanf("%d",&at[count]);
printf("Enter Burst Time %d :",count+1); 
scanf("%d",&bt[count]); 
rt[count]=bt[count];
}


printf("\n\nProcess	\t|Turnaround_Time|	Waiting Time\n\n"); 
for(time=0,count=0;remaining!=0;)
{

if(rt[count]<=qt && rt[count]>0)
{
 
time=time+rt[count]; 
rt[count]=0;
flag=1;
}

else if(rt[count]>0)
{

rt[count]-=qt; 
time+=qt;
}

if(rt[count]==0 && flag==1)
{

remaining--;
printf("P[%d]\t|\t%d\t|\t%d\n",count+1,time-at[count],time-at[count]-bt[count]); 
wt=wt+time-at[count]-bt[count];
tat=tat+time-at[count]; 
flag=0;
}

if(count==n-1) 
count=0;
else if(at[count+1]<=time) 
count++;
else 
count=0;
}

printf("\nAverage Waiting Time= %f\n",wt*1.0/n); 
printf("Average Turnaround Time = %f",tat*1.0/n); 
return 0;
 
}

