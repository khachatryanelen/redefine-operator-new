#include <iostream>
#include <cstdlib>

void myMalloc(int size,void** ptr){
    *ptr=malloc(size);
    std::cout<<"Hahahah you are using my malloc :) "<<std::endl;
}
void* operator new(size_t size){
    void * ptr;
    myMalloc(size,&ptr);
    std::cout<<"Allocated "<< size <<" byte(s)"<<std::endl;
    if(ptr==nullptr) {
        std::cout<<"Not enough place"<<std::endl;
    }
    return ptr;
}
void operator delete(void* ptr){
    if(ptr==nullptr){
        std::cout <<"The pointer is null "<< std::endl;
    }
    free( ptr);
    std::cout <<"Deleted"<< std::endl;
}
int main(int argc,const char* argv[]){
    char* number=new char;
    *number='a';
    std::cout<< *number<<std::endl;
    delete number;
    
    return 0;
}