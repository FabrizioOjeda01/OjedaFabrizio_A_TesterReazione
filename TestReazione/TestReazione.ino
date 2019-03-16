#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

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
lcd.init();
lcd.backlight();

pinMode(btn_Inizio , INPUT);
pinMode(btn_Led,     INPUT);
pinMode(btn_Suono ,  INPUT);

pinMode(led_Inizio,  OUTPUT);
pinMode(led_Verde,   OUTPUT);
pinMode(led_Rosso,   OUTPUT);
pinMode(suono,       OUTPUT);

btn_Inizio  = 1;
btn_Led     = 2;
btn_Suono   = 3;

led_Inizio  = 8;
led_Verde   = 9;
led_Rosso   = 10;
suono       = 11;

test1       = 750;
test2       = 750;
}

void loop() {
  //Finché non verrà rilevata la pressione del bottone di inizio, non inizierà nulla
  while(digitalRead(btn_Inizio) == LOW){};
  digitalWrite (led_Verde, LOW);
  digitalWrite (led_Rosso, LOW);
  lcd.clear();

  //Richiamo del metodo per il calcolo del tempo di reazione impiegato sia per il led che per il buzzer
  /*esito1 = inserire metodo con variabili input
    esito2= inserire meotodo con variabili input */
   
  //Esito finale, led verde= test superato, led rosso = test non superato
  if(esito1 <= test1 && esito2 <= test2){
  digitalWrite (led_Verde, HIGH);
  }else{
  digitalWrite (led_Rosso, HIGH);
  }
}
