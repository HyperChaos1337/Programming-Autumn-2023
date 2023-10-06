public class Test {

    void init(){

        TwoLinkedList<Integer> list = new TwoLinkedList<>();
        DynamicArray<Float> array = new DynamicArray<>();
        MyStack<String> stack = new MyStack<>();
        ShuntingYard shuntingYard = new ShuntingYard();

        for(int i = 0; i < 5; i++)  list.push_back(10*i);
        System.out.println("1. List:"); list.print();
        list.push_front(-10);
        System.out.println("List after pushing front:"); list.print();
        list.pop_front();
        list.pop_back();
        System.out.println("List after removal head and tail:"); list.print();
        list.insert(1, 5);
        System.out.println("List after insertion:"); list.print();
        list.erase(2);
        System.out.println("List after removal:"); list.print();

        System.out.println();

        for(int i = 0; i < 5; i++) array.push(3.14f + i*10);
        System.out.println("2. Dynamic array:"); array.print();
        System.out.println("Length: " + array.size() + ", Capacity: " + array.capacity());
        array.pop();
        System.out.println("Array after removal peek element:"); array.print();
        System.out.println("Length: " + array.size() + ", Capacity: " + array.capacity());
        array.push(44.14f);
        array.push(54.14f);
        System.out.println("Array after insertion:"); array.print();
        System.out.println("Length: " + array.size() + ", Capacity: " + array.capacity());

        System.out.println();

        stack.push("Zero");
        stack.push("One");
        stack.push("Two");
        System.out.println("3. Stack:"); stack.print();
        stack.push("Three");
        System.out.println("Stack after pushing:"); stack.print();
        System.out.println("Peek element: " + stack.peek());
        stack.pop();
        System.out.println("Stack after removal:"); stack.print();

        System.out.println();

        System.out.println("4. Shunting yard algorithm (Reversed Polish Notation)");
        String first = "3 + 4 * 2 / ( 1 - 5 ) ^ 2", second = "sin ( 1 / 2 * 5 )";
        System.out.println("1st string: " + first + "\n" + "2nd string: " + second);
        System.out.println("1st string in RPN: " + shuntingYard.algorithm(first));
        System.out.println("2nd string in RPN: " + shuntingYard.algorithm(second));

    }

}
