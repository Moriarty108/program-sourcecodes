package custom;

import javax.servlet.jsp.tagext.*;
import javax.servlet.jsp.*;
import java.io.*;

public class PrintMessage extends SimpleTagSupport {
    private String message = null;

    public void setMessage(String message) {
        this.message = message;
    }

    public void doTag() throws IOException {
        JspWriter out = getJspContext().getOut();
        out.println(message);
    }
}