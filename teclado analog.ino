#include <TM1637Display.h>
#define CLK 3
#define DIO 2
TM1637Display display(CLK, DIO);
//analogicas
const int kb_AnaInPin = 1;
int brilloDisplay = 5;
int wait_NextCycle = 50;
int lecturasPromedio= 10;
int WaitNextReadProm = 5;
int keyBoard_key = 0;

void setup(){
  analogReference(DEFAULT);
  display.setBrightness(brilloDisplay);
}

void loop () {
  ReadValueKeyBoard ();
  delay(wait_NextCycle);
}

void ReadValueKeyBoard()
{
  int temps = 0;
  for(int i=0; i < lecturasPromedio;i++)
  {
    keyBoard_key = analogRead(kb_AnaInPin);
    delay(WaitNextReadProm);
    temps = temps + keyBoard_key;
  }
  temps = temps / lecturasPromedio;
 // display.showNumberDec(temps);
  keyBoard_checkValue(temps);
}

void keyBoard_checkValue(int valor)
{
  int temp = 0;
  if(valor >=1015 &&valor <1025)
  {
    DisplayLineas();
    return;
  }
  if (valor >=165 && valor< 185)
  temp = 0;
  else if (valor >=670 && valor <680)
  temp = 1;
  else if (valor >=500 && valor <510)
  temp = 2;
  else if (valor >=470 && valor <480)
  temp = 3;
  else if (valor >=630 && valor <640)
  temp = 4;
  else if (valor >=400 && valor <410)
  temp = 5;
  else if (valor >=360 && valor <370)
  temp = 6;
  else if (valor >=580 && valor <590)
  temp = 7;
  else if (valor >=260 && valor <270)
  temp = 8;
  else if (valor >=200 && valor <210)
  temp = 9;
   else if (valor >=440 && valor <450)
  temp = 10;
   else if (valor >=320 && valor <330)
  temp = 11;
   else if (valor >=130 && valor <140)
  temp = 12;
   else if (valor >=1 && valor <5)
  temp = 13;
  else if (valor >=550 && valor <560)
  {
    DisplayAsterisco();
    return;
  }
  else if (valor >=90 && valor <100)
  {
    DisplayGato();
    return;
  }
  else
  {
    DisplayLineas();
    return;
  }
  display.showNumberDec(temp);
}

void DisplayLineas(){
  uint8_t segmentos  [] = { SEG_G,SEG_G,SEG_G,SEG_G};
  display.setSegments(segmentos, 4, 4);
}
void DisplayAsterisco(){
  uint8_t segmentos  [] = { SEG_A,SEG_D,SEG_E,SEG_F};
  display.setSegments(segmentos, 1 , 4);
}
void DisplayGato(){
  uint8_t segmentos  [] = { SEG_A,SEG_D,SEG_E,SEG_F};
  display.setSegments(segmentos, 1 , 4);
}
