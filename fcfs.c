#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct fcfs
{
char pname[5];
int AT,BT,TAT,PCT;
};
void main()
{	int n,i,j,temp1,temp2;
	char temp3[5];
	printf("enter number of processes");
	scanf("%d",&n);
	int GCE[2*n];
	GCE[0]=0;
	struct fcfs S[n];
	for(i=0;i<n;i++)	//input
	{
		printf("enter name for process %d",i);
		scanf("%s",&S[i].pname);
		printf("enter AT for process %d",i);
		scanf("%d",&S[i].AT);
		printf("enter BT for process %d",i);
		scanf("%d",&S[i].BT);
	}
	for(i=0;i<n-1;i++)	//sorting prosesses on the basis of A.T
	{
		for(j=0;j<n-1-i;j++)
		{
			if(S[i].AT>S[i+1].AT)
			{
				temp1=S[i].AT;
				S[i].AT=S[i+1].AT;
				S[i+1].AT=temp1;

				temp2=S[i].BT;
				S[i].BT=S[i+1].BT;
				S[i+1].BT=temp2;

				strcpy(temp3,S[i].pname);
				strcpy(S[i].pname,S[i+1].pname);
				strcpy(S[i+1].pname,temp3);
			}
		}
	}
	i=0;j=1;int k=0,l=0,temp4;
	while(l!=n)
	{
		if(S[0].AT==0)
		{
			if(j==1)
			{
				GCE[j]=S[i].BT;
				S[i].PCT=S[i].BT;
				j++;	l++;i++;
			}
			else
			{
				if(S[i].AT<=S[i-1].PCT)
				{
					S[i].PCT=S[i-1].PCT+S[i].BT;
					GCE[j]=S[i].PCT;
					i++;j++;l++;
				}

				else
				{
					
					GCE[j]=S[i].AT;
					j++;
					GCE[j]=GCE[j-1]+S[i].BT;
					S[i].PCT=GCE[j];
					i++;j++;l++;
				}
			}
		}

		else
		{
			if(j==1)
			{
				GCE[j]=S[i].AT;
				j++;
				S[i].PCT=S[i].BT+GCE[j-1];
				GCE[j]=S[i].PCT;
				j++;	l++;i++;
			}
			else
			{
				if(S[i].AT<=S[i-1].PCT)
				{
					S[i].PCT=S[i-1].PCT+S[i].BT;
					GCE[j]=S[i].PCT;
					i++;j++;l++;
				}

				else
				{
					
					GCE[j]=S[i].AT;
					j++;
					GCE[j]=GCE[j-1]+S[i].BT;
					S[i].PCT=GCE[j];
					i++;j++;l++;
				}
			}
		}
		
	}
for(i=0;i<j;i++)
{
printf("\t %d \t",GCE[i]);
}
}






















