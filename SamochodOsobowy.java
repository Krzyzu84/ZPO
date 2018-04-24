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
public class SamochodOsobowy extends Pojazd{
    
    int liczbaMiejsc;
    
    SamochodOsobowy(int mocSilnika,String nazwa,int predkosc,int masa,int liczbaMiejsc)
    {
        super(mocSilnika,nazwa,predkosc,masa);
        this.liczbaMiejsc=liczbaMiejsc;
    }
    
    
    @Override
    void dodajGazu()
    {
        this.predkowsc+=(this.mocSilnika*10*5)/this.masa;
    }
    @Override
    void hamuj()
    {
        this.predkowsc-=(mocSilnika*5*2)/this.masa;
    }
    
        public String toString()
    {
        return "Moc = " +this.mocSilnika+" Nazwa = "+this.nazwa+" Predkosc = "+
                this.predkowsc+ " Masa = "+this.masa+" Liczba miejsc = "+this.liczbaMiejsc;
    }
}
