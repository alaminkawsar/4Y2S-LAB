public class primitive_root {
    public static void main(String[] args) {
        int d = 9;
        System.out.print("9 ");
        for(int i=0;i<100;i++){
            d = (d*9)%23;
            System.out.print(d+" ");
        }
    }
}
