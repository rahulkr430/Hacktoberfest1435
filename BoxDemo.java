class Box{
    double width;
    double height;
    double depth;
     double volume(){
        return width*height*depth;
     }
     void setDim(double w, double h, double d){
        width = w;
        height = h;
        depth = d;
     }
    }

class BoxDemo {
    public static void main(String args[])

    {
        Box mybox1 = new Box();
        Box mybox2 = new Box();
        mybox1.setDim(10,20,15);
        mybox2.setDim(3,5,10);
        double vol = mybox1.volume();
        System.out.println("volume 1"+vol);
        double vol2 = mybox2.volume();
        System.out.println("volume 2"+vol2);

    }
    
}
