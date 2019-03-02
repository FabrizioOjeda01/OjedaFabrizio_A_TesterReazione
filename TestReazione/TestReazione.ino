              //variabili input
int btn_Inizio;
int btn_Led;
int btn_beep;
              //variabili OUTPUT
int ledInizio;
int ledVerde;
int ledRosso;
int beep;

void setup() {
  // put your setup code here, to run once:
lcd.begin(16, 2);
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
}

void loop() {
  // put your main code here, to run repeatedly:

}
