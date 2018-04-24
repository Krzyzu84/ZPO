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
public class SamochodCiezarowy extends Pojazd{
    
    
    SamochodCiezarowy(int mocSilnika,String nazwa,int predkosc,int masa)
    {
        super(mocSilnika,nazwa,predkosc,masa);
    }
        
        
    void zaladuj(int ile)
    {
        this.masa +=ile;
    }
    void rozladuj(int ile)
    {
        this.masa -=ile;
    }
    
    @Override
    void dodajGazu()
    {
        this.predkowsc+=(this.mocSilnika*10*2)/this.masa;
    }
    @Override
    void hamuj()
    {
        this.predkowsc-=(mocSilnika*5*5)/this.masa;
    }
    
    public String toString()
    {
        return "Moc = " +this.mocSilnika+" Nazwa = "+this.nazwa+" Predkosc = "+
                this.predkowsc+ " Masa = "+this.masa;
    }
    
}
