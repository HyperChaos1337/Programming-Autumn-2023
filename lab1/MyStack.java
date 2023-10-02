/*
class Node<T>{

    public T field;
    public Node next;

    public Node(T field){
        this.next = null;
        this.field = field;
    }

}
*/
public class MyStack<T>{

    DynamicArray<T> array;

    public MyStack(){
        array = new DynamicArray<>();
    }

    void push(T data){
        array.push(data);
    }
    T pop(){
        T peek_value = null;
        if(!is_empty()){
            peek_value = array.get(size()-1);
            array.pop();
        }
        return peek_value;
    }
    T peek(){
        return is_empty() ? null : array.get(size()-1);
    }
    boolean is_empty(){
        return array.size() == 0;
    }
    int size(){
        return array.size();
    }
    int capacity(){
        return array.capacity();
    }
    void print(){
        array.print();
    }

    /*
    Node head, tail;

    void push(T field){
        Node ptr = new Node(field);
        if(head == null) head = ptr;
        if(tail != null) tail.next = ptr;
        tail = ptr;
    }

    void pop(){
        if(tail == null) return;
        if(head == tail){
            System.gc();
            head = tail = null;
            return;
        }
        Node node = head;
        for(;node.next != tail; node = node.next);
        node.next = null;
        System.gc();
        tail = node;
    }

    T peek(){
        if(tail == null){
            System.out.print("Стек пуст");
            return null;
        }
        return (T) tail.field;
    }

    void print(){
        for(Node node = head; node != null; node = node.next){
            System.out.print(node.field);
            System.out.print(" ");
        }
    }

    int size(){
        int k = 0;
        for(Node node = head; node != null; node = node.next) k++;
        return k;
    }
     */
}
