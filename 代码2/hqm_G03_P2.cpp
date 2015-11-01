#include <stdio.h>  
#include <memory.h>  
#include <stdlib.h>

  
int count[100];  	//the numbers of leaf nodes for each level
int maxlevel=1;  	//max level of the tree
  
struct childLink     // used to link children of a node
{  
    int id;  
    childLink *next  ;  //point to the next child
    childLink(){next=0;} 
};  
  
struct Node                                //the nodes of the tree 
{  
    int childNum;                          //number of the child
    childLink *childHead;                  //point to the firsr child
    Node(){childNum=0;childHead=0;}  
}*node;  
  
void CountLeaves(int level,int id)         //count leaves in the level input with an id in this level
{  
    childLink *cl = node[id].childHead;      //strat form the first child
    if(maxlevel<level)maxlevel=level;  
	if(node[id].childNum==0)count[level]++;  
	else  
    while(cl)  
    {                 
        CountLeaves(level+1,cl->id);         //recursively traverse the tree 
        cl=cl->next;  
    }  
}  
  
int main(void)  
{  
      
    int n,m;  
    int i,j,id;  
    childLink *cl=0;
    scanf("%d%d\n",&n,&m); 
	while (n!=0||m!=0)
	{	 
    	node=(Node *)malloc(sizeof(Node)*(n+1));		
    	memset(node,0,sizeof(Node)*(n+1));  			//Initialization
    	memset(count,0,sizeof(int)*(n+1));  			
    	maxlevel=0;
    	cl=0;  
    	for(i=0;i<m;i++)  								//read and save the tree 
    	{  
       		scanf("%d",&id);  
			getchar();
        	scanf("%d",&node[id].childNum);
			getchar();
        	for(j=0;j<node[id].childNum;j++)  
        	{  
            	cl = new childLink;              
            	scanf("%d",&cl->id); 
				getchar();
            	if(node[id].childHead) cl->next=node[id].childHead;  
            	node[id].childHead = cl;  
        	}  
    	}    
    	if(node[1].childNum==0){count[1]=1;maxlevel=1;}  //Determine the special circumstances
    		else   
    		{  
        		count[1]=0;  
        		CountLeaves(1,1);  
    		}  
    	for(i=1;i<maxlevel;i++)  						//output
    		printf("%d ",count[i]);
    	printf("%d\n",count[i]);    
		scanf("%d%d",&n,&m);
		getchar();
	}
	getchar();
    return 0;  
}  
