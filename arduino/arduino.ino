#define BLYNK_PRINT Serial
#include <LedMatrix.h>

#define MAX_TESTED_VALUES 100
#define NUMBER_OF_DEVICES 1
#define CS_PIN D8
LedMatrix ledMatrix = LedMatrix(NUMBER_OF_DEVICES, CS_PIN);

byte hearth[] =
{
  B00111000,
  B01111100,
  B00111110,
  B00011111,
  B00111110,
  B01111100,
  B00111000,
  B00000000
};

byte happy[] =
{
  B00000000,
  B01101100,
  B01100010,
  B00000010,
  B00000010,
  B01100010,
  B01101100,
  B00000000
};

byte clindoeil[] =
{
  B00000000,
  B00101100,
  B00100010,
  B00000010,
  B00000010,
  B01100010,
  B01101100,
  B00000000
};

byte chinois[] = {
  B00000000,
  B00101000,
  B00100100,
  B00000010,
  B00000010,
  B00100010,
  B00101100,
  B00000000
};

byte tm[] = {
  B00011111,
  B00001000,
  B00000100,
  B00001111,
  B00110000,
  B00001000,
  B00001111,
  B00001000
};

byte twentytwo[] = {
  B00010001,
  B00101001,
  B00100101,
  B00010011,
  B00011001,
  B00100101,
  B00100011,
  B00010001
};

byte letterj[] = {
  B00000000,
  B01000000,
  B01111110,
  B01111111,
  B01000001,
  B00001111,
  B00001110,
  B00000000
};

byte letterc[] = {
  B00000000,
  B00100100,
  B01100110,
  B01000010,
  B01000010,
  B01000010,
  B01111110,
  B00111100
};

/*
 * --- setup ---
 * Set up several things:
 *      - WiFi
 *      - Soil Sensor pin
 *      - Serial
 *      - LED Matrix
 *
 */
void setup()
{
  // Debug console
  Serial.begin(9600);
  delay(200);
  Serial.println("");
  Serial.println("NodeMCU Started");
  
  setupMatrix();
};

/*
 * --- loop ---
 * Just call each second the method that reads the soil sensor value.
 *
 */
void loop()
{
  display(happy);
  delay(10000);
  display(chinois);
  delay(10000);
  display(twentytwo);
  delay(10000);
  display(clindoeil);
  delay(10000);
  display(hearth);
  delay(10000);
  display(letterc);
  delay(10000);
  display(letterj);
  delay(10000);
}

void setupMatrix(){
  ledMatrix.init();
  ledMatrix.setIntensity(15); // range is 0-15
  clearScreen();
}

void display(byte drawing[] ){
  for (int i=0; i < 8; i++){
    ledMatrix.setColumn(i, drawing[i]);
  }
  ledMatrix.commit();
}
void clearScreen(){
  ledMatrix.clear();
  ledMatrix.commit();
}
