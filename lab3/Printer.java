import java.util.LinkedList;

public class Printer<T>{

    private void binaryTreeSpace(double n, Node<T> removed) {
        for (; n > 0; n--) {
            System.out.print("\t");
        }
        if (removed == null) {
            System.out.print(" ");
        }
        else {
            System.out.print(removed.get_data());
        }
    }

    private int binaryTreeHeight(Node<T> root) {
        if (root == null) {
            return 0;
        }
        return 1
                + Math.max(binaryTreeHeight(root.get_leftChild()),
                binaryTreeHeight(root.get_rightChild()));
    }

    public void printBinaryTree(Node<T> root) {
        LinkedList<Node<T>> treeLevel = new LinkedList<>();
        treeLevel.add(root);
        LinkedList<Node<T>> temp = new LinkedList<>();
        int counter = 0;
        int height = binaryTreeHeight(root) - 1;
        double numberOfElements
                = (Math.pow(2, (height + 1)) - 1);
        while (counter <= height) {
            Node<T> removed = treeLevel.removeFirst();
            if (temp.isEmpty()) {
                binaryTreeSpace(numberOfElements
                                / Math.pow(2, counter + 1),
                        removed);
            }
            else {
                binaryTreeSpace(numberOfElements
                                / Math.pow(2, counter),
                        removed);
            }
            if (removed == null) {
                temp.add(null);
                temp.add(null);
            }
            else {
                temp.add(removed.get_leftChild());
                temp.add(removed.get_rightChild());
            }

            if (treeLevel.isEmpty()) {
                System.out.println("");
                System.out.println("");
                treeLevel = temp;
                temp = new LinkedList<>();
                counter++;
            }
        }
    }

    private void avlTreeSpace(double n, AVL_Node<T> removed) {
        for (; n > 0; n--) {
            System.out.print("\t");
        }
        if (removed == null) {
            System.out.print(" ");
        }
        else {
            System.out.print(removed.get_data());
        }
    }

    private int avlTreeHeight(AVL_Node<T> root) {
        if (root == null) {
            return 0;
        }
        return 1
                + Math.max(avlTreeHeight(root.get_left()),
                avlTreeHeight(root.get_right()));
    }

    public void printAvlTree(AVL_Node<T> root) {
        LinkedList<AVL_Node<T>> treeLevel = new LinkedList<>();
        treeLevel.add(root);
        LinkedList<AVL_Node<T>> temp = new LinkedList<>();
        int counter = 0;
        int height = avlTreeHeight(root) - 1;
        double numberOfElements
                = (Math.pow(2, (height + 1)) - 1);
        while (counter <= height) {
            AVL_Node<T> removed = treeLevel.removeFirst();
            if (temp.isEmpty()) {
                avlTreeSpace(numberOfElements
                                / Math.pow(2, counter + 1),
                        removed);
            }
            else {
                avlTreeSpace(numberOfElements
                                / Math.pow(2, counter),
                        removed);
            }
            if (removed == null) {
                temp.add(null);
                temp.add(null);
            }
            else {
                temp.add(removed.get_left());
                temp.add(removed.get_right());
            }

            if (treeLevel.isEmpty()) {
                System.out.println("");
                System.out.println("");
                treeLevel = temp;
                temp = new LinkedList<>();
                counter++;
            }
        }
    }

}
