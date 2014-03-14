#include <iostream>
//Ruben Martinez A01195867
//Angel Gonzalez A01137638
using namespace std;
int b[50];
void Une(int a[],int p, int q, int r)
{
	int i = p;
	int j = q+1;
	int k = 1;
	while(i<=q&&j<=r){
        if(a[i]<a[j]){
            b[k++]=a[i++];
        }else{
            b[k++]=a[j++];
        }
        while(i<=q){
            b[k++]=a[i++];
        }
        while(j<=r){
            b[k++]=a[j++];
        }
        for(i=r;i>=p;i--){
            a[i]=b[--k];
        }
	}
}


void MergeSort(int arreglo[],int inicio, int fin){
    int mitad;
    if (inicio < fin) {
        mitad = (inicio+fin) /2;
        MergeSort(arreglo,inicio, mitad);
        MergeSort(arreglo,mitad+1, fin);
        Une(arreglo,inicio, mitad, fin);
    }
}


int main()
{
    int ciclo,dias,cMayor;
    cin>>ciclo;
    while(ciclo>0){

        cin>>dias;
        int arreglo[dias],aux[dias];
        for(int i=1;i<=dias;i++)
        {
            cin>>arreglo[i];
            aux[i]=arreglo[i];
        }
        MergeSort(aux,1,dias);
        int menor=aux[1];
        int mayor=aux[dias];
        int cMenor;
        for(int i=1;i<=dias;i++)
        {
            if(menor==arreglo[i])
            {
                cMenor=i;
                i+=dias;
            }
        }
        bool encontro=false;
        int auxMenor=cMenor;
        while(!encontro && auxMenor<=dias)
        {
            if(mayor==arreglo[auxMenor])
            {
                encontro=true;
                cMayor=auxMenor;
            }
            if(auxMenor == dias && !encontro)
            {
                mayor=aux[dias-1];
                auxMenor=cMenor;
            }
            auxMenor++;

        }
        cout<<"Buy in " << cMenor <<", sell in " << cMayor<<endl;
        ciclo--;
    }
    return 0;
}
