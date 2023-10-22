import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;

public class Main {
    public static String getDataFromFile() {
        try {
            return Files.readAllLines(Path.of("data.txt")).get(0);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
    public static void main(String[] args) {
        BinaryTree<Integer> binaryTree = new BinaryTree<>();
        binaryTree = binaryTree.fromStr(getDataFromFile());
        Printer<Integer> printer = new Printer<>();
        printer.printBinaryTree(binaryTree.get_root());
    }
}
