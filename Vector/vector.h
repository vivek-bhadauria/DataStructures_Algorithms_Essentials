template <typename T>
class Vector{
    T* arr;
    int last;
    int capacity;
    
    void resize(const int newCapacity){
        /* Create an array with new capacity */
        T* temp = new T[newCapacity];

        /* Copy elements from current array */
        for(int i =0; i<size(); i++){
            temp[i] = arr[i];
        }

        /* remove the earlier array */
        delete [] arr;

        /* make the new array as current array */
        arr = temp;

        /* set the new capacity as the current capacity */
        capacity = newCapacity;
    }

  public:
    
    Vector(){
        arr = new T[1];
        capacity = 1;
        last = -1;
    }
    
    Vector(int cap){
        arr = new T[cap];
        capacity = cap;
        last = -1;
    }
    
    void push_back(const T n){
        if(size()==capacity){
            resize(capacity * 2);
        }
        arr[++last] = n;
    }

    T pop_back(){
        if(size()==0){
            return -1;
        }else if(size() == (capacity/2)){
            resize(capacity / 2);
        }
        T temp = arr[last--];
        return temp;
    }  

    T get(const int index) const{
        if((index < 0) || (index > (size()-1))){
            return -1;
        }
        return arr[index];
    }

    T front() const{
        if(size() == 0){
            return -1;
        }
        return arr[0];
    }

    T back() const{
        if(size() == 0){
            return -1;
        }
        return arr[last];
    }

    T size() const{
        return last+1;
    }

    T getCapacity() const{
        return capacity;
    }

    bool isEmpty() const{
        return last == -1;
    }

    T operator[](const int index) const{
        return arr[index];
    }
};