import static java.lang.Integer.parseInt;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;

class Node <T>{

    private T data;
    private Node<T> leftChild, rightChild, parent;

    public Node(T data){
        this.data = data;
    }

    public void set_data(T data){
        this.data = data;
    }
    public T get_data(){
        return (T) data;
    }

    public void set_leftChild(Node<T> leftChild){
        this.leftChild = leftChild;
    }
    public Node<T> get_leftChild(){
        return leftChild;
    }

    public void set_rightChild(Node<T> rightChild){
        this.rightChild = rightChild;
    }
    public Node<T> get_rightChild() {
        return rightChild;
    }

    public void set_parent(Node<T> parent){
        this.parent = parent;
    }
    public Node<T> get_parent(){
        return parent;
    }

}

public class BinaryTree<T extends Comparable<T>>{

    private Node<T> root;

    public void set_root(Node<T> root){
        this.root = root;
    }
    public Node<T> get_root(){
        return root;
    }

    public void insert(T data){
        Node<T> node = new Node<>(data);
        if(root == null) set_root(node);
        else{
            Node<T> iterator = root;
            while (true){
                int compare = node.get_data().compareTo(iterator.get_data());
                if(compare == 0){
                    node.set_parent(iterator);
                    node.set_rightChild(iterator.get_rightChild());
                    if(node.get_rightChild() != null) node.get_rightChild().set_parent(node);
                    iterator.set_rightChild(node);
                    break;
                }
                else if(compare > 0){
                    if(iterator.get_rightChild() != null) iterator = iterator.get_rightChild();
                    else{
                        node.set_parent(iterator);
                        iterator.set_rightChild(node);
                        break;
                    }
                }
                else{
                    if(iterator.get_leftChild() != null) iterator = iterator.get_leftChild();
                    else{
                        node.set_parent(iterator);
                        iterator.set_leftChild(node);
                        break;
                    }
                }
            }
        }
    }

    public DynamicArray<T> preorderTraversal(Node<T> node, DynamicArray<T> array){
        if (node == null) return null;
        array.push(node.get_data());
        preorderTraversal(node.get_leftChild(), array);
        preorderTraversal(node.get_rightChild(), array);
        return array;
    }

    public DynamicArray<T> Traverse(){
        return preorderTraversal(root, new DynamicArray<>());
    }

    private int findCloseBrackets(String sequence, int openBrackets){
        for(int i = openBrackets, len = sequence.length(), opened = 0; i < len; i++){
            if(sequence.charAt(i) == '(') opened++;
            else if (sequence.charAt(i) == ')' && --opened == 0) return i;
        }
        return 0;
    }

    public Node<Integer> nodeFromStr(String sequence, Node<Integer> parent){
        Node<Integer> node = new Node<>(null);
        node.set_parent(parent);
        if (sequence.charAt(0) != '(' || sequence.charAt(sequence.length() - 1) != ')')
            System.out.println("Incorrect sequence");
        sequence = sequence.substring(1, sequence.length() - 1);

        int openBrackets = sequence.indexOf('(');
        if (openBrackets == -1) {
            node.set_data(sequence.isEmpty() ? null : parseInt(sequence));
            return node;
        }

        String strData = sequence.substring(0, openBrackets);
        node.set_data(strData.isEmpty() ? null : parseInt(strData));

        int closeBrackets = findCloseBrackets(sequence, openBrackets);
        if (closeBrackets == 0) System.out.println("Incorrect sequence");

        node.set_leftChild(nodeFromStr(sequence.substring(openBrackets, closeBrackets + 1), node));

        openBrackets = sequence.indexOf('(', closeBrackets);
        if (openBrackets != -1) {
            closeBrackets = findCloseBrackets(sequence, openBrackets);
            if (closeBrackets == 0) System.out.println("Incorrect sequence");
            node.set_rightChild(nodeFromStr(sequence.substring(openBrackets, closeBrackets + 1), node));

        }

        return node;

    }

    public String nodeToStr(Node<T> node){
        StringBuilder stringBuilder = new StringBuilder("(");
        if (node.get_data() != null)
            stringBuilder.append(node.get_data().toString());

        if (node.get_leftChild() != null)
            stringBuilder.append(node.get_leftChild().toString());

        if (node.get_rightChild() != null)
            stringBuilder.append(node.get_rightChild().toString());

        stringBuilder.append(')');
        return stringBuilder.toString();
    }

    public String treeToStr(){
        return nodeToStr(root);
    }

    public BinaryTree<Integer> fromStr(String sequence){
        BinaryTree<Integer> tree = new BinaryTree<>();
        sequence = sequence.replace(" ", "");
        tree.root = nodeFromStr(sequence, null);
        return tree;
    }

    public BinaryTree<Integer> fromFile(Path path) throws IOException {
        return fromStr(Files.readString(path)
                .replace("\r", "")
                .replace("\n", ""));
    }

}
