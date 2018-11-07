import javax.swing.JFrame;

public class CalculatorMain {

	public static void main(String[] args) {
		JFrame window = new JFrame();
		window.setSize(300, 400);
		window.setTitle("Steven Alspach");
		window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		Calculator calc = new Calculator();
		
		window.add(calc);
		window.setVisible(true);
	}
}