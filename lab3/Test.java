import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;

public class Test {
    public String getDataFromFile() {
        try {
            return Files.readAllLines(Path.of("data.txt")).get(0);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
    public void init(){

        BinaryTree<Integer> binaryTree = new BinaryTree<>();
        AVL_Tree<Integer> avlTree = new AVL_Tree<>();
        Printer<Integer> printer = new Printer<>();

        DynamicArray<Integer> array = new DynamicArray<>();

        binaryTree = binaryTree.fromStr(getDataFromFile());
        avlTree = binaryTree.toAVL();

        System.out.println("1. Binary tree(Read from file)");
        printer.printBinaryTree(binaryTree.get_root());
        array = binaryTree.traverse();
        System.out.print("Preorder Traverse Result: ");
        array.print();

        System.out.println();
        System.out.println("2. AVL tree(Cast from Binary Tree)");
        printer.printAvlTree(avlTree.get_root());

        array = avlTree.prefixTraverse();
        System.out.print("Prefix Traverse Result: ");
        array.print();

        array = avlTree.infixTraverse();
        System.out.print("Infix Traverse Result: ");
        array.print();

        array = avlTree.postfixTraverse();
        System.out.print("Postfix Traverse Result: ");
        array.print();

        array = avlTree.bfs(avlTree.get_root());
        System.out.print("Breadth-First-Search Result: ");
        array.print();

    }
}
