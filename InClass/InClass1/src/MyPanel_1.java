import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Insets;

import javax.swing.JButton;
import javax.swing.JPanel;

public class MyPanel_1 extends JPanel {

	  public MyPanel_1() {
		    GridBagLayout m_layout = new GridBagLayout();
		    setLayout(m_layout);

		    GridBagConstraints c = new GridBagConstraints();
		    c.insets = new Insets(5,5,5,5);

		    c.gridx = 5;
		    c.gridy = 0;
		    c.weightx = 0.5;
		    c.weighty = 0;
		    c.gridwidth = 2;
		    c.gridheight = 1;
		    c.fill = GridBagConstraints.BOTH;
		    c.anchor = GridBagConstraints.CENTER;
		    add(new JButton("one"), c);
		    
		    c.gridx = 5;
		    c.gridy = 1;
		    c.weightx = 0.5;
		    c.weighty = 0;
		    c.gridwidth = 1;
		    c.gridheight = 1;
		    c.fill = GridBagConstraints.BOTH;
		    c.anchor = GridBagConstraints.CENTER;
		    add(new JButton("two"), c);
		    
		    c.gridx = 6;
		    c.gridy = 1;
		    c.weightx = 0.5;
		    c.weighty = 0;
		    c.gridwidth = 1;
		    c.gridheight = 1;
		    c.fill = GridBagConstraints.BOTH;
		    c.anchor = GridBagConstraints.CENTER;
		    add(new JButton("three"), c);
		    
		    c.gridx = 0;
		    c.gridy = 2;
		    c.weightx = 0;
		    c.weighty = 0;
		    c.gridwidth = 5;
		    c.gridheight = 1;
		    c.fill = GridBagConstraints.HORIZONTAL;
		    c.anchor = GridBagConstraints.NORTH;
		    add(new JButton("four"), c);
		    
		    c.gridx = 5;
		    c.gridy = 2;
		    c.weightx = 0.5;
		    c.weighty = 1;
		    c.gridwidth = 2;
		    c.gridheight = 0;
		    c.fill = GridBagConstraints.BOTH;
		    c.anchor = GridBagConstraints.CENTER;
		    add(new JButton("five"), c);
		    
		    c.gridx = 0;
		    c.gridy = 1;
		    c.weightx = 0;
		    c.weighty = 0;
		    c.gridwidth = 1;
		    c.gridheight = 1;
		    c.fill = GridBagConstraints.BOTH;
		    c.anchor = GridBagConstraints.CENTER;
		    add(new JButton("A"), c);
		    
		    c.gridx = 1;
		    c.gridy = 1;
		    c.weightx = 0;
		    c.weighty = 0;
		    c.gridwidth = 1;
		    c.gridheight = 1;
		    c.fill = GridBagConstraints.BOTH;
		    c.anchor = GridBagConstraints.CENTER;
		    add(new JButton("B"), c);
		    
		    c.gridx = 2;
		    c.gridy = 1;
		    c.weightx = 0;
		    c.weighty = 0;
		    c.gridwidth = 1;
		    c.gridheight = 1;
		    c.fill = GridBagConstraints.BOTH;
		    c.anchor = GridBagConstraints.CENTER;
		    add(new JButton("C"), c);
		    
		    c.gridx = 3;
		    c.gridy = 1;
		    c.weightx = 0;
		    c.weighty = 0;
		    c.gridwidth = 1;
		    c.gridheight = 1;
		    c.fill = GridBagConstraints.BOTH;
		    c.anchor = GridBagConstraints.CENTER;
		    add(new JButton("D"), c);
		    
		    c.gridx = 4;
		    c.gridy = 1;
		    c.weightx = 0;
		    c.weighty = 0;
		    c.gridwidth = 1;
		    c.gridheight = 1;
		    c.fill = GridBagConstraints.BOTH;
		    c.anchor = GridBagConstraints.CENTER;
		    add(new JButton("E"), c);
	  }
}