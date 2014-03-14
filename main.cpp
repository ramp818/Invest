#include <iostream>
//Ruben Martinez A01195867
//Angel Gonzalez A01137638
using namespace std;

void merge(int*,int*,int,int,int);
void MergeSort(int *a, int*b, int low, int high)
{
    int pivot;
    if(low<high)
    {
        pivot=(low+high)/2;
        MergeSort(a,b,low,pivot);
        MergeSort(a,b,pivot+1,high);
        merge(a,b,low,pivot,high);
    }
}
void merge(int *a, int *b, int low, int pivot, int high)
{
    int h,i,j,k;
    h=low;
    i=low;
    j=pivot+1;

    while((h<=pivot)&&(j<=high))
    {
        if(a[h]<=a[j])
        {
            b[i]=a[h];
            h++;
        }
        else
        {
            b[i]=a[j];
            j++;
        }
        i++;
    }
    if(h>pivot)
    {
        for(k=j; k<=high; k++)
        {
            b[i]=a[k];
            i++;
        }
    }
    else
    {
        for(k=h; k<=pivot; k++)
        {
            b[i]=a[k];
            i++;
        }
    }
    for(k=low; k<=high; k++) a[k]=b[k];
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
        int b[dias];
        MergeSort(aux,b,1,dias);
        for(int i=1;i<=dias;i++)
        {
            cout<<aux[i];
        }
        cout<<endl;
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
