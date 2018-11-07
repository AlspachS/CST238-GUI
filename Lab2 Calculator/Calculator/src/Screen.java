import java.awt.Font;

import javax.swing.JTextField;
import javax.swing.SwingConstants;

public class Screen extends JTextField {
	boolean nextNumber = false;

	public Screen() {
		setText("0");
		setEditable(false);
		setHorizontalAlignment(SwingConstants.RIGHT);
		setFont(new Font(getFont().getName(), getFont().getStyle(), 20));
	}

	public void addDigit(String numeral) {
		String current = getText();
		if (nextNumber || current.equals("0")) {
			nextNumber = false;
			setText(numeral);
		} else if (!current.equals("0")) {
			setText(current + numeral);
		}
	}

	public void addDecimal() {
		String current = getText();
		if (!current.contains(".")) {
			setText(current += ".");
		}
	}

	public void addNegative() {
		String current = getText();
		if (current.startsWith("-")) {
			current = current.substring(1);
		} else {
			current = "-" + current;
		}
		setText(current);
	}

	public double getValue() {
		nextNumber = true;
		return Double.parseDouble(getText());
	}

	public void setValue(double value) {
		setText(Double.toString(value));
	}
	
	public void clear() {
		setText("0");
		nextNumber = false;
	}
}