class QueueNode<T>{

    public T data;
    public QueueNode<T> next;
    public QueueNode(T data){
        this.data = data;
        this.next = null;
    }

}

public class MyQueue<T>{
    QueueNode<T> head;
    QueueNode<T> tail;

    void add(T data){
        QueueNode<T> node = new QueueNode<>(data);
        if(is_empty()){
            head = node;
        }
        else{
            tail.next = node;
        }
        tail = node;
    }

    T poll(){
        if(is_empty()) return null;
        T data = head.data;
        head = head.next;
        if(head == null) tail = null;
        return data;
    }

    T peek(){
        if(is_empty()) return null;
        return head.data;
    }

    int size(){
        int k = 0;
        for(QueueNode<T> node = head; node != null; node = node.next) k++;
        return k;
    }

    boolean is_empty(){
        return head == null;
    }
    void print(){
        for(QueueNode<T> node = head; node != null; node = node.next) System.out.print(node.data + " ");
        System.out.println();
    }
}
