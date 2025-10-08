#include <iostream>
#include <cstdlib>

void* operator new(size_t size){
    void* p=malloc(size);
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
    char* number=new char;
    *number='a';
    std::cout<< *number<<std::endl;
    delete(number);
    
    return 0;
}