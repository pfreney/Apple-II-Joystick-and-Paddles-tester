# Apple ][ Joystick and Paddles tester

## Introduction

Collectionneur de matériels Apple, j'avais quelques joysticks et paddles Apple à tester.
Comme je ne voulais pas risquer d’abimer un Apple IIe pour les tests, un court-circuit dans les vieux matériels étant vite arrivé, j’ai décidé de me construire un petit montage de test.

Le cahier des charges est rapidement fait :
- tester les directions en affichant les coordonnées sur l’écran ainsi qu’un curseur qui se déplace;
- tester les deux boutons PB0 et PB1, afficher le résultat sur l’écran et allumer une LED pour chacun.

Le cœur du montage est un Arduino. Mon premier montage est à base d’un Arduino Uno que j’avais déjà en stock, mais pour la seconde étape, pour gagner de la place, j’ai utilisé un Arduino mini.

Les joysticks et paddles utilisés avec les Apple II sont construits très simplement : deux potentiomètres pour les quatre directions, deux résistances, et deux boutons. Le schéma est à disposition dans ce dossier.
Le joystick est connecté simplement à l’ordinateur avec un connecteur DE-9M (9 broches mâles), alors que pour les paddles, il fallait ouvrir la machine et les connecter sur un support de circuit intégré à 16 broches, situé sur la carte mère.
Les schémas du joystick et des paddles sont disponibles dans ce dépôt (repository).


Le montage permet de connecter l’un ou l’autre :
- le joystick avec un connecteur 9 broches femelle;
- les paddles avec un support ZIF (zéro insertion force) 16 broches.
L’alimentation s’effectue avec un chargeur USB standard et un câble USC-C, en 5 Volts.

Des informations sont inscrites sur un écran 0.96 pouce, largement suffisant pour cette utilisation.
Le but est d’afficher une petite croix en fonction de la position des manettes.
Les positions mathématiques horizontales et verticales sont inscrites, tout comme l’état des boutons-poussoirs PB0 et PB1.
Deux petites LED supplémentaires s’allument lorsque les boutons sont appuyés.

J’ai noté une petite différence de position entre le joystick et les paddles, et j’ai donc rajouté un bouton pour sélectionner l’un ou l’autre, les calculs se font par programmation.

Le schéma du montage complet est disponible dans ce dépôt (repository).

Le tout est placé dans un boitier de montage aux dimensions de 100x60x25 mm en ABS. Deux trous ont été faits manuellement pour laisser passer le câble USB-C de l’alimentation de l’Arduino, et le connecteur DE-9F.


## Construction

Pour la liste des composants :

- 1 x Arduino mini, par exemple chez AliExpress : https://www.aliexpress.com/item/1994733794.html
- 1 x écran OLED I2C 0.96 pouce (VCC, GND, SCL, SDA), par exemple chez AliExpress : https://fr.aliexpress.com/item/1005006901360788.html
- 1 x connecteur DE-9F femelle à souder, par exemple chez AliExpress : https://fr.aliexpress.com/item/4001214300548.html
- 1 x connecteur ZIF 16 broches, par exemple chez AliExpress : https://fr.aliexpress.com/item/32857974149.html
- 2 x résistance (R1, R2) smd 1206 de 150 kΩ, par exemple chez AliExpress : https://fr.aliexpress.com/item/1005005681179895.html
- 1 x résistance (R3) smd 1206 de 10 kΩ, par exemple chez AliExpress : https://fr.aliexpress.com/item/1005005681179895.html
- 2 x résistance (R4, R5) smd 1206 de 180 Ω, par exemple chez AliExpress : https://fr.aliexpress.com/item/1005005681179895.html
- 1 x bouton poussoir smd 2 broches 3x6x2.5 mm, par exemple chez AliExpress : https://fr.aliexpress.com/item/1005006364026072.html
- 2 x LED smd 1206 blanche, par exemple chez AliExpress : https://fr.aliexpress.com/item/4001031824623.html
- 1 x boitier ABS 100x60x25 mm, par exemple chez AliExpress : https://www.aliexpress.com/item/1005006412728406.html

Le circuit imprimé a été fabriqué par JLCPCB https://jlcpcb.com.

Note 1 : les liens ci-dessus sont pour l’achat en lot, pas à l’unité, pour des questions de coûts.
Note 2 : les liens peuvent être morts, le vendeur AliExpress ayant peut-être arrêté la vente du produit voulu.

L’Arduino est directement soudé sur le circuit pour des gains de place en hauteur, car le boitier se referme, et l’ensemble est protégé quand il est rangé.
Les connecteurs permettent d’enlever et de remplacer rapidement l’Arduino en cas de défaillance. Ce ne sera pas le cas ici.

Je n'ai pas placé l'Arduino sur des connecteurs pour des questions de hauteur de boitier. Le boitier se referme et est protégé entièrement.


## Coût

Le coût total, port compris, du circuit complet, revient à moins de 10 € l’unité.

En réalité, c’est plus compliqué de calculer, car j’achète les composants en lot qui me servent à faire d’autres montages. Pour vous donner une idée, j’ai acheté un lot de 1200 résistances à 5,79 € et un lot de 250 boutons-poussoirs à 4.09 €.
Donc, si vous commandez les composants à l’unité chez n’importe quel revendeur français ou étranger, le prix risque d’être différent (je n’ai pas fait la démarche).

Pour le circuit imprimé, la commande minimale chez JLCPCB est de 5 pièces. Chaque circuit m’est revenu à 0,92 €, port et taxes incluses à destination de la France (total de 4,59 €).
À noter que j’ai payé avec PayPal, et que le fabricant prend 0.53 € de frais supplémentaires.


## Programmation

L’application Arduido IDE a été utilisé. Rien de vraiment spécial dans la programmation de ce montage. Chaque ligne ou presque du programme est documentée. Désolé, les commentaires sont en français.


## Utilisation

Rien de bien compliqué, soit on branche le Joystick sur le connecteur 9 broches sur le côté de la boite, soit on branche les paddles sur le support vert (avec le levier) du montage.
Ne pas oublier d’alimenter via le port USB-C avec n’importe quel chargeur ou ordinateur sous la main.
Et voilà, ne reste plus qu’à manipuler la manette pour voir la croix bouger sur l’écran.
Si on appuie sur un des deux boutons du joystick, la LED s’allume et l’information passe à "ON" sur l’écran.
C’est identique avec les paddles.

Petite vidéo pour expliquer le fonctionnement :
https://www.youtube.com/watch?v=9ZfeMaLszHQ


## Licence

Vous en faites ce que vous voulez. Je peux me tromper, mais je ne vois pas vraiment un industriel construire ce montage pour le vendre à des milliers d'exemplaires et gagner des millions d'euros ou de dollars ! ;-)
Pour moi, cela a surtout été une bonne expérience amusante de faire ce petit montage, et c'est pourquoi je le mets en libre disposition. 





