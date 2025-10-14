#include <iostream>
#include <cstdlib>
#include <ctime>

void myMalloc(int size,void** ptr){
    *ptr=malloc(size);
    std::cout<<"Hahahah you are using my malloc :) "<<std::endl;
}
void* operator new[](size_t size){
    void* ptr;
    myMalloc(size,&ptr);
    std::cout<<"Allocated "<< size <<" byte(s)"<<std::endl;
    if(ptr==nullptr) {
        std::cout<<"Not enough place"<<std::endl;
    }
    return ptr;
}
void operator delete[](void* ptr){
    if(ptr==nullptr){
        std::cout <<"The pointer is null "<< std::endl;
    }
    free( ptr);
    std::cout <<"Deleted"<< std::endl;
}
void initArray(int* arr,int size){
    for(int i=0;i<size;i++){
        arr[i]=rand()%1000;
    }
}
void printArray(int* arr,int size){
    for(int i=0;i<size;i++){
        std::cout<< arr[i] << "; ";
    }
    std::cout << std::endl;
}
int main(int argc,const char* argv[]){
    srand(time(0));
    int size=8;
    int* arr=new int[size];
    initArray(arr,size);
    printArray(arr,size);
    delete[] arr;
    
    return 0;
}
