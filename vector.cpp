#include<iostream>

template <typename T>
class Myvector
{
    private:
    T* data;
    size_t capacity;
    size_t current_size;
    public:
    //basic constructor to build an empty vector
        Myvector(){ 
            current_size=0;
            capacity=1;
            data=new T[capacity];
        }
    //constructor to build a vector with n elements(elements are default initialised with 0)
        Myvector(size_t n){
            current_size=n; 
            capacity=n;
            data=new T[capacity];
        }
    //constructor to build a vector with n elements(elements are default initialised with 0)
        Myvector(size_t n,const T& value){
            current_size=n;
            capacity=n;
            data =new T[capacity];

            for(size_t i=0;i<n;i++){
                data[i]=value;
            }
        }
    //copy constructor to deep copy another vector
        Myvector(const Myvector& other){
            current_size=other.current_size;
            capacity=other.capacity;
            data =new T[capacity];
            for(size_t i=0;i<current_size;i++){
                data[i]=other.data[i];
            }
        }
    //move constructor to steal memory pointer
        Myvector(Myvector&& other){
            current_size=other.current_size;
            capacity=other.capacity;
            data=other.data;

            other.data=nullptr;
            other.capacity=0;
            other.current_size=0;
        }
    //initializer list constructor(initializer list needs to be traversed by iterators)
        Myvector(std::initializer_list<T> list){
            current_size=list.size();
            capacity=current_size;
            data=new T[capacity];

            size_t i=0;
            for(auto val:list){
                data[i++]=val;
            }
        }
    //destructor
        ~Myvector(){
            delete[] data;
        }
    //equal operator overloading
        Myvector& operator=(const Myvector& other){
            if(this==&other){
                return *this;
            }
            delete[] data;
            this->current_size=other.current_size;
            this->capacity=other.capacity;
            data=new T[capacity];
            for(size_t i=0;i<current_size;i++){
                this->data[i]=other.data[i];
            }
            return *this;
        }
    //pushback function (doubling strategy used here)
        void push_back(const T& value){
            if(current_size==capacity){
                capacity=(capacity==0)?1:capacity*2;
                T* newdata=new T[capacity];
                for(size_t i=0;i<current_size;i++){
                    newdata[i]=data[i];
                }
                delete[] data;
                data=newdata;
            }
            data[current_size++]=value;
            
        }
    //popback function ()
        void pop_back(){
            if(current_size>0){
                current_size--;
            }            
        }
    //access operator
        T& operator[](size_t index){
            return data[index];
        }
    //utility function
        size_t get_currentsize(){
            return current_size;
        }
        size_t get_capacity(){
            return capacity;
        }
        bool is_empty(){
            return current_size==0;
        }   
    //display function
        void show(){
            std::cout<<this->current_size<<","<<this->capacity<<std::endl;
            for(size_t i=0;i<current_size;i++){
                std::cout<<" "<<this->data[i];
            }
            std::cout<<std::endl;
        }

};

int main(){
    Myvector<int> new_vect_1;
    new_vect_1.show();
    Myvector<int> new_vect_2(5,10);
    new_vect_2.show();
    Myvector<int> new_vect_3(new_vect_2);
    new_vect_3.show();
    Myvector<int> new_vect_4(std::move(new_vect_3));
    new_vect_4.show();
    Myvector<int> new_vect_5={1,2,3,4,5};
    new_vect_5.show();



    return 0;
}