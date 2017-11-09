#include <iostream>
#include <fstream>
using namespace std;

void bf(int vf,int viz[],int n,int a[50][50])
{
    int c[50],p,u,k;
    p=u=1;
    c[p]=vf;
    viz[vf]=1;
    while(p<=u)
    {
        for(k=1;k<=n;k++)
            if(a[c[p]][k]==1 && viz[k]==0)
            {
                c[++u]=k;
                viz[k]=1;
            }
            p++;
    }
    for(k=1;k<=u;k++)
        cout<<c[k]<<" ";
	cout<<endl;
}

void citire(int &n,int a[50][50])
{
    int i,j;
    ifstream f("in.txt");
    f>>n;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            f>>a[i][j];
}

int main()
{
    int n,a[50][50],viz[50],i,nr=0,v[50];
    citire(n,a);
    for(i=1;i<=n;i++)
        viz[i]=0;
	//comp conexe
	do
	{
		for(i=1;i<=n && viz[i]==1;i++);
		if(i<=n)
		{
			nr++;
			v[nr]=i;
			bf(i,viz,n,a);
		}
	}while(i<=n);
	//
	if(nr==1)
		cout<<"Graf conex.";
	else
	{
		cout<<"Graful nu e conex, are "<<nr<<" componente conexe.";
		cout<<endl;
		cout<<"Nr minim de muchii care trebuie adaugate este: "<<nr-1<<endl;
		for(i=1;i<nr;i++)
			cout<<"["<<v[i]<<","<<v[i+1]<<"],";
		cout<<"\b ";
	}
    return 0;
}
