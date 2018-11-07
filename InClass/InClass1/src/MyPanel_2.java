import javax.swing.ButtonGroup;
import javax.swing.GroupLayout;
import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JRadioButton;
import javax.swing.JTextField;

public class MyPanel_2 extends JPanel {
	public MyPanel_2() {
		GroupLayout layout = new GroupLayout(this);
		setLayout(layout);

		JButton find = new JButton("Find");
		JButton replace_find = new JButton("Replace Find");
		JButton replace = new JButton("Replace");
		JButton replace_all = new JButton("Replace All");
		JButton close = new JButton("Close");

		JLabel find_label = new JLabel("Find:");
		JLabel replace_with = new JLabel("Replace withxxxxxxxxxxxxxxxxxxxxxxxxx:");
		JLabel direction = new JLabel("Direction");
		JLabel scope = new JLabel("Scope");
		JLabel options = new JLabel("Options");

		JTextField findString = new JTextField(20);
		JTextField replaceString = new JTextField(20);

		JRadioButton forward = new JRadioButton("Forward");
		JRadioButton backward = new JRadioButton("Backward");
		JRadioButton all = new JRadioButton("All");
		JRadioButton selected = new JRadioButton("Selected lines");

		ButtonGroup directionGroup = new ButtonGroup();
		directionGroup.add(forward);
		directionGroup.add(backward);

		ButtonGroup scopeGroup = new ButtonGroup();
		scopeGroup.add(all);
		scopeGroup.add(selected);

		// Turn on automatically adding gaps between components
		layout.setAutoCreateGaps(true);

		// Turn on automatically creating gaps between components that touch
		// the edge of the container and the container.
		layout.setAutoCreateContainerGaps(true);

		layout.setHorizontalGroup(layout.createParallelGroup()
				.addGroup(layout.createSequentialGroup()
						.addGroup(layout.createParallelGroup()
								.addComponent(find_label)
								.addComponent(replace_with))
						.addGroup(layout.createParallelGroup()
								.addComponent(findString)
								.addComponent(replaceString)))
				.addGroup(layout.createSequentialGroup()
						.addGroup(layout.createParallelGroup()
								.addComponent(direction)
								.addComponent(forward)
								.addComponent(backward))
						.addGroup(layout.createParallelGroup()
								.addComponent(scope)
								.addComponent(all)
								.addComponent(selected))
						
						));

		layout.setVerticalGroup(layout.createSequentialGroup()
				.addGroup(layout.createParallelGroup()
						.addComponent(find_label)
						.addComponent(findString))
				.addGroup(layout.createParallelGroup()
						.addComponent(replace_with)
						.addComponent(replaceString))
				.addGroup(layout.createParallelGroup()
						.addComponent(direction)
						.addComponent(scope))
				.addGroup(layout.createParallelGroup()
						.addComponent(forward)
						.addComponent(all))
				.addGroup(layout.createParallelGroup()
						.addComponent(backward)
						.addComponent(selected)));
			
	}
}










