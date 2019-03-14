#include <LiquidCrystal_I2C.h>

              // variabili input
int btn_Inizio;
int btn_Led;
int btn_Suono;
              // variabili OUTPUT
int led_Inizio;
int led_Verde;
int led_Rosso;
int suono;
             //  variabili 
int esito1;
int esito2;
int test1;
int test2;

void setup() {

pinMode(btn_Inizio , INPUT);
pinMode(btn_Led, INPUT);
pinMode(btn_beep , INPUT);

pinMode(ledInizio,OUTPUT);
pinMode(ledVerde,OUTPUT);
pinMode(ledRosso,OUTPUT);
pinMode(beep,OUTPUT);

btn_Inizio = 1;
btn_Led    = 2;
btn_beep   = 3;

ledInizio  = 8;
ledVerde   = 9;
ledRosso   = 10;
beep       = 11;

test1      = 750;
test2      = 750;
}

void loop() {
  //Finché non verrà rilevata la pressione del bottone di inizio, non inizierà nulla
  while(digitalRead(btn_Inizio) == LOW){};
  digitalWrite (led_Verde LOW);
  digitalWrite (led_Rosso LOW);
  lcd.clear();

  //Richiamo del metodo per il calcolo del tempo di reazione impiegato sia per il led che per il buzzer
  /*esito1 = inserire metodo con variabili input
    esito2= inserire meotodo con variabili input
   */
   //Esito finale, led verde= test superato, led rosso = test non superato
   if(esito1 <= test1 && esito2 <= test2){
    digitalWrite (led_Verde HIGH);
   }else{
    digitalWrite (led_Rosso HIGH);
   }
}
