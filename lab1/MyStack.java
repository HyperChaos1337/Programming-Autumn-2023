class Node{
    public String field;
    public Node next;
    public Node(String field){
        this.next = null;
        this.field = field;
    }
}

public class MyStack {
    Node head, tail;
    void push(String field){
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
    String peek(){
        if(head == null){
            System.out.println("Стек пуст");
            return "";
        }
        return tail.field;
    }
    void print(){
        for(Node node = head; node != null; node = node.next) System.out.println(node.field);
    }
    int size(){
        int k = 0;
        for(Node node = head; node != null; node = node.next) k++;
        return k;
    }
}
