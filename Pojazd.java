/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package kolokwium2;

/**
 *
 * @author Krzysztof
 */
public abstract class Pojazd {
    int mocSilnika;
    String nazwa;
    int predkowsc;
    int masa;
    
     Pojazd(int mocSilnika,String nazwa,int predkosc,int masa)
     {
      this.mocSilnika=mocSilnika;
      this.nazwa= nazwa;
      this.predkowsc=predkosc;
      this.masa=masa;
     }
    
    
    abstract void dodajGazu();
    abstract void hamuj();
    
    
}
