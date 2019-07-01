#include <iostream>

using namespace std;

void llenarMatriz(int mat[][3],int f,int c);
void mostrarMatriz(int mat[][3],int f,int c);
void transponerMatriz(int mat[][3],int f,int c);
int  determinante(int mat[][3],int n);
int det(int mat[][2],int n);
void invertirMatriz(int mat[][3],int f,int c);

void mostrarMatriz2x2(int mat[][2]);

int main()
{
	int mat[3][3],f=3,c=3;
	int matP[3][3]={1,2,3,4,5,6,7,8,9};
	int det;
	
	det = determinante(matP,f);
	mostrarMatriz(matP,f,c);
	
	cout<<"\nDeterminante: "<<det<<endl;
	
	system("pause");
	return 0;
}

void llenarMatriz(int mat[][3],int f,int c)
{
	cout<<"Llenando matriz: \n"<<endl;
	
	for(int i=0;i<f;i++)
	{
		for(int j=0;j<c;j++)
		{
			cout<<"Fila "<<i+1<<" Columna "<<j+1<<" :";cin>>mat[i][j];
		}
	}
}

void mostrarMatriz(int mat[][3],int f,int c)
{
	cout<<"\nMostrando matriz: \n"<<endl;
	
	for(int i=0;i<f;i++)
	{
		for(int j=0;j<c;j++)
		{
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}	
}

void mostrarMatriz2x2(int mat[][2])
{
	cout<<"\nMostrando matriz: 2x2\n"<<endl;
	
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}	
}
void transponerMatriz(int mat[][3],int f,int c)
{
	int aux;
	for(int i=0;i<f;i++)
	{
		for(int j=0;j<c;j++)
		{
			if(i>j)
			{			
				aux=mat[i][j];
				mat[i][j]=mat[j][i];
				mat[j][i]=aux;
			}
		}
	}
}

int det(int mat[][2])
{
	int determinante;
		
	determinante = ((mat[0][0]*mat[1][1])-(mat[1][0]*mat[0][1]));
	
	return determinante;	
}

int  determinante(int matriz[][3],int n)
{
	int mat[2][2];
	int determinante=0;
	int cof,f=0,c=0,fil,col;
	
	
	for(int k=0;k<n;k++) //3 determinantes 2x2
	{
		c=k;
		
		fil=0,col=0;
		
		for(int i=0;i<n;i++) //recorre las filas
		{
			for(int j=0;j<n;j++) //recorre las columnas
			{
				if(i!=0 && j!=c)
				{
					mat[fil][col] = matriz[i][j];
					
					if(col<1)
						col++;
					else
					{
						col=0;
						fil++;
					}
				}	
			}
		}	
		cof = det(mat);
		
		if(k%2 != 0)
			cof*=-1;
			
		determinante += cof;
	}
	
	return determinante;
}

void invertirMatriz(int mat[][3],int f,int c)
{
	
}

