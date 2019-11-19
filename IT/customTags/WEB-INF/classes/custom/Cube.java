package custom;

import javax.servlet.jsp.tagext.*;
import javax.servlet.jsp.*;
import java.io.*;

public class Cube extends SimpleTagSupport {
    private int num;

    public void setNum(int num) {
        this.num = num;
    }

    public void doTag() throws IOException {
        JspWriter out = getJspContext().getOut();
        out.println(num * num * num);
    }
}