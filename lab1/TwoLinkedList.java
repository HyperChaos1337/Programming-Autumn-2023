class ListNode {
    public String field;
    public ListNode next, prev;
    public ListNode(String field){
        this.field = field;
        this.next = this.prev = null;
    }
}

public class TwoLinkedList{
    ListNode head, tail;
    ListNode push_back(String data){
        ListNode ptr = new ListNode(data);
        ptr.prev = tail;
        if(tail != null) tail.next = ptr;
        if(head == null) head = ptr;
        tail = ptr;
        return ptr;
    }
    ListNode push_front(String data){
        ListNode ptr = new ListNode(data);
        ptr.next = head;
        if(head != null) head.prev = ptr;
        if(tail == null) tail = ptr;
        head = ptr;
        return ptr;
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
    String get_element(int index){
        int k = 0;
        ListNode node = head;
        while (node != null){
            k++;
            node = node.next;
            if(index == k) return node.field;
            else{
                System.out.println("Index is out of bounds");
                return "";
            }
        }
        return "";
    }

    ListNode insert(int index, String data){
        ListNode right = get_at(index);
        if(index < 0 || index > length()){
            System.out.println("Индекс находится за границами списка. Вставка невозможна");
            return null;
        }
        if(right == null) return push_back(data);
        ListNode left = right.prev;
        if(left == null) return push_front(data);
        ListNode ptr = new ListNode(data);
        ptr.next = right;
        ptr.prev = left;
        right.prev = ptr;
        left.next = ptr;
        return ptr;
    }

    int length(){
        int k = 0;
        for(ListNode node = head; node != null; node = node.next){
             k++;
        }
        return k;
    }
    void print(){
        System.out.println("Список:");
        for(ListNode node = head; node != null; node = node.next){
            System.out.println(node.field);
        }
    }

}