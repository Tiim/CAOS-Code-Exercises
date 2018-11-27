
class Main {
    public static void main(String[] args) {

        long milis = System.currentTimeMillis();
        long count = 0;

        while (true) {
            count += 1;
            if(milis + 1000 < System.currentTimeMillis() ) {
                milis = System.currentTimeMillis();
                System.out.println(count);
            }
        }

    }
}