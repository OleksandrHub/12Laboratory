#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    FILE *f=fopen("input.txt","r"), *g=fopen("output.txt","w");
    if(f==NULL){
        printf("Error opening file\n");
        return 1;
    }
    char name[15][50], weight[15][50], price[15][50];
    for (int i=0;i<15;i++){
        fscanf(f,"%s %s %s",name[i],weight[i],price[i]);
    }
    for (int i=0;i<15;i++){
       for(int j=0; j<15-i-1; j++){
            if(stof(price[j])<stof(price[j+1])){
                swap(price[j],price[j+1]);
                swap(name[j],name[j+1]);
                swap(weight[j],weight[j+1]);
            }
       }
    }
    for (int i=0;i<15;i++){
        printf("%s %s %s\n",name[i],weight[i],price[i]);
        fprintf(g,"%s %s %s\n",name[i],weight[i],price[i]);
    }
    fclose(f);
    fclose(g);
    return 0;
}