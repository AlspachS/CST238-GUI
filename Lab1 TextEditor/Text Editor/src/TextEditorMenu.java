import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowEvent;

import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

import javax.swing.JFileChooser;
import javax.swing.JFrame;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;

/**
 * Menu for the TextEditor. This class creates the menus that determine the text
 * formatting of the TextEditor, such as font style and typeface. It also holds
 * the ActionListeners used to implement the actions of the menu.
 * 
 * @author Steven Alspach
 */
public class TextEditorMenu extends JMenuBar {
	EditorArea mEditor;
	JFrame mWindow;

	public TextEditorMenu(JFrame window, EditorArea editor) {
		mEditor = editor;
		mWindow = window;

		JMenu menu = new JMenu("File");
		add(menu);

		JMenuItem item = new JMenuItem("Load");
		item.addActionListener(new LoadAction());
		menu.add(item);
		item = new JMenuItem("Save");
		item.addActionListener(new SaveAction());
		menu.add(item);
		item = new JMenuItem("Exit");
		item.addActionListener(new ExitAction());
		menu.add(item);

		menu = new JMenu("Typeface");
		add(menu);

		item = new JMenuItem("Monospace");
		item.addActionListener(new TypefaceAction(mEditor, Font.MONOSPACED));
		menu.add(item);
		item = new JMenuItem("Serif");
		item.addActionListener(new TypefaceAction(mEditor, Font.SERIF));
		menu.add(item);
		item = new JMenuItem("Sans Serif");
		item.addActionListener(new TypefaceAction(mEditor, Font.SANS_SERIF));
		menu.add(item);

		menu = new JMenu("Style");
		add(menu);

		item = new JMenuItem("Plain");
		item.addActionListener(new StyleAction(mEditor, Font.PLAIN));
		menu.add(item);
		item = new JMenuItem("Bold");
		item.addActionListener(new StyleAction(mEditor, Font.BOLD));
		menu.add(item);
		item = new JMenuItem("Italic");
		item.addActionListener(new StyleAction(mEditor, Font.ITALIC));
		menu.add(item);
	}

	/**
	 * Used for changing the style of the text from the text editor's menu. Current
	 * implemented styles are: Plain, Bold, and Italic.
	 * 
	 * @author Steven Alspach
	 */
	public class StyleAction implements ActionListener {
		int mStyle;

		public StyleAction(EditorArea editor, int style) {
			mStyle = style;
			mEditor = editor;
		}

		public void actionPerformed(ActionEvent e) {
			mEditor.setStyle(mStyle);
		}
	}

	/**
	 * Used for changing the typeface of the text from the text editor's menu.
	 * Current implemented typefaces are Monospaced, Serif, and Sans Serif.
	 * 
	 * @author Steven Alspach
	 */
	public class TypefaceAction implements ActionListener {
		String mTypeface;

		public TypefaceAction(EditorArea editor, String typeface) {
			mTypeface = typeface;
			mEditor = editor;
		}

		public void actionPerformed(ActionEvent e) {
			mEditor.setTypeface(mTypeface);
		}
	}

	/**
	 * Allows the window to be closed from the menu option.
	 * 
	 * @author Steven Alspach
	 */
	public class ExitAction implements ActionListener {

		public void actionPerformed(ActionEvent e) {
			mWindow.dispatchEvent(new WindowEvent(mWindow, WindowEvent.WINDOW_CLOSING));
		}
	}

	/**
	 * Uses a BufferedWriter to write the text in the text editor to a 
	 * file.  No formatting information is persisted.
	 * 
	 * @author Steven Alspach
	 */
	public class SaveAction implements ActionListener {

		public void actionPerformed(ActionEvent e) {
			JFileChooser fileDialog = new JFileChooser();
			int dialogOption = fileDialog.showSaveDialog(mEditor);

			if (dialogOption == JFileChooser.APPROVE_OPTION) {
				try (BufferedWriter out = new BufferedWriter(new FileWriter(fileDialog.getSelectedFile()))) {
					out.write(mEditor.getText());
				} catch (IOException e1) {
				}
			}
		}
	}

	/**
	 * Uses a Scanner to load text from a file to the text area. No formatting
	 * information is changed.
	 * 
	 * @author Steven Alspach
	 */
	public class LoadAction implements ActionListener {

		public void actionPerformed(ActionEvent e) {
			JFileChooser fileDialog = new JFileChooser();
			int dialogOption = fileDialog.showOpenDialog(mEditor);

			if (dialogOption == JFileChooser.APPROVE_OPTION) {
				try (Scanner in = new Scanner(new FileReader(fileDialog.getSelectedFile())).useDelimiter("\\Z")) {
					mEditor.setText(in.next());
				} catch (FileNotFoundException e1) {
				}
			}
		}
	}
}