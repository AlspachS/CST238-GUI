import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Insets;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JPanel;

public class Calculator extends JPanel {
	Screen mDisplayArea = new Screen();
	String mOperation = "";
	double mLeft;
	double mRight;

	public Calculator() {
		GridBagLayout mLayout = new GridBagLayout();
		setLayout(mLayout);

		GridBagConstraints cuffs = new GridBagConstraints();
		cuffs.insets = new Insets(5, 5, 5, 5);

		cuffs.gridx = 0;
		cuffs.gridy = 0;
		cuffs.gridwidth = 4;
		cuffs.gridheight = 1;
		cuffs.weightx = 1;
		cuffs.weighty = 0;
		cuffs.fill = GridBagConstraints.HORIZONTAL;
		cuffs.anchor = GridBagConstraints.CENTER;
		add(mDisplayArea, cuffs);

		cuffs.gridx = 0;
		cuffs.gridy = 1;
		cuffs.gridwidth = 1;
		cuffs.gridheight = 1;
		cuffs.weightx = 0.25;
		cuffs.weighty = 0.2;
		cuffs.fill = GridBagConstraints.BOTH;
		cuffs.anchor = GridBagConstraints.CENTER;
		JButton clear = new JButton("C");
		clear.addActionListener(new ClearListener());
		add(clear, cuffs);

		cuffs.gridx = 1;
		cuffs.gridy = 1;
		cuffs.gridwidth = 1;
		cuffs.gridheight = 1;
		cuffs.weightx = 0.25;
		cuffs.weighty = 0.2;
		cuffs.fill = GridBagConstraints.BOTH;
		cuffs.anchor = GridBagConstraints.CENTER;
		JButton negative = new JButton("+/-");
		negative.addActionListener(new NegativeListener());
		add(negative, cuffs);

		cuffs.gridx = 2;
		cuffs.gridy = 1;
		cuffs.gridwidth = 1;
		cuffs.gridheight = 1;
		cuffs.weightx = 0.25;
		cuffs.weighty = 0.2;
		cuffs.fill = GridBagConstraints.BOTH;
		cuffs.anchor = GridBagConstraints.CENTER;
		JButton divide = new JButton("/");
		divide.addActionListener(new OperationListener("/"));
		add(divide, cuffs);

		cuffs.gridx = 3;
		cuffs.gridy = 1;
		cuffs.gridwidth = 1;
		cuffs.gridheight = 1;
		cuffs.weightx = 0.25;
		cuffs.weighty = 0.2;
		cuffs.fill = GridBagConstraints.BOTH;
		cuffs.anchor = GridBagConstraints.CENTER;
		JButton multiply = new JButton("X");
		multiply.addActionListener(new OperationListener("*"));
		add(multiply, cuffs);

		cuffs.gridx = 0;
		cuffs.gridy = 2;
		cuffs.gridwidth = 1;
		cuffs.gridheight = 1;
		cuffs.weightx = 0.25;
		cuffs.weighty = 0.2;
		cuffs.fill = GridBagConstraints.BOTH;
		cuffs.anchor = GridBagConstraints.CENTER;
		add(new NumericButton("7", mDisplayArea), cuffs);

		cuffs.gridx = 1;
		cuffs.gridy = 2;
		cuffs.gridwidth = 1;
		cuffs.gridheight = 1;
		cuffs.weightx = 0.25;
		cuffs.weighty = 0.2;
		cuffs.fill = GridBagConstraints.BOTH;
		cuffs.anchor = GridBagConstraints.CENTER;
		add(new NumericButton("8", mDisplayArea), cuffs);

		cuffs.gridx = 2;
		cuffs.gridy = 2;
		cuffs.gridwidth = 1;
		cuffs.gridheight = 1;
		cuffs.weightx = 0.25;
		cuffs.weighty = 0.2;
		cuffs.fill = GridBagConstraints.BOTH;
		cuffs.anchor = GridBagConstraints.CENTER;
		add(new NumericButton("9", mDisplayArea), cuffs);

		cuffs.gridx = 3;
		cuffs.gridy = 2;
		cuffs.gridwidth = 1;
		cuffs.gridheight = 1;
		cuffs.weightx = 0.25;
		cuffs.weighty = 0.2;
		cuffs.fill = GridBagConstraints.BOTH;
		cuffs.anchor = GridBagConstraints.CENTER;
		JButton subtract = new JButton("-");
		subtract.addActionListener(new OperationListener("-"));
		add(subtract, cuffs);

		cuffs.gridx = 0;
		cuffs.gridy = 3;
		cuffs.gridwidth = 1;
		cuffs.gridheight = 1;
		cuffs.weightx = 0.25;
		cuffs.weighty = 0.2;
		cuffs.fill = GridBagConstraints.BOTH;
		cuffs.anchor = GridBagConstraints.CENTER;
		add(new NumericButton("4", mDisplayArea), cuffs);

		cuffs.gridx = 1;
		cuffs.gridy = 3;
		cuffs.gridwidth = 1;
		cuffs.gridheight = 1;
		cuffs.weightx = 0.25;
		cuffs.weighty = 0.2;
		cuffs.fill = GridBagConstraints.BOTH;
		cuffs.anchor = GridBagConstraints.CENTER;
		add(new NumericButton("5", mDisplayArea), cuffs);

		cuffs.gridx = 2;
		cuffs.gridy = 3;
		cuffs.gridwidth = 1;
		cuffs.gridheight = 1;
		cuffs.weightx = 0.25;
		cuffs.weighty = 0.2;
		cuffs.fill = GridBagConstraints.BOTH;
		cuffs.anchor = GridBagConstraints.CENTER;
		add(new NumericButton("6", mDisplayArea), cuffs);

		cuffs.gridx = 3;
		cuffs.gridy = 3;
		cuffs.gridwidth = 1;
		cuffs.gridheight = 1;
		cuffs.weightx = 0.25;
		cuffs.weighty = 0.2;
		cuffs.fill = GridBagConstraints.BOTH;
		cuffs.anchor = GridBagConstraints.CENTER;
		JButton sum = new JButton("+");
		sum.addActionListener(new OperationListener("+"));
		add(sum, cuffs);

		cuffs.gridx = 0;
		cuffs.gridy = 4;
		cuffs.gridwidth = 1;
		cuffs.gridheight = 1;
		cuffs.weightx = 0.25;
		cuffs.weighty = 0.2;
		cuffs.fill = GridBagConstraints.BOTH;
		cuffs.anchor = GridBagConstraints.CENTER;
		add(new NumericButton("1", mDisplayArea), cuffs);

		cuffs.gridx = 1;
		cuffs.gridy = 4;
		cuffs.gridwidth = 1;
		cuffs.gridheight = 1;
		cuffs.weightx = 0.25;
		cuffs.weighty = 0.2;
		cuffs.fill = GridBagConstraints.BOTH;
		cuffs.anchor = GridBagConstraints.CENTER;
		add(new NumericButton("2", mDisplayArea), cuffs);

		cuffs.gridx = 2;
		cuffs.gridy = 4;
		cuffs.gridwidth = 1;
		cuffs.gridheight = 1;
		cuffs.weightx = 0.25;
		cuffs.weighty = 0.2;
		cuffs.fill = GridBagConstraints.BOTH;
		cuffs.anchor = GridBagConstraints.CENTER;
		add(new NumericButton("3", mDisplayArea), cuffs);

		cuffs.gridx = 3;
		cuffs.gridy = 4;
		cuffs.gridwidth = 1;
		cuffs.gridheight = 2;
		cuffs.weightx = 0.25;
		cuffs.weighty = 0.2;
		cuffs.fill = GridBagConstraints.BOTH;
		cuffs.anchor = GridBagConstraints.CENTER;
		JButton equals = new JButton("=");
		equals.addActionListener(new EqualsListener());
		add(equals, cuffs);

		cuffs.gridx = 0;
		cuffs.gridy = 5;
		cuffs.gridwidth = 2;
		cuffs.gridheight = 1;
		cuffs.weightx = 0.5;
		cuffs.weighty = 0.2;
		cuffs.fill = GridBagConstraints.BOTH;
		cuffs.anchor = GridBagConstraints.CENTER;
		add(new NumericButton("0", mDisplayArea), cuffs);

		cuffs.gridx = 2;
		cuffs.gridy = 5;
		cuffs.gridwidth = 1;
		cuffs.gridheight = 1;
		cuffs.weightx = 0.25;
		cuffs.weighty = 0.2;
		cuffs.fill = GridBagConstraints.BOTH;
		cuffs.anchor = GridBagConstraints.CENTER;
		JButton decimal = new JButton(".");
		decimal.addActionListener(new DecimalListener());
		add(decimal, cuffs);
	}
	
	private void Equals() {
		mRight = mDisplayArea.getValue();
		switch (mOperation) {
		case "+":
			mLeft += mRight;
			break;
		case "-":
			mLeft -= mRight;
			break;
		case "*":
			mLeft *= mRight;
			break;
		case "/":
			if (mRight != 0) {
				mLeft /= mRight;
			}
			break;
		default:
			break;
		}
		if (mRight == 0) {
			mDisplayArea.setText("Error");
		} else {
			mDisplayArea.setValue(mLeft);				
		}
	}

	private class OperationListener implements ActionListener {
		String mOperator;
		
		public OperationListener(String operator) {
			mOperator = operator;
		}

		public void actionPerformed(ActionEvent e) {
			if(mOperation.equals("")) {
				mLeft = mDisplayArea.getValue();
			} else {
				Equals();
			}
			mOperation = mOperator;
			
		}
	}

	private class NegativeListener implements ActionListener {

		public void actionPerformed(ActionEvent e) {
			mDisplayArea.addNegative();
		}
	}

	private class EqualsListener implements ActionListener {

		public void actionPerformed(ActionEvent e) {
			Equals();
		}
	}

	private class DecimalListener implements ActionListener {
		public void actionPerformed(ActionEvent e) {
			mDisplayArea.addDecimal();
		}
	}

	private class ClearListener implements ActionListener {

		public void actionPerformed(ActionEvent e) {
			mOperation = "";
			mLeft = 0;
			mRight = 0;
			mDisplayArea.clear();
		}
	}
}
