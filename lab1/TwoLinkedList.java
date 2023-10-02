class ListNode<T>{

    public T field;
    public ListNode next, prev;

    public ListNode(T field){
        this.field = field;
        this.next = this.prev = null;
    }

}

public class TwoLinkedList<T>{

    ListNode head, tail;

    ListNode push_back(T data){
        ListNode ptr = new ListNode(data);
        ptr.prev = tail;
        if(tail != null) tail.next = ptr;
        if(head == null) head = ptr;
        tail = ptr;
        return ptr;
    }
    ListNode push_front(T data){
        ListNode ptr = new ListNode(data);
        ptr.next = head;
        if(head != null) head.prev = ptr;
        if(tail == null) tail = ptr;
        head = ptr;
        return ptr;
    }

    void pop_back(){
        if(tail == null) return;
        ListNode ptr = tail.prev;
        if(ptr != null) ptr.next = null;
        else head = null;
        System.gc();
        tail = ptr;
    }
    void pop_front(){
        if(head == null) return;
        ListNode ptr = head.next;
        if(ptr != null) ptr.prev = null;
        else tail = null;
        System.gc();
        head = ptr;
    }

    ListNode get_at(int index){
        int k = 0;
        ListNode node = head;
        while(k != index){
            if(node == null) return node;
            node = node.next;
            k++;
        }
        return node;
    }
    T get_element(int index){
        int k = 0;
        ListNode node = head;
        while (node != null){
            k++;
            node = node.next;
            if(index == k) return (T) node.field;
            else{
                System.out.println("Index is out of bounds");
                return null;
            }
        }
        return null;
    }

    ListNode insert(int index, T data){
        ListNode right = get_at(index);
        if(index < 0 || index > length()){
            System.out.println("Индекс находится за границами списка. Вставка невозможна");
            return null;
        }
        if(right == null) return push_back((T) data);
        ListNode left = right.prev;
        if(left == null) return push_front((T) data);
        ListNode ptr = new ListNode(data);
        ptr.next = right;
        ptr.prev = left;
        right.prev = ptr;
        left.next = ptr;
        return ptr;
    }

    void erase(int index){
        ListNode ptr = get_at(index);
        if(ptr == null){
            System.out.println("Элемент с данным индексом отсутствует. Удаление невозможно");
            return;
        }
        if(ptr.next == null){
            pop_back();
            return;
        }
        if(ptr.prev == null){
            pop_front();
            return;
        }
        ListNode right = ptr.next;
        ListNode left = ptr.prev;
        right.prev = left;
        left.next = right;
    }

    int length(){
        int k = 0;
        for(ListNode node = head; node != null; node = node.next){
             k++;
        }
        return k;
    }

    void print(){
        for(ListNode node = head; node != null; node = node.next){
            System.out.print(node.field);
            System.out.print(" <-> ");
        }
    }

}