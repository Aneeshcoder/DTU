import javax.swing.*;
import java.awt.*;

public class Exp_11 extends JApplet {
    
    public void init() {
        try {
            SwingUtilities.invokeAndWait(new Runnable() {
                public void run() {
                    buildGUI();
                }
            });
        } catch (Exception e) {
            System.err.println("Couldn't create UI.");
        }
    }

    private void buildGUI() {
        JLabel label = new JLabel("Hello, Swing Applet!");
        add(label, BorderLayout.CENTER);
    }
}
