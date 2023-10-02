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
    
}
