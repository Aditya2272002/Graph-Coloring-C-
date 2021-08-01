#include<stdio.h>
#include<conio.h>

int x[10]={0},n=4,m=2;
 int G[10][10]={
        { 0, 0, 0, 0, 0},
        { 0, 0, 1, 0, 1 },
		{ 0, 1, 0, 1, 0 },
		{ 0, 0, 1, 0, 1 },
		{ 0, 1, 0, 1, 0 },
    };
void write(){
    int i;
    printf("\n");

    for(i=1;i<=n;i++){
        printf("%d vertex -> %d",i,x[i]);
        printf("\n");
    }
    printf("\n");
}

void nextColor(int k){
    int i=1;
   //x[] is array having values from 0-m in index 1-n
   // i.e which node will be coloured by which color 
   // x = [ 0th position not filled, 1,0,2]  filling occur from 1st index : node 1 have color 1, node 2 have no color, node 3 have color 2.  
	
   // return; means exit suddenly from this function returning void.	
    do{
        x[k] = (x[k]+1)%(m+1); //Highest color that can be used
        if(x[k]==0)return; // All colours used then return to function.
        for(i=1;i<=n;i++)  // Iterating from node 1 to n 
            if(G[i][k]!=0 && x[k]==x[i]) // G[i][k] : means nodes exist between i and k , x[k] == x[i] : means checking ajdacent nodes i and k have same color
                break;
        if(i==n+1) // if no two adjacent nodes have same color and path exist between them then loop variable will reach to n+1 :- new color found 
            return;
    }while(1);
}

void mcoloring(int k){
    for(int i=1;i<=n;i++){
        nextColor(k);
        if(x[k]==0) // if Color can not be filled at kth location.
            return;
        if(k==n) // if all nodes are coloured then print.
            write();
        else
            mcoloring(k+1); // proceed to next node.
    }
}

int main(){

    mcoloring(1);
    return 0;
}
