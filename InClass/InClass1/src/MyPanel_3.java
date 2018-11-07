import javax.swing.GroupLayout;
import javax.swing.JButton;
import javax.swing.JPanel;

public class MyPanel_3 extends JPanel {
	public MyPanel_3() {
		GroupLayout layout = new GroupLayout(this);
		setLayout(layout);
	
		JButton c1 = new JButton("C1");
		JButton c2 = new JButton("C2");
		JButton c3 = new JButton("C3");
		JButton c4 = new JButton("C4");
		
	    // Turn on automatically adding gaps between components
		layout.setAutoCreateGaps(true);

		// Turn on automatically creating gaps between components that touch
		// the edge of the container and the container.
		layout.setAutoCreateContainerGaps(true);

		layout.setHorizontalGroup(
				   layout.createSequentialGroup()
				      .addComponent(c1)
				      .addComponent(c2)
				      .addGroup(layout.createParallelGroup()
				         .addComponent(c3)
				         .addComponent(c4))
				);
		layout.setVerticalGroup(
				   layout.createSequentialGroup()
				      .addGroup(layout.createParallelGroup()
						   .addComponent(c1)
						   .addComponent(c2)
						   .addComponent(c3))
				      .addComponent(c4)
				);
	}
}