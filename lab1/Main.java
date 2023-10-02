public class Main {
    public static void main(String[] args) {
        System.out.println(ShuntingYard.shunting_yard("3 + 4 * 2 / ( 1 - 5 ) ^ 2"));
        System.out.println(ShuntingYard.shunting_yard("sin ( 1 / 2 * 5 )"));
    }
}