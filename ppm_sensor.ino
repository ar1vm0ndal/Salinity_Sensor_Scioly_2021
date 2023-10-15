int condVal; //this sets an integer called condVal which is used in later calculations in the code below



const int redPin = 10;//Sets digital pin as Red LED's control
const int bluePin = 8; //Sets digital pin as Blue LED's control
const int greenPin = 6;//Sets digital pin as Green LED's control 

const int dividerPin = 9;
int runs = 0;
double values[5];

double vToPpm(double voltage){
  
  double ppm =   (-1.93407*pow(134.269,voltage))+(pow(119.168,voltage))+(pow(144.09,voltage));
  return ppm;

}


void setup() {
  Serial.begin(9600); //establishes a connection to the Arduino at a baud rate of 9600
  
 
  pinMode(redPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(greenPin, OUTPUT);

  pinMode(dividerPin, OUTPUT);


}

void loop() 
{ //everything between these curly braces will Loop
  
      digitalWrite(dividerPin, HIGH);
      condVal = analogRead(A0); //this sets the integer condVal equal to the value read from analog @ on the Arduino
      double voltage = condVal*(3.40/1023.00000); //calculation of relative conductivity, essentially this is a measure of the voltage drop
      //across the conductivity probe. As the conductivity increases, the voltage drop across the
      //probe also increases
             

     double ppm = vToPpm(voltage);
     Serial.print("Voltage: ");
     Serial.print(voltage,4);
     Serial.print("  Conc: ");
     Serial.print(ppm);
     Serial.print("\n");
      

    
      if(ppm < 1200){
          digitalWrite(redPin, HIGH);
          digitalWrite(bluePin, LOW);
          digitalWrite(greenPin, LOW);
          
      }else if(ppm < 2000){
          digitalWrite(redPin, LOW);
          digitalWrite(bluePin, LOW);
          digitalWrite(greenPin, LOW);
            
      }else if (ppm < 3100){
          digitalWrite(redPin, LOW);
          digitalWrite(bluePin, LOW);
          digitalWrite(greenPin, HIGH);  
          
      }else if (ppm >= 3100){
          digitalWrite(redPin, LOW);
          digitalWrite(bluePin, HIGH);
          digitalWrite(greenPin, LOW);
      }
    //  digitalWrite(dividerPin,LOW);
    //  delay(500);
  
     
    Serial.print("Off\n");
    digitalWrite(dividerPin,LOW);
  delay(5000); //delay before looping, numerical values are in milliseconds
}
