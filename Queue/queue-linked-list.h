template<typename T>
class Node{
    public:
        T data;
        Node* next;

        Node(T data){
            this->data = data;
        }
};

template<typename T>
class Queue{

    Node<T>* head;
    Node<T>* tail;
    int size;

    public:
        Queue(){
            head = NULL;
            tail = NULL;
            size = 0;
        }

        bool empty(){
            return head == NULL;
        }

        int Size(){
            return size;
        }

        T Front(){
            return head->data;
        }

        void push(T data){
            Node<T>* node = new Node(data);
            if(head == NULL){
                head = node;
            }else{
                tail->next = node;
            }
            tail = node;
            size++;
        }

        void pop(){
            Node<T>* temp = head;
            if(head == tail){
                head = NULL;
                tail = NULL;
            }else{
                head = head -> next;
            }
            delete temp;
            size--;
        }
};