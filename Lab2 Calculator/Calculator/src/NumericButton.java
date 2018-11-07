import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;

public class NumericButton extends JButton {
	String mDisplayString;
	Screen mDisplayArea;
	
	public NumericButton(String value, Screen display) {
		setText(mDisplayString = value);
		mDisplayArea = display;
		
		addActionListener(new NumericButtonAction());
	}
	
	private class NumericButtonAction implements ActionListener {

		public void actionPerformed(ActionEvent e) {
			mDisplayArea.addDigit(mDisplayString);
		}		
	}
}