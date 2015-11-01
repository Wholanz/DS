/* Author: Hu Liangze;  ID:3120102116;  No.01 */

#include <stdio.h>
#include <stdlib.h>

typedef int Elementtype;
typedef struct tree *Tree;

struct tree{
	Elementtype X;
	Tree left;
	Tree right;
};

	

int main()
{
	       int Thesametree(Tree T1,Tree T2);
		   Tree insert(Elementtype x,Tree T2);
		   int a[10] , b[10] , n , l , i , j ;
		   Tree  T1=NULL , T2=NULL ;
		   scanf("%d",&n);

		   while(n){
			        scanf("%d",&l);
					
					for(j=0;j<n;j++)
						{
							scanf("%d",&a[j]);
							T1=insert(a[j],T1);
						}
					for(i=0;i<l;i++)
					{
						
                        for(j=0;j<n;j++)
						{
							scanf("%d",&b[j]);
							T2=insert(b[j],T2);
						}
						
						if(Thesametree(T1,T2))
							printf("Yes\n");
						else printf("No\n");
						free(T2);
						T2=NULL;
					}
					scanf("%d",&n);
					free(T1);
					T1=NULL;
		   }
	
}

int Thesametree(Tree T1,Tree T2)
{
	
	if(T1==NULL&&T2==NULL) return 1;
	if(T1->X!=T2->X) return 0;
	return (Thesametree(T1->left,T2->left)&&Thesametree(T1->right,T2->right));
}

Tree insert(Elementtype x,Tree T2)
{

	if(T2==NULL) 
	{
		T2=(Tree)malloc(sizeof(struct tree));
	    T2->X=x;
		T2->left=NULL;
		T2->right=NULL;
		return T2;
	}

     else if(x < T2->X) 
		T2->left=insert(x,T2->left);
	else if(x>T2->X) 
		T2->right=insert(x,T2->right);
	else 
		printf("Wrong input!");

	return T2;
}