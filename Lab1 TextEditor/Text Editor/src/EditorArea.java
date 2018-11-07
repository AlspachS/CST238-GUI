import java.awt.Font;

import javax.swing.JTextArea;

/**
 * Subclass of JTextArea to allow the setting of the text's style
 * and typeface properties from the text editor's menu.
 * 
 * @author Steven Alspach
 */
public class EditorArea extends JTextArea {
	protected String mCurrentTypeface;
	protected int mCurrentStyle;
	protected int mCurrentSize;
	
	public EditorArea() {
		setEditable(true);
		mCurrentSize = getFont().getSize();
	}

	public void setTypeface(String newTypeface) {
		mCurrentTypeface = newTypeface;
		setFont(new Font(mCurrentTypeface, mCurrentStyle, mCurrentSize));
	}

	public void setStyle(int newStyle) {
		mCurrentStyle = newStyle;
		setFont(new Font(mCurrentTypeface, mCurrentStyle, mCurrentSize));
	}
}