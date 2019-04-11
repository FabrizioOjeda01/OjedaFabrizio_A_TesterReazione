              // Librerie
 #include <LiquidCrystal_I2C.h>
 LiquidCrystal_I2C lcd(0x27, 16, 2);
              // variabili INPUT
 int btn_Inizio;
 int    btn_Led;
 int  btn_Suono;
              // variabili OUTPUT
 int led_Blu;
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

  btn_Inizio  = 2;
  btn_Led     = 3;
  btn_Suono   = 4;

  led_Blu  = 8;
  led_Verde   = 9;
  led_Rosso   = 10;
  suono       = 11;

  
  pinMode(btn_Inizio , INPUT);
  pinMode(btn_Led,     INPUT);
  pinMode(btn_Suono ,  INPUT);

  pinMode(led_Blu,  OUTPUT);
  pinMode(led_Verde,   OUTPUT);
  pinMode(led_Rosso,   OUTPUT);
  pinMode(suono,       OUTPUT);

  test        = 750;
}

 void loop() {
  
  //Finché non verrà rilevata la pressione del bottone di inizio, non inizierà nulla
  delay(400);
  while(digitalRead(btn_Inizio) == LOW){};
  lcd.clear();
  lcd.print("Test inziato");
  digitalWrite (led_Verde, LOW);
  digitalWrite (led_Rosso, LOW);

  //Richiamo del metodo per il calcolo del tempo di reazione impiegato sia per il led che per il buzzer
  esito1 = calcoloTempo(led_Blu, btn_Led, 0, "Led: ");
  esito2 = calcoloTempo(suono, btn_Suono, 1, "Suono: ");
   
  //Esito finale, led verde = test superato, led rosso = test non superato
  if(esito1 <= test && esito2 <= test){
    digitalWrite (led_Verde, HIGH);
  }else{
    digitalWrite (led_Rosso, HIGH);
  }
  
  while(digitalRead(btn_Inizio) == LOW){};
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Premere per");
  lcd.setCursor(0, 1);
  lcd.print("inziare");
}
  
  int calcoloTempo(int pin, int bottone, int linCursore, String spazio){
    delay(random(1000, 8000));         // Dopo un tempo random che va da 1 secondo a 8 secondi il led/buzzer si accenderà
    digitalWrite(pin, HIGH);
    int ris = 0;
    while (digitalRead(bottone) == LOW){ // Il while è per determinare il tempo (in millisecondi) di reazione nel premere il bottone
      ris++;
      delay(1);
    }
    lcd.setCursor(0, linCursore);       // Verrà poi stampato il risultato sull'LCD, linea 0 del cursore per led, linea 1 del cursore per il buzzer
    lcd.print(spazio + String(ris) + "ms       ");
    digitalWrite(pin, LOW);             // Verrà poi spento il led
    return ris;
  }
