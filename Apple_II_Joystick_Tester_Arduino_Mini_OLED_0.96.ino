// ************************************************************
//
// Testeur de joysticks et paddles Apple
//
// Patrice Freney - https://www.freney.net
//
// version 1.0 du 2025/02/05

// carte Arduino mini
// ecran OLED noir et blanc de 128 x 64 pixels de 0.96 pouces

// branchements des composants :
// SDA de l'écran OLED sur la broche A4 de l'Arduino
// SDK de l'écran OLED sur la broche A5 de l'Arduino

// pour le joystick :
// axe des x sur la broche A0 de l'Arduino
// axe des y sur la broche A1 de l'Arduino
// bouton BP0 sur la broche A2 de l'Arduino
// bouton BP1 sur la broche A3 de l'Arduino

// un bouton Joystick/paddles qui permet de sélectionner soit l'un soit l'autre
// bouton branché sur la broche D10

// deux leds pour la simulation des boutons 0 et 1
// led 1 sur la sortie D11
// led 2 sur la sortie D12

// Arduino Application version 2.3.4
//
// Adafruit_GFX.h version 1.11.1
// Adafruit_SSD1306.h version 2.5.13
// Bounce2 version 2.71
//
// ************************************************************


// ************************************************************
// pour les variables :
//    - ve_ : entier (sauf pour les boucles)
//    - vr_ : reel
//    - vb_ : booleen
//    - vllong_ : long long
//
// ************************************************************


// librairies utilisées
#include <Wire.h>              // communication avec les écrans I2c
#include <Adafruit_GFX.h>      // gestion des écrans, https://github.com/adafruit/Adafruit-GFX-Library
#include <Adafruit_SSD1306.h>  // gestion de l'écran SSD1306, https://github.com/adafruit/Adafruit_SSD1306
#include <Bounce2.h>           // gestion des boutons anti-rebondissement, https://github.com/thomasfredericks/Bounce2

Adafruit_SSD1306 display(128, 64, &Wire, -1);  // déclaration pour un écran SSD1306 connecté à I2C (SDA, SCL)

// Bounce2
Bounce2::Button button = Bounce2::Button();  // INSTANTIATE A Button OBJECT

// déclaration des variables
int ve_button0_valeur;
int ve_button1_valeur;
int ve_buttonjp_valeur;
int ve_axex_valeur;
int ve_axey_valeur;
int ve_curseur_x;
int ve_curseur_y;
bool vb_button_jp_stat_joystick = true;


// désignation des broches utilisées
const byte axex = 0;           // axe horizontal broche A0
const byte axey = 1;           // axe vertical broche A1
const byte button_0 = 2;       // bouton 0 broche A2
const byte button_1 = 3;       // bouton 1 broche A3
#define button_jp 10           // Bounce2 // bouton joystick/paddles broche D10
const byte led_button_0 = 11;  // led 1 broche D11
const byte led_button_1 = 12;  // led 2 broche D12


void setup() {
  // connexion avec l'écran
  Serial.begin(115200);
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ;
  }

  delay(200);
  display.clearDisplay();
  display.setTextSize(1);       // taille de l'écriture
  display.setTextColor(WHITE);  // écriture blanche, sinon noire par défaut

  // affichage textes bienvenue, rien d'obligatoire
  display.setCursor(1, 10);
  display.print("Testeur de joysticks et paddles Apple ][");
  display.setCursor(1, 40);
  display.print("Patrice Freney");
  display.setCursor(62, 55);
  display.print("v1.0 - 2025");
  display.display();
  delay(2000);  // ce n'est rien, quelques millisecondes dans une vie… ;-)
  display.clearDisplay();
  display.display();


  // définition des entrées
  pinMode(axex, INPUT);             // axe horizontal
  pinMode(axey, INPUT);             // axe vertical
  pinMode(button_0, INPUT);         // bouton 0
  pinMode(button_1, INPUT);         // bouton 1
  button.attach(button_jp, INPUT);  // Bounce2 : USE EXTERNAL PULL-UP

  // gestion des paramètres pour les boutons avec Bounce2
  button.interval(5);           // Bounce2 : DEBOUNCE INTERVAL IN MILLISECONDS
  button.setPressedState(LOW);  // Bounce2 : INDICATE THAT THE LOW STATE CORRESPONDS TO PHYSICALLY PRESSING THE BUTTON

  // définition des sorties
  pinMode(led_button_0, OUTPUT);  // led 1 pour le bouton 0
  pinMode(led_button_1, OUTPUT);  // led 2 pour le bouton 1
}

void loop() {
  // lecture des entrées : boutons BP0 et BP1, ainsi que les potentiomètres X et Y
  ve_button0_valeur = analogRead(button_0);
  ve_button1_valeur = analogRead(button_1);
  ve_axex_valeur = analogRead(axex);
  ve_axey_valeur = analogRead(axey);

  display.clearDisplay();                 // effacer l'écran
  display.drawRect(0, 0, 64, 64, WHITE);  // dessin du rectangle de fond

  // dessin des lignes avec une coupure au centre pour voir le curseur en position centrale
  display.drawLine(32, 0, 32, 27, WHITE);   // ligne verticale haute
  display.drawLine(32, 37, 32, 63, WHITE);  // ligne verticale basse
  display.drawLine(0, 32, 27, 32, WHITE);   // ligne horizontale gauche
  display.drawLine(37, 32, 63, 32, WHITE);  // ligne horizontale droite

  // gestion du bouton joystick & paddles
  // affichage du mode
  display.setCursor(70, 0);
  display.print("Mode :");

  button.update();                                             // Bounce2 : UPDATE THE BUTTON, YOU MUST CALL THIS EVERY LOOP
  if (button.pressed()) {                                      // Bounce2
    vb_button_jp_stat_joystick = !vb_button_jp_stat_joystick;  // inversion du mode
  }

  // gestion du curseur
  // les coordonnées ve_curseur_x et ve_curseur_y représentent le centre du curseur en forme de croix

  // calculs des coordonnées du curseur x et y selon le mode Joystick ou paddles.
  // il y a quelques différences et comme les chiffres minimaux ne sont pas les mêmes, le curseur pouvait sortir de l'écran.
  // donc, choix avec le bouton du mode pour les tests.
  if (vb_button_jp_stat_joystick == true) {  // mode joystick, mesures relevées
    ve_curseur_x = map(ve_axex_valeur, 1023, 542, 1, 64);
    ve_curseur_y = map(ve_axey_valeur, 1023, 542, 1, 64);
  } else {  // mode paddles, mesures relevées
    ve_curseur_x = map(ve_axex_valeur, 1023, 460, 1, 64);
    ve_curseur_y = map(ve_axey_valeur, 1023, 480, 1, 64);
  }

  // vérification des valeurs maximales x et y
  // avec certains paddles, les potentiomètres mal calibrés ou défaillants faisaient sortir la croix de l'écran
  if (ve_curseur_x > 64) {  // si pour une raison diverse, le calcul de ve_curseur_x >64, valeur maximale = 64
    ve_curseur_x = 64;
  }
  if (ve_curseur_y > 64) {  // si pour une raison diverse, le calcul de ve_curseur_y  >64, valeur maximale = 64
    ve_curseur_y = 64;
  }

  // dessin du curseur 5x5 pixels
  display.drawLine(ve_curseur_x - 2, ve_curseur_y, ve_curseur_x + 2, ve_curseur_y, WHITE);  // ligne horizontale
  display.drawLine(ve_curseur_x, ve_curseur_y - 2, ve_curseur_x, ve_curseur_y + 2, WHITE);  // ligne verticale

  // afficher les valeurs de positionnement du curseur
  display.setCursor(70, 46);
  display.print("X : ");
  display.print(ve_axex_valeur);

  display.setCursor(70, 56);
  display.print("Y : ");
  display.print(ve_axey_valeur);

  // afficher le statut du mode Joystick ou paddles
  display.setCursor(70, 10);
  if (vb_button_jp_stat_joystick == true) {
    display.print("Joystick");
  } else {
    display.print("Paddles");
  }

  // gestion du bouton 0
  display.setCursor(70, 23);
  display.print("BP0 : ");
  if (ve_button0_valeur < 1000) {
    display.print("OFF");
    digitalWrite(led_button_0, LOW);
  } else {
    display.print("ON");
    digitalWrite(led_button_0, HIGH);
  }

  // gestion du bouton 1
  display.setCursor(70, 33);
  display.print("BP1 : ");
  if (ve_button1_valeur < 1000) {
    display.print("OFF");
    digitalWrite(led_button_1, LOW);
  } else {
    display.print("ON");
    digitalWrite(led_button_1, HIGH);
  }

  display.display();  // mettre à jour l'affichage
  delay(10);          // petite temporisation

}  // loop


// ************************************************************

