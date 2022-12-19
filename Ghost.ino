#include <Adafruit_NeoPixel.h>
#define LED_PIN 3
#define LED_COUNT 144
#define UP  5
#define DOWN  6

Adafruit_NeoPixel LED(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
int mov = 0;
int aux = 0;
bool eye = 0;

//red         rgb(150,0,0)
//            rgb(150,30,0) orange
//    orange  rgb(150,100,0)
//darkgreen   rgb(0,80,0)
// lime       rgb(0,150,0)
//limegreen   rgb(25,150,50)
// violet     rgb(150,80,150)
//fuchsia     rgb(150,0,150)
//purple      rgb(80,0,80)
int red[10] =   {150,150,150,0,0,25,150,150,80,80};
int green[10]=  {0,30,100,80,150,150,80,0,0,0};
int blue[10]=   {0,0,0,0,0,50,150,150,80,80};
int n = 0;


void setup()
{
  LED.begin();
  LED.show();
  pinMode(UP, INPUT);
  pinMode(DOWN, INPUT);
  
}


void loop()
{
  if(digitalRead(UP) == HIGH) {
  
    n++;
    if (n>9){
      n=0;
    }
    
  } 

  if (digitalRead(DOWN) == HIGH) {
    
    n--;
    if (n<0){
      n=9;
    }
  }

  LED.clear();
  
  int olhos[4] = {52,55,67,64};
  int corpoPar[25] = {15,16,17,18,19,38,41,44,62,65,68,86,87,88,89,90,91,92,110,111,112,113,114,115,116};
  int corpoImpar[32] = {5,6,7,28,29,30,31,32,51,54,57,75,76,77,78,79,80,81,99,100,101,102,103,104,105,123,124,125,126,127,128,129};
  int caldaE[3] = {134,136,140};
  int caldaD[3] = {134,138,140};
  
  
  for(int i = 0; i < 32; i++) // corpo impar
  {
    LED.setPixelColor(corpoImpar[i]-mov, red[n], green[n], blue[n]);
    LED.show();
  }

    for(int i = 0; i < 25; i++) // corpo par
  {
    LED.setPixelColor(corpoPar[i]+mov,  red[n], green[n], blue[n]);
    LED.show();
  }

  if(eye){
    for(int i = 0; i < 3; i++) // calda para esquerda
    {
      LED.setPixelColor(caldaE[i]+mov,  red[n], green[n], blue[n]);
      LED.show();
    }
  }
  else{
    for(int i = 0; i < 3; i++) // calda para direita
  {
    LED.setPixelColor(caldaD[i]+mov,  red[n], green[n], blue[n]);
    LED.show();
  }
  }

    for(int i = 0; i < 4; i++)//olhos
  {
    if (eye){
      if (olhos[i]==52 ||olhos[i]==55){ //impar
            LED.setPixelColor(olhos[i]-mov+1, 51, 150, 150);
            LED.show();
          }
          else{ //par
            LED.setPixelColor(olhos[i]+mov-1, 51, 150, 150);
            LED.show();
          }
    }
    else{
      if (olhos[i]==52 ||olhos[i]==55 ){ //impar
            LED.setPixelColor(olhos[i]-mov, 51, 150, 150);
            LED.show();
          }
          else{ //par
            LED.setPixelColor(olhos[i]+mov, 51, 150, 150);
            LED.show();
          }
    }
    
  }
if(aux<3){
  mov++;
  aux++;
  eye=0;
}
else{
  mov--;
  eye = 1;
  if(mov==-2){
    aux = -2;
  }
}

delay(400);

}
