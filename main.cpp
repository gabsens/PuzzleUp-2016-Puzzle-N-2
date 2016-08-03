#include <iostream>
#include <cstdlib>

int k = 18;
int trials = 100000;
int numbers[100];


void reset(){
    for (int i=0; i<100; i++){
        numbers[i] = i+1;
    }
}



int * draw(int * arr){
    for (int i=0; i<k; i++){
        int r = rand() % (100-i);
        int temp = arr[100-1-i];
        arr[100-1-i] = arr[r];
        arr[r] = temp;
    }
    return (arr + 100 -k);
}



int compare (const void * a, const void * b)
{
    return ( *(int*)a - *(int*)b );
}



bool isconsec(int * arr){
    qsort (arr, k, sizeof(int), compare);
    for (int i=0; i<k-1; i++){
        if ((arr[i]-arr[i+1]==1) || (arr[i]-arr[i+1]==-1)){
            return true;
        }
    }
    return false;
}



void simulation(){
    int acc=0;
    for (int i=0; i<trials; i++){
        reset();
        int * drawed = draw(numbers);
        if (isconsec(drawed)){
            acc++;
        }
    }
    float prob = (float(acc)/float(trials));
    printf("probability : %f\n", prob);
}

int main(int argc, const char * argv[]) {

    simulation();
    
    return 0;
}
