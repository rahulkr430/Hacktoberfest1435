public class Method {
    static void myStaticMethod(){
        System.out.println("Static methods can be called without object");
        
    }
    public void myPublicMethod(){
        System.out.println("Public method must be called by creating");
    }
    public static void main(String[] args){
        myStaticMethod();
        Main myObj = new Main();
        myObj.myPublicMethod();
    }
    
}
