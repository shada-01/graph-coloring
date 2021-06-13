#include<stdio.h>
#include<stdlib.h>
int n;
int sum;
char colors[7]="abcdef";
char *col_v;
int *ver;

//function to obtain required vertex 
int ver_deg(int **g)
{
 
	int V;
	 for(int i=0;i<n;i++)
	 {
		  sum=-1;
		  for(int j=0;j<n;j++){
		      sum+=g[i][j];
		       }
		      if(sum>=0 && sum<6)
			    { V=i; 
			       break;}

	 }
	 ver[V]=0; //assigning 0 to selected vertex
	return V;

}
   
//checking adjacency
int no_adjacency(int **g,int pro_ver,char c)
{
 for(int i=0;i<n;i++)
{
 if(  g[pro_ver][i]==1 && c==col_v[i] )
 return 0;
}
return 1;
}
   

//coloring the particular vertex
void color(int **g,int pro_ver)
{
 
 for(int i=0;i<6;i++)
{
  if((no_adjacency(g,pro_ver,colors[i]))==1)
    {col_v[pro_ver]=colors[i];
     break;}
}

}


//recursive function
void graph_color(int **g,int bal)
{

	int remove_ver;
	 if(bal==1) //base condition-only one vertex
	 {
	      for(int i=0;i<n;i++)
		 {
		   if(ver[i]==1) //finding unselected vertex 
		        { remove_ver=i; break;}
		  }

		 col_v[remove_ver]='a'; 
	  
	 }
	
	 else
	{
	 
	 	 
		 int flag=0;
		 int **v=(int**)malloc(n*sizeof(int*));
		for(int i=0;i<n;i++)
		 	v[i]=(int*)malloc(n*sizeof(int));
		 
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
			    v[i][j]=g[i][j];
		 
			}
		 }
		 
		 remove_ver=ver_deg(g);
		
		
			  for(int j=0;j<n;j++)
			   {
			   	
				 v[remove_ver][j]=0;
				 v[j][remove_ver]=0; 
                                 //removng all edges associated with that vertex
					     
			    }
			
			
		bal--;
		graph_color(v,bal);
		color(g,remove_ver);

	}
}



void main()
{
	 int m,i,j,k;
	 scanf("%d",&n);
	 scanf("%d",&m);
         int **g;
	 g=(int**)malloc(n*sizeof(int*));
	 for(int i=0;i<n;i++)
	 	g[i]=(int*)malloc(n*sizeof(int));
	 for(int k=0;k<m;k++)
	 {
		  scanf("%d %d",&i,&j);
		  g[i][j]=1;
		  g[j][i]=1;

	}

	for(int i=0;i<n;i++)
	{
		 for(int j=0;j<n;j++)
		 {
			   if(g[i][j]!=1)
			   g[i][j]=0; 
			
		 }
		
	}
	
	for(int i=0;i<n;i++)
		g[i][i]=1;
       //adjacency matrix defined as g
	
	col_v=(char*)malloc(n*sizeof(char));
	ver=(int*)malloc(n*sizeof(int));

	for(i=0;i<n;i++)
		ver[i]=1;

	graph_color(g,n);


	for(i=0;i<n;i++)
		printf("%c\n",col_v[i]);
	


}


