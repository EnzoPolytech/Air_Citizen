#include "mbed.h"

AnalogIn NO2(A0);
AnalogIn O3(A1);

Serial sig(D5,D0);

int main()
{
    float meas_r_NO2;
    float meas_v_NO2;
    
    float meas_r_O3;
    float meas_v_O3;
    
    float NO2_ppb;
    float O3_ppb;
    
    /*float coef_capteur_NO2 = ;
    float coef_capteur_O3 = ;
    float offset_NO2= ;
    float offset_O3= ;*/
    while(1) {

        meas_r_NO2 = NO2.read(); 
        meas_v_NO2 = meas_r_NO2 * 3300; 
        
        meas_r_O3 = O3.read(); 
        meas_v_O3 = meas_r_O3 * 3300;
        
        sig.printf("AT$SF=%02x\r\n", meas_v_NO2);
        sig.printf("AT$SF=%02x\r\n", meas_v_O3);
        
        /*NO2_ppb = coef_capteur_NO2 * meas_v_NO2 + offset_NO2 ;
        O3_ppb = coef_capteur_O3 * meas_v_O3 + offset_O3 ;
        
        sig.printf("AT$SF=%02x\r\n", NO2_ppb);
        sig.printf("AT$SF=%02x\r\n", O3_ppb);*/
        wait(30);
    }
}
