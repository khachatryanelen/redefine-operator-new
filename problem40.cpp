#include <iostream>
#include <cstdlib>
#include <string>

void* myMalloc(int size,std::string& str){
    void* p=malloc(size);
    std::cout<<str<<std::endl;
    return p;
}
void* operator new(size_t size,std::string& str){
    void* p=myMalloc(size,str);
    std::cout<<"Allocated "<< size <<" byte(s)"<<std::endl;
    if(p==nullptr) {
        std::cout<<"Not enough place"<<std::endl;
    }
    return p;
}
void operator delete(void* ptr){
    if(ptr==nullptr){
        std::cout <<"The pointer is null "<< std::endl;
    }
    free( ptr);
    std::cout <<"Deleted"<< std::endl;
}
int main(int argc,const char* argv[]){
    std::string str="Hahaha you are using my malloc:) ";
    char* number=new(str) char;
    *number='a';
    std::cout<< *number<<std::endl;
    delete number;
    
    return 0;
}
