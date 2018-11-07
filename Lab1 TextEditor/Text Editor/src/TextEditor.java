import javax.swing.JFrame;
import javax.swing.JScrollPane;

/**
 * Main driver for a light-weight text editor. Creates the objects needed and
 * hooks them together so they can operate on each other.
 * 
 * @author Steven Alspach
 */
public class TextEditor {

	public static void main(String[] args) {
		JFrame window = new JFrame();
		window.setSize(600, 400);
		window.setTitle("Steven Alspach");
		window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		EditorArea editor = new EditorArea();
		window.setJMenuBar(new TextEditorMenu(window, editor));

		JScrollPane scroller = new JScrollPane(editor);

		window.add(scroller);

		window.setVisible(true);
	}
}