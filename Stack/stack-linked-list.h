template<typename T>
class Stack;

template<typename T>
class Node{
    public:
        
        T data;
        Node<T>* next; 

        Node(T data){
            this->data = data;
        }
};

template<typename T>
class Stack{

    Node<T>* head;

    public:

        Stack(){
            head = NULL;
        }

        void push(T data){
            Node<T>* node = new Node<T>(data);
            node->next = head;
            head = node;
        }

        void pop(){
            if(!empty()){
                Node<T>* temp = head;
                head = head->next;
                delete temp;
            }
        }
    
        T top(){
            return head->data;
        }

        bool empty(){
            return head == NULL;
        }
 
};
