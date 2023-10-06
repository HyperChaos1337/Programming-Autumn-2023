enum Priority{
    None, Low, Medium, High;
}

public class ShuntingYard {

    private final String functions = "cossin";
    private final String operators = "+-*/^()";
    private final String separator = ",";

    private int open_brackets = 0;

    ShuntingYard() {
    }

    private MyStack<String> stringMyStack = new MyStack<>();

    private static Priority get_priority(String token) {
        return switch (token) {
            case "+", "-" -> Priority.Low;
            case "*", "/" -> Priority.Medium;
            case "^" -> Priority.High;
            default -> Priority.None;
        };
    }

    public String algorithm(String input) {
        StringBuilder result = new StringBuilder();
        String[] tokens = input.split(" ");
        for (int i = 0; i < tokens.length; ++i) {
            String token = tokens[i];
            if (token.matches("[0-9]+")) result.append(token).append(" ");
            else if (operators.contains(token)) {
                if (token.equals("(")) {
                    open_brackets++;
                    stringMyStack.push(token);
                } else if (token.equals(")")) {
                    while (!stringMyStack.peek().equals("(")) {
                        result.append(stringMyStack.pop()).append(" ");
                    }
                    stringMyStack.pop();
                    if (stringMyStack.peek() != null && functions.contains(stringMyStack.peek()))
                        result.append(stringMyStack.pop()).append(" ");
                    open_brackets--;
                } else if (!stringMyStack.is_empty() && get_priority(token).equals(get_priority(stringMyStack.peek()))) {
                    result.append(stringMyStack.pop()).append(" ");
                    stringMyStack.push(token);
                } else stringMyStack.push(token);
            } else if (functions.contains(token)) stringMyStack.push(token);

        }
        while (!stringMyStack.is_empty()) result.append(stringMyStack.pop()).append(" ");
        return result.toString();
    }

}
