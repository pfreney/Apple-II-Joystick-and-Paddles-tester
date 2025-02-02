# Apple ][ Joystick and Paddles tester

Collectionneur de matériels Apple, j'avais quelques joysticks et paddles Apple à tester.
Comme je ne voulais pas risquer d'abimer un Apple IIe pour les tests, un court-circuit dans les vieux matériels étant vite arrivés, j'ai décidé de me construire un petit montage de test.
J'ai bien évidemment commencé par cabler sur une plaque Lab, et j'ai décidé, pour m'amuser, d'aller plus loin en construisant le circuit imprimé.

Le coeur du montage est un Arduino. Mon premier montage est à base d'un Arduino Uno que j'avais déjà en stock, mais pour la seconde étape, pour gagner de la place, j'ai utilisé un Arduino mini.

Les joysticks et paddles utilisés avec les Apple II sont construits très simplement : deux potentiomètres pour les quatre directions, deux résistances, et deux boutons. Le schéma est à disposition.
Pour la petite histoire, les deux paddles étaient utilisés, l'un pour la direction nord-sud, et l'autre pour la direction est-ouest. Le joystick a réuni les deux en un avec une manette allant dans les quatre directions. Plus simple !

Le joystick est connecté simplement à l'ordinateur avec un connecteur DE-9M (9 broches, male), alors que pour les paddles, il fallait ouvrir la machine et les connecter sur un support de circuit-intégré 16 broches, situé sur la carte mère.

Le montage permet de connecter l'un ou l'autre :
- le joystick avec un connecteur 9 broches femele
- les paddles avec un support ZIF (zéro insertion force) 16 broches

L'alimentation s'effectue avec un chargeur USB standard et un cable USC-C, en 5 Volt.

Des informations sont inscrites sur un écran 0.96", largement suffisant pour cette utilisation.
Le but est d'afficher une petite croix en fonction de la position des manettes.
Les positions mathématiques horizontales et verticales sont inscrites, tout comme l'état des boutons poussoirs BP0 et BP1.
Deux petites LEDs supplémentaires s'allument lorsque les boutons sont appuyés.

J'ai noté une petite différence de position entre le joystick et les paddles, et j'ai donc rajouté un bouton pour sélectionner l'un ou l'autre, les calculs se font par programmation.

Le tout est placé dans un boitier de montage aux dimensions de 100x60x25 mm en ABS trouvé chez AliExpress. Deux trous ont été faits pour laisser passer le cable USB-C de l'alimentation de l'Arduino, et le connecteur DB9.

Pour la liste des composants :
- 1 x Arduino mini, par exemple chez AliExpress : https://www.aliexpress.com/item/1994733794.html
- 1 x écran OLED I2C 0.96" (VCC, GND, SCL, SDA), par exemple chez AliExpress : https://fr.aliexpress.com/item/1005006901360788.html
- 1 x connecteur DE-9F femelle à souder, par exemple chez AliExpress : https://fr.aliexpress.com/item/4001214300548.html
- 1 x connecteur ZIF 16 broches, par exemple chez AliExpress : https://fr.aliexpress.com/item/32857974149.html
- 2 x résistance (R1, R2) smd 1206 de 150 KΩ, par exemple chez AliExpress : https://fr.aliexpress.com/item/1005005681179895.html
- 1 x résistance (R3) smd 1206 de 10 KΩ, par exemple chez AliExpress : https://fr.aliexpress.com/item/1005005681179895.html
- 2 x résistance (R4, R5) smd 1206 de 180 Ω, par exemple chez AliExpress : https://fr.aliexpress.com/item/1005005681179895.html
- 1 x bouton poussoir smd 2 broches 3x6x2.5 mm, par exemple chez AliExpress : https://fr.aliexpress.com/item/1005006364026072.html
- 2 x LED smd 1206 blanche, par exemple chez AliExpress : https://fr.aliexpress.com/item/4001031824623.html
- 1 x boitier ABS 100x60x25 mm, par exemple chez AliExpress : https://www.aliexpress.com/item/1005006412728406.html

Le circuit imprimé a été fabriqué par JLCPCB https://jlcpcb.com. La commande minimale est de 5 circuits pour un total de 8.68 €, soit 1.8 € le cicuit, port et taxes incluses à destination de la France.


Note 1 : les liens ci-dessus sont pour l'achat en lot, pas à l'unité, pour des questions de couts.
Note 2 : les liens peuvent être faux, le vendeur AliExpress ayant arrêté la vente du produit voulu

Je n'ai pas placé l'Arduino sur des connecteurs pour des questions de hauteur de boitier. Le boitier se referme est est protégé entièrement.


