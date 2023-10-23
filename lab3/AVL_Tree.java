class AVL_Node<T>{

    T data;
    short height;
    AVL_Node<T> left;
    AVL_Node<T> right;

    public AVL_Node(T data) {
        this.data = data;
    }

    public void fixHeight() {
        short hl = height(left);
        short hr = height(right);
        height = (short) (Math.max(hl, hr) + 1);
    }

    public static int balance(AVL_Node node) {
        return height(node.right) - height(node.left);
    }

    public static short height(AVL_Node node) {
        return node != null ? node.height : 0;
    }

    public T get_data() {
        return data;
    }

    public short get_height() {
        return height;
    }

    public AVL_Node<T> get_left() {
        return left;
    }

    public AVL_Node<T> get_right() {
        return right;
    }
}

public class AVL_Tree<T extends Comparable<T>> {

    private AVL_Node<T> root;

    private AVL_Node<T> rotateRight(AVL_Node<T> node) {
        AVL_Node<T> left = node.left;
        node.left = left.right;
        left.right = node;
        node.fixHeight();
        left.fixHeight();
        return left;
    }

    private AVL_Node<T> rotateLeft(AVL_Node<T> node) {
        AVL_Node<T> right = node.right;
        node.right = right.left;
        right.left = node;
        node.fixHeight();
        right.fixHeight();
        return right;
    }

    private AVL_Node<T> balance(AVL_Node<T> node) {
        node.fixHeight();
        int nodeBalanceFactor = AVL_Node.balance(node);
        if (nodeBalanceFactor == 2) {
            if (AVL_Node.balance(node.right) < 0)
                node.right = rotateRight(node.right);
            return rotateLeft(node);
        } else if (nodeBalanceFactor == -2) {
            if (AVL_Node.balance(node.left) > 0)
                node.right = rotateLeft(node.left);
            return rotateRight(node);
        } else
            return node;
    }

    public AVL_Node<T> get_root() {
        return root;
    }

    private AVL_Node<T> get_min(AVL_Node<T> node) {
        return node.left != null ? get_min(node.left) : node;
    }

    private AVL_Node<T> remove_min(AVL_Node<T> node) {
        if (node.left == null)
            return node.right;
        node.left = remove_min(node.left);
        return balance(node);
    }

    private AVL_Node<T> find_node(AVL_Node<T> root, T key) {
        if (root == null || root.data.equals(key))
            return root;
        else
            return find_node(
                    key.compareTo(root.data) < 0 ? root.left : root.right,
                    key
            );
    }

    public AVL_Node<T> find(T key) {
        return find_node(root, key);
    }

    private AVL_Node<T> remove_element(AVL_Node<T> root, T key) {
        if (root == null) return null;
        int compare = key.compareTo(root.data);
        if (compare < 0)
            root.left = remove_element(root.left, key);
        else if (compare > 0)
            root.right = remove_element(root.right, key);
        else {
            AVL_Node<T> left = root.left;
            AVL_Node<T> right = root.right;
            root.right = root.left = null;

            if (right == null)
                return left;

            AVL_Node<T> minimal = get_min(right);
            minimal.right = remove_min(right);
            minimal.left = left;

            return balance(minimal);
        }

        return balance(root);
    }

    public void remove(T key) {
        remove_element(get_root(), key);
    }

    private AVL_Node<T> insert_element(T data, AVL_Node<T> root) {
        if (root == null)
            return new AVL_Node<>(data);
        else if (data.compareTo(root.data) < 0){
            root.left = insert_element(data, root.left);
            balance(root.left);
        }

        else{
            root.right = insert_element(data, root.right);
            balance(root.right);
        }

        return balance(root);
    }

    public void insert(T data) {
        root = insert_element(data, root);
    }


    public DynamicArray<T> prefixSearch(AVL_Node<T> node, DynamicArray<T> array) {
        if (node == null)
            return null;

        MyStack<AVL_Node<T>> stack = new MyStack<>();
        stack.push(node);
        while (!stack.is_empty()) {
            AVL_Node<T> n = stack.pop();
            array.push(n.data);
            if (n.right != null) stack.push(n.right);
            if (n.left != null) stack.push(n.left);
        }

        return array;
    }
    public DynamicArray<T> prefixTraverse() {
        return prefixSearch(root, new DynamicArray<>());
    }

    public DynamicArray<T> infixSearch(AVL_Node<T> node, DynamicArray<T> array) {
        if (node == null)
            return null;

        MyStack<AVL_Node<T>> stack = new MyStack<>();
        stack.push(node);
        while (!stack.is_empty()) {
            AVL_Node<T> n = stack.pop();
            if(n.right != null) stack.push(n.right);
            array.push(n.data);
            if(n.left != null) stack.push(n.left);
        }

        return array;
    }
    public DynamicArray<T> infixTraverse() {
        return infixSearch(root, new DynamicArray<>());
    }

    public DynamicArray<T> postfixSearch(AVL_Node<T> node, DynamicArray<T> array) {
        if (node == null)
            return null;

        MyStack<AVL_Node<T>> stack = new MyStack<>();
        stack.push(node);
        while (!stack.is_empty()) {
            AVL_Node<T> n = stack.pop();
            if (n.right != null) stack.push(n.right);
            if (n.left != null) stack.push(n.left);
            array.push(n.data);
        }

        return array;
    }

    public DynamicArray<T> postfixTraverse() {
        return postfixSearch(root, new DynamicArray<>());
    }

    public DynamicArray<T> bfs(AVL_Node<T> node) {
        DynamicArray<T> values = new DynamicArray<>();
        MyStack<AVL_Node<T>> queue = new MyStack<>();
        queue.push(node);

        while (queue.size() > 0) {
            AVL_Node<T> queuedNode = queue.pop();
            values.push(queuedNode.get_data());

            if (queuedNode.get_left() != null) queue.push(queuedNode.get_left());
            if (queuedNode.get_right() != null) queue.push(queuedNode.get_right());
        }

        return values;
    }

}
