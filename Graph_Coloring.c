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
    do{
        x[k] = (x[k]+1)%(m+1); //Highest color that can be used
        if(x[k]==0)return;
        for(i=1;i<=n;i++)
            if(G[i][k]!=0 && x[k]==x[i]) // G[i][k] : means nodes exist between i and k , x[k] == x[i] : means checking ajdacent nodes i and k have same color
                break;
        if(i==n+1)
            return;
    }while(1);
}

void mcoloring(int k){
    for(int i=1;i<=n;i++){
        nextColor(k);
        if(x[k]==0) // if Color can not be filled at kth location
            return;
        if(k==n) // if all nodes are coloured then print
            write();
        else
            mcoloring(k+1); // proceed to nexr node
    }
}

int main(){

    mcoloring(1);
    return 0;
}
