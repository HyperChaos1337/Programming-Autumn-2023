public class DynamicArray<T> {

    private Object[] arr;

    private int memory;
    private int len;

    public DynamicArray() {

        arr = new Object[5];
        memory = 5;
        len = 0;

    }

    void push(T data) {

        if (len == memory) {

            final int MEM_STEP = 5;
            Object[] temp = new Object[MEM_STEP + memory];
            if (memory >= 0) System.arraycopy(arr, 0, temp, 0, memory);
            memory += MEM_STEP;
            arr = temp;

        }

        arr[len] = data;
        len++;
    }

    T get(int index) {

        if (index < len)
            return (T) arr[index];

        return null;

    }

    void pop() {
        len--;
    }

    int size() {
        return len;
    }

    int capacity() {
        return memory;
    }

    void print() {
        for (int i = 0; i < len; i++) System.out.print(arr[i] + " ");
        System.out.println();
    }

}