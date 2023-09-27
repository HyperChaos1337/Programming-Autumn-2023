import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        /*
        TwoLinkedList list = new TwoLinkedList();
        list.push_back("Один");
        list.push_back("Два");
        list.push_back("Три");
        list.print();
         */
        MyStack stack = new MyStack();
        stack.push("Один");
        stack.pop();
        stack.print();
        System.out.println(stack.peek());
    }
}
