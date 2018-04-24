/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package kolokwium2;

import java.util.ArrayList;
import java.util.Iterator;

/**
 *
 * @author Krzysztof
 */
public class Flota {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        
        ArrayList<Pojazd> flota = new ArrayList<>();
        
        SamochodCiezarowy c1 = new SamochodCiezarowy(1000,"C1",420,1200);
        SamochodCiezarowy c2 = new SamochodCiezarowy(2000,"C2",220,2200);
        
        SamochodOsobowy o1 = new SamochodOsobowy(100,"O11",42,200,2);
        SamochodOsobowy o2 = new SamochodOsobowy(200,"O2",22,200,3);
        
        flota.add(c1);
        flota.add(c2);
        flota.add(o1);
        flota.add(o2);
        
        
        
//        for(Pojazd it : flota)
//        {
//            System.out.println("Orginalnie: "+it);
//            it.dodajGazu();
//            System.out.println("Po dodaniu gazu: "+it);
//            it.hamuj();
//            System.out.println("Po hamowanu: "+it);
//            System.out.println("\n");
//        }
        
        for(Iterator<Pojazd> it = flota.iterator();it.hasNext();)
        {
            System.out.println("Item is: "+it.next());
        }
        
    }
    
}
