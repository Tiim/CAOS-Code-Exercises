/* Rechnerarchitektur und Betriebssysteme �bung 4

    jlottner 200412, ykilcher 201211
    
    Die Mensa bekommt vom Koch frische Gerichte, giesst dann ein wenig Fett darueber (1 Sekunde lang), die Professoren k�nnen sie abholen, falls es welche hat.
    
    Falls es nichts mehr hat werden die Profs aufgefordert zu warten.
    
    Falls es schon 10 Gerichte hat, wird dem Koch befohlen, sich schlafen zu legen. Er wird dann geweckt, wenn es noch weniger als 3 Portionen hat.
    
    
    Hier die n�tigen Funktionen einf�gen!
    Verwenden sie die vorgegebenen Ausgaben!
*/

import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Queue;

class Mensa {

    private final Queue<String> queue = new ArrayDeque<>();

    public synchronized void put(String[] gerichte) {
        queue.addAll(Arrays.asList(gerichte));

        System.out.println("(" + System.currentTimeMillis() + ") Mensa: Ah, der Nachschub ist da. Noch ein bisschen Fett darüber giessen...");

        if (queue.size() > 10) {
            System.out.println("(" + System.currentTimeMillis() + ") Mensa: !Mach mal ne Pause, Koch!");
            try {
                this.wait();
            } catch (InterruptedException ignored) {
            }
        }

        System.out.println("(" + System.currentTimeMillis() + ") Mensa: Neue Gerichte bereit. Koennt alle kommen!");
        this.notifyAll();
    }

    public synchronized String get(int id) throws InterruptedException {
        String s = null;
        while (s == null) {
            if (queue.isEmpty()) {
                System.out.println("(" + System.currentTimeMillis() + ") " + "Mensa: Nichts mehr da, Herr Prof " + id + ", sie muessen warten!");
                wait();

            } else {
                s = queue.poll();
            }
        }
        System.out.println("(" + System.currentTimeMillis() + ") Mensa: Voila, einmal " + s + " fuer Prof " + id + ".");
        System.out.println("(" + System.currentTimeMillis() + ") Mensa: Noch " + queue.size() + " Gerichte uebrig.");

        if (queue.size() <= 3) {
            System.out.println("(" + System.currentTimeMillis() + ") Mensa: !Aufwachen!");
            this.notify();
        }

        return s;
    }

}
