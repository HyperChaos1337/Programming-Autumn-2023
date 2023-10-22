import java.util.LinkedList;

public class Printer<T>{

    private void printSpace(double n, Node<T> removed) {
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

    private int heightOfTree(Node<T> root) {
        if (root == null) {
            return 0;
        }
        return 1
                + Math.max(heightOfTree(root.get_leftChild()),
                heightOfTree(root.get_rightChild()));
    }

    public void printBinaryTree(Node<T> root)
    {
        LinkedList<Node<T>> treeLevel = new LinkedList<>();
        treeLevel.add(root);
        LinkedList<Node<T>> temp = new LinkedList<>();
        int counter = 0;
        int height = heightOfTree(root) - 1;
        double numberOfElements
                = (Math.pow(2, (height + 1)) - 1);
        while (counter <= height) {
            Node<T> removed = treeLevel.removeFirst();
            if (temp.isEmpty()) {
                printSpace(numberOfElements
                                / Math.pow(2, counter + 1),
                        removed);
            }
            else {
                printSpace(numberOfElements
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

}
