import java.util.Random;

class Game {
    private String name;
    private String engineUsed;
    private double version;
    private int gID;
    private String dev;
    private String pub;
    private static final int GID_RANGE = 1000;
    private static final int GID_MINVALUE = 7653;
    public String getName() {
        return this.name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getEngineUsed() {
        return this.engineUsed;
    }

    public void setEngineUsed(String engineUsed) {
        this.engineUsed = engineUsed;
    }

    public double getVersion() {
        return this.version;
    }

    public void setVersion(double version) {
        this.version = version;
    }

    public int getGID() {
        return this.gID;
    }

    public String getDev() {
        return this.dev;
    }

    public void setDev(String dev) {
        this.dev = dev;
    }

    public String getPub() {
        return this.pub;
    }

    public void setPub(String pub) {
        this.pub = pub;
    }

    public Game(String name, double version) {
        this.name = name;
        this.version = version;
        Random rand = new Random();
        this.gID = rand.nextInt(GID_RANGE) + GID_MINVALUE;
    }

    @Override
    public String toString() {
        return "{" + " Name='" + getName() + "'" + ", engineUsed='" + getEngineUsed() + "'" + ", version='"
                + getVersion() + "'" + ", gID='" + getGID() + "'" + ", dev='" + getDev() + "'" + ", pub='" + getPub()
                + "'" + "}";
    }
}