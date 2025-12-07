//单链表
template<typename T>
struct LinkNode{
    T *data;
    LinkNode<T> *next;
    LinkNode():next(nullptr){}
    LinkNode(T d);data(d),next(nullptr){}
};

template<typename T>
class LinkList{
public:
    LinkNode<T> *head;
};


//计数法
template<typename T>
T Middle1(LinkList<T> &L){
    int j = 1;
    int n = L.Getlength();
    LinkNode<T> *p = L.head->next;

    while(j<=(n-1)/2){
        j++;
        p = p->next;
    }

    return p->data;
}


//快慢指针法
template<typename T>
T Middle2(LinkList<T> &L){
    
}