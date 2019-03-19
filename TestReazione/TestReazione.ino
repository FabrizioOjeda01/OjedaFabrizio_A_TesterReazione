              // Librerie
 #include <LiquidCrystal_I2C.h>
 LiquidCrystal_I2C lcd(0x27, 16, 2);
              // variabili INPUT
 int btn_Inizio;
 int    btn_Led;
 int  btn_Suono;
              // variabili OUTPUT
 int led_Bianco;
 int  led_Verde;
 int  led_Rosso;
 int      suono;
              //  variabili 
 int esito1;
 int esito2;
 int   test;

 void setup() {
  lcd.init();
  lcd.backlight();

  pinMode(btn_Inizio , INPUT);
  pinMode(btn_Led,     INPUT);
  pinMode(btn_Suono ,  INPUT);

  pinMode(led_Bianco,  OUTPUT);
  pinMode(led_Verde,   OUTPUT);
  pinMode(led_Rosso,   OUTPUT);
  pinMode(suono,       OUTPUT);

  btn_Inizio  = 1;
  btn_Led     = 2;
  btn_Suono   = 3;

  led_Bianco  = 8;
  led_Verde   = 9;
  led_Rosso   = 10;
  suono       = 11;

  test        = 750;
}

 void loop() {
  
  //Finché non verrà rilevata la pressione del bottone di inizio, non inizierà nulla
  while(digitalRead(btn_Inizio) == LOW){};
  digitalWrite (led_Verde, LOW);
  digitalWrite (led_Rosso, LOW);
  lcd.clear();

  //Richiamo del metodo per il calcolo del tempo di reazione impiegato sia per il led che per il buzzer
  esito1 = calcoloTempo(led_Bianco, btn_Led, 0, " ");
  esito2 = calcoloTempo(suono, btn_Suono, 1, " ");
   
  //Esito finale, led verde = test superato, led rosso = test non superato
  if(esito1 <= test1 && esito2 <= test2){
    digitalWrite (led_Verde, HIGH);
  }else{
    digitalWrite (led_Rosso, HIGH);
  }
}
  
  int calcoloTempo(int pin, int bottone, int linCursore, String risultato){
    delay(random(1000, 8000));         // Dopo un tempo random che va da 1 secondo a 8 secondi il led/buzzer si accenderà
    digitalWrite(pin, HIGH);
    int ris = 0;
    while (digitalRead(button) == LOW){ // Il while è per determinare il tempo (in millisecondi) di reazione nel premere il bottone
      ris++;
      delay(1);
    }
    lcd.setCursor(0, linCursore);       // Verrà poi stampato il risultato sull'LCD, linea 0 del cursore per led, linea 1 del cursore per il buzzer
    lcd.print(risultato + String(ris) + "ms");
    digitalWrite(pin, LOW);             // Verrà poi spento il led
    return ris;
  }
