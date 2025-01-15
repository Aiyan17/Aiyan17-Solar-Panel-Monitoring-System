const long Rf = 100000; //enter value of feedback resistor in Ohms
const long Ri = 20000; //enter value of bias resistor in Ohms*/
const long R1 = 20000; //enter value of series resistor in Ohms
const long R2 = 100000 ; //enter value of load resistor in Ohms
const long Rsh = 50; //enter value of shunt resistor in Ohms
float Read_Vtemp = A1;//value read from ADC on pin A1
float Read_Itemp  = A0;//value read from ADC on pin A0
float Gain  ; //Gain of the Op-Amp Circuit
float Vtemp; //setting temporary analog voltage input
float Itemp; //setting temporary analog current input (actually a voltage reading)
float Voltage = 0.0; //initializing voltage reading
float Current = 0.0; //initializing current reading
float Power = 0.0;   //initializing power calculation
int a = 100;
#include <LiquidCrystal.h> 
const int rs = 2, en = 4, d4 = 9, d5 = 10, d6 = 11, d7 = 12; // set digital output pins for LCD display
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() 
{
  Serial.begin(9600); //set up serial monitor

  
  lcd.begin(16, 2); // set up LCD display

  // write to LCD display to verify it's working
 lcd.print(" Circuits I "); 
  lcd.setCursor(0, 1); 
  lcd.print(" Wattmeter "); 
  delay(2000);
  lcd.setCursor(0, 0);
  lcd.print("Please give us"); 
  lcd.setCursor(0, 1); 
 lcd.print("    an  A   ");
delay(2000);
  lcd.clear();
lcd.print("Loading.");  
  delay(500);
lcd.clear();
lcd.print("Loading..");
delay(500);
lcd.clear();
lcd.print("Loading...");
}

void loop() 
{
 
 Vtemp = analogRead(Read_Vtemp);
 Itemp = analogRead(Read_Itemp);

 // Voltage Measurement
 // 1. Converts the analog input (max 5V) into a digital value (max 1024)
 // 2. Accounts for the voltage divider calculation
  Voltage = Vtemp * (5.0/1024.0) * (R1+R2) / R2; //in Volts
 Gain = 1+Rf/Ri;
 // Current Measurement
 // 1. Calculates the Op-Amp Gain
 // Gain = 1+(Rf/Ri); //in V/V
 // 2. Converts the analog input (5V max) into a digital value (max 1024)
 // 3. Accounts for the op-amp gain, current to voltage conversion (Rsh), and units (mA=1/1000)
 Current = Itemp*(5.0/1024.0)/(Gain*Rsh)*1000; //in mA
// Current = Vtemp*(5.0/1024.0)/(R2+R1);
 
 // Power Measurement
 Power = Voltage * Current;//Calculation of power from solar panel in mW

 // Print values to the serial monitor for verification
 Serial.print("ADCV reads: ");
 Serial.print(Vtemp);
 Serial.print("   Solar Panel Voltage is: ");
 Serial.print(Voltage);
 Serial.print(" Volts");
 Serial.println("");
 Serial.println("  ");
 delay(1000); 
  
 Serial.print("ADCI reads: ");
 Serial.print(Itemp);
 Serial.print("   Solar Panel Current is: ");
 Serial.print(Current);
 Serial.print(" milliAmps");
 Serial.println("");
 Serial.println("  ");
 delay(1000); 
  
 Serial.print("Solar Panel Power is: ");
 Serial.print(Power);
 Serial.print(" milliWatts");
 Serial.println("  ");
 Serial.println("__________________");
 delay(1000); 

  
   // Replace Voltage, Power, and Current with the actual variables
  lcd.setCursor(0, 0); 
  lcd.print("V="); 
  lcd.print(Voltage); 
  lcd.print("V"); 

  lcd.print("P="); 
  lcd.print(Power); 
  lcd.print("mW"); 

  lcd.setCursor(0, 1); 
  lcd.print("I="); 
  lcd.print(Current); 
  lcd.print(" mA"); 

  delay(1000);
}
