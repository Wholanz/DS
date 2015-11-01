/* Author:Yi Wang; ID:3120101996; No.01 */
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

#ifndef _Tree_H

struct TreeNode;
typedef struct TreeNode *Position;
typedef struct TreeNode *SearchTree;

SearchTree MakeEmpty(SearchTree T);
SearchTree Insert(int x, SearchTree T);

#endif

struct TreeNode
{
  int Element;
  SearchTree Left;
  SearchTree Right;

};

SearchTree MakeEmpty(SearchTree T)
{
	if(T!=NULL)
  {
	  MakeEmpty(T->Left);
	  MakeEmpty(T->Right);
	  free(T);
  }
  return NULL;
}


SearchTree Insert(int x,SearchTree T)
{
	if(T==NULL)
	{
		T=(SearchTree)malloc(sizeof(struct TreeNode));
		if(T==NULL)
			printf("Out of space!\n");
		else
		{
			T->Element=x;
			T->Left=T->Right=NULL;
		}
	}
	else if(T!=NULL&&T->Element==0)
	{
		T->Element=x;
		T->Left=T->Right=NULL;
	}
	else if(x<T->Element)
		T->Left=Insert(x,T->Left);
	else if(x>T->Element)
		T->Right=Insert(x,T->Right);

	return T;
}

int cmp(SearchTree T1, SearchTree T2)
{

	while(T1!=NULL&&T2!=NULL)
	{
		if(T1->Element==T2->Element)
	     {
			return (cmp(T1->Left,T2->Left)+cmp(T1->Right,T2->Right));   
	      }
	   else
        return 1;
	}
	if((T1!=NULL&&T2==NULL)||(T1==NULL&&T2!=NULL))
          return 1;
	return 0;
}

int main()
{
  int n=0,l,i,j,tmp;
  int a[30];
  SearchTree T1;
  T1=(SearchTree)malloc(sizeof(struct TreeNode));
  if(T1==NULL)
   {
	  printf("Error\n");
      return 0;
   }
  T1->Element=0;
  while(1)
   {
     scanf("%d",&n);
     if(n==0)
	   return 0;
     else
     {
       scanf("%d",&l);
       for(i=0;i<n;i++)
        {
          scanf("%d",&tmp);
          T1=Insert(tmp,T1);
        }
       for(i=0;i<l;i++)
        {
	      SearchTree T2;
	      T2=(SearchTree)malloc(sizeof(struct TreeNode));
          if(T2==NULL)
           {
		     printf("Error\n");
             break;
           }
	      T2->Element=0;
	      for(j=0;j<n;j++)
	       {
	         scanf("%d",&tmp);
	         T2=Insert(tmp,T2);
	       }
	      a[i]=cmp(T1,T2);
	      ///
        }
      for(j=0;j<l;j++)
	    if(a[j]==0)
		  printf("Yes\n");
	    else 
		  printf("No\n");
        ///
      }
   }
 return 0;
}

