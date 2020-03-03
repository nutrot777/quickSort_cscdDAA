#include <iostream> 
#include <sys/time.h>
#include <time.h>


using namespace std;


void fnGenRandInput(int [], int);
void fnDispArray(int [], int);
int fnPartition(int [], int, int);
void fnQuickSort(int[], int, int);
inline void fnSwap(int*, int*);
inline void fnSwap(int *, int *);

inline void fnSwap(int *a, int *b){
    int t=*a;
    *a = *b;
    *b = t;
}

int main(int argc, char **argv){
    FILE *fp;
    struct timeval tv;
    double dStart, dEnd;
    int Arr[500000], iNum, iPos, iKey,  iChoice;

    for(;;){
    cout<<"\n"<<"1.Plot the Graph"<<endl;
    cout<<"\n"<<"2.QuickSort"<<endl;
    cout<<"\n"<<"3.Exit"<<endl;
    cout<<"\n"<<"Enter your choice"<<endl;
    cin>>iChoice;
    switch(iChoice){
   
      case 1:
      fp = fopen("QuickPlot.dat", "w");
      for (int i =100; i<100000; i+=100){
          fnGenRandInput(Arr, i);
          gettimeofday(&tv, NULL);
          dStart=tv.tv_sec + (tv.tv_usec/1000000.0);
          fnQuickSort(Arr, 0, i-1);
          gettimeofday(&tv, NULL);
          dEnd = tv.tv_sec + (tv.tv_usec/1000000.0);

          fprintf(fp, "%d\t%lf\n", i, dEnd - dStart);
      }
         fclose(fp);

        cout<<"\n"<<"Data File generated and stored in file <QuickPlot.dat> "<<endl;
        cout<<"\n"<<"Use a plotting utility"<<endl;
        break;

       case 2:
       cout<<"\n"<<"Enter the number of elements to sort"<<endl;
       cin>>iNum;
       cout<<"\n"<<"Unsorted Array"<<endl;
       fnGenRandInput(Arr, iNum);
       fnDispArray(Arr, iNum);
       fnQuickSort(Arr, 0, iNum-1);
       cout<<"\n"<<"Sorted Array"<<endl;
       fnDispArray(Arr, iNum);
       break;

       case 3:
       exit(0);
       
       
    }


    }

    return 0;

}

// Functions Definitions 
//Partion Function
int fnPartition(int a[], int l, int r){
    int i, j, temp;
    int p;

    p = a[l];
    i = l;
    j = r + 1;

    do{
        do{
            i++;
        }while(a[i]<p);
        do{
            j--;
        }while(a[j]>p);

        fnSwap(&a[i], &a[j]);
    }while(i<j);

    fnSwap(&a[i], &a[j]);
    fnSwap(&a[l], &a[j]);

    return j;
}

//QuickSort Algorithm
void fnQuickSort(int a[], int l, int r){
    int s; 
    if(l<r){
        s = fnPartition(a, l, r);
        fnQuickSort(a, l, s-1);
        fnQuickSort(a, s+1, r);
    }
}

//GenRandInput
void fnGenRandInput(int X[], int n){
    int i; 
    srand(time(NULL));
    for (i = 0; i<n; i++){
        X[i] = rand()%10000;
    }
}

//DispArray
void fnDispArray(int X[], int n){
    int i; 
    for(i=0; i<n; i++){
        cout<<"\n"<<X[i]<<endl;
    }
}