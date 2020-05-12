#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 2500

#define VISITED 3
struct node{
    int data;
    struct node *next;
};
struct node* first = NULL;
struct node* last = NULL;
struct node* createNode(int x)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}
void enQueue(int x)
{
    struct node* newyNode = createNode(x);
    if(first == NULL)
    {
        first = newyNode;
        last = newyNode;
    }
    else
    {
        last->next = newyNode;
        last = newyNode;
    }
}
void deQueue()
{
    if(first == NULL)
    {
        printf("\n Queue is  empty ");
        return;
    }
 
    if(first->next == NULL)
    {
        first = NULL;
        last = NULL;
    }
    else
    {
        struct node* secondNode = first->next;
        free(first);
        first = secondNode;
    }
 
}
bool isEmpty()
{
    if(first == NULL)
        return true;
    else
        return false;
}
int next()
{
    return first->data;
}
int adj[2500][2500];
int visited[2500];
char * koor_word(int koor);
char * koor_word(int koor){//koordinati verilen kelimeyi dondurur
	FILE *fil; 
	int i=1,tmp1;
	static char x[5];
	fil = fopen("kelime.txt", "r");
	
while(fgets(x,7,fil)&& i<koor){
		i++;
	}
	
	return x;
	fclose(fil);
}

int koordinat(char kelime[5], int adj[2500][2500]);
int koordinat(char kelime[5], int adj[2500][2500]){ //bir kelimenin matristeki koordinatini dondurur
	FILE *file; 
	int i,u,p=0,tmp1;
	char x[5];
	file = fopen("kelime.txt", "r");
	
while(fgets(x,7,file)){
		u=0; p++; 
		for(i=0;i<6;i++){
			if(kelime[i]!=x[i]){
				u++;
			}
		}
		if(u==1){
			
			tmp1=p;
		}
	}
	fclose(file);
	return tmp1;
}

void bagvar(int adj[2500][2500], char ilk[5], char son[5]);
void bagvar(int adj[2500][2500], char ilk[5], char son[5]){
	int x,y;
	x=koordinat(ilk,adj);
	y=koordinat(son,adj);
	if(adj[x][y]==1){
		printf("baglanti var\n");
	} else {
		printf("baglanti yok\n");
	}
}
int main(){
	FILE *fp,*fp2;
	int i,j,k,z,l,n=0,fark,koor,x,y;
    char  word[5],word1[5],ilk[5],son[5];
    char * ch;
	printf("ilk kelime gir:"); gets(ilk);
	printf("son kelime gir:"); gets(son);
	fp = fopen("kelime.txt", "r");
	while(fgets(word, 7, fp)){
	    n++;	
    }
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			adj[i][j]=0;
		}
	}  
	for(i=0;i<n;i++){
		visited[i]=0;
	}
	fclose(fp);
	fp = fopen("kelime.txt", "r");   fp2 = fopen("kelime.txt", "r");
	l=1; k=1;
	while(fgets(word, 7, fp)){ //adj matrix olusturma basladý
		while(fgets(word1, 7, fp2)){
			fark=0;
				for(i=0;i<6;i++){
					if(word[i]!=word1[i]){
						fark++; 
					} 		
		   		}
		   	if(fark==1){
		   		adj[k][l+k]=1;
		   		adj[l+k][k]=1;
			   }	
		l++;
	} l=1;
	fclose(fp2);
	k++;
	fp2 = fopen("kelime.txt", "r");
	for(z=0;z<k;z++){
		fgets(word1, 7, fp2);
	}
}//adj matrix olusturuldu
    bagvar(adj,ilk,son);
    x=koordinat(ilk,adj);
    y=koordinat(son,adj);
    visited[x] = 1;
    enQueue(x);
    while(isEmpty() == false && visited[y]==0)
    {
        x= next();
        deQueue();
        ch=koor_word(x);
		for(i=0;i<6;i++){
        	printf("%c", *(ch+i));
		}
        for( i = 0; i < n; i++)
        {
        	
            if(visited[i] == 0 && adj[x][i] == 1)
            {
                visited[i] = 1;
                enQueue(i);
            }
        }
        
    }
    ch=koor_word(y);
    for(i=0;i<6;i++){
        	printf("%c", *(ch+i));
		}
	fclose(fp);
	fclose(fp2);
    return 0;

}
 

