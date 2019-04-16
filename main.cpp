#include <cstdlib>
#include <iostream>
#include <vector>
#include <time.h>
#include <algorithm>


#define INF -1 // Não descoberto (desconexo).
#define NUL -2 // Orfão (raiz).
#define PRETO 0 // Descendentes já estão pretos ou não tem descendentes.
#define CINZA 1 // Descoberto.
#define BRANCO 2 // Não descoberto.

int *cor;
int *predescessor;
int *descoberta; // Tempo de descoberta
int *termino; // Tempo de término
int tempo; // "Relógio"

using namespace std;

vector<int> *g;

void DFS_visit(int vA)
{
     int vB;
     vector<int>::iterator it;
     cor[vA] = CINZA; 
     tempo++; 
     descoberta[vA] = tempo; 

     for(it = g[vA].begin(); it!=g[vA].end(); it++)
     { 

         vB = *it; 
         if(cor[vB] == BRANCO)
         { 
             predescessor[vB] = vA; 
             DFS_visit(vB);
         }
     }

     cor[vA] = PRETO; 
     termino[vA] = tempo; 
     tempo++; 
}


void DFS(int numeroDeVertices, int raiz)
{
    cor = new int[numeroDeVertices];
    predescessor = new int[numeroDeVertices];
    descoberta = new int[numeroDeVertices];
    termino = new int[numeroDeVertices];

    int vA;

    for(vA=0; vA < numeroDeVertices; vA++)
    { 

        cor[vA] = BRANCO;
        descoberta[vA] = INF;
        predescessor[vA] = NUL;
    }

    tempo = -1; 

    for(int i=raiz; i < numeroDeVertices; i++)
    {
		if(cor[i]==BRANCO)
    		DFS_visit(i);
	}
}

int main()
{
	int N,M,j,k,a;
	cin>>k;
	for(j=0;j<k;j++){
		cin>>a;
		cin>>N>>M;
   		g = new vector<int> [N+1];
   		
	    int x,y;

		for(int i=0;i<M;i++)
		{
			cin>>x>>y;
			g[x].push_back(y);
	  		g[y].push_back(x);
		}

		DFS(N+1,a); 
			cout<<termino[a]<<endl;
	}
	system("PAUSE");
    return 0;
}
