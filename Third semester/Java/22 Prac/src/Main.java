import java.awt.Color;
import java.awt.Graphics;
import java.awt.Image;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;

import javax.imageio.ImageIO;
import javax.swing.*;

class ImagePanel extends JComponent {
    private Image image;
    public ImagePanel(Image image) {
        this.image = image;
    }
    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        g.drawImage(image, 0, 0, this);
    }
}

public class Main extends JPanel{
    public static void main(String[] args) throws IOException {
        String img_path = "";
        for (var arg : args){
            if (arg.contains("path="))
                img_path = arg.split("=")[1];
        }

        if (img_path.equals(""))
            return;

        BufferedImage myImage = ImageIO.read(new File(img_path));
        JFrame myJFrame = new JFrame("Image pane");
        myJFrame.setContentPane(new ImagePanel(myImage));
        myJFrame.setVisible(true);

        new Main();
    }
}