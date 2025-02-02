# Apple ][ Joystick and Paddles tester

Collectionneur de matériels Apple, j'avais quelques joysticks et paddles Apple à tester.
Comme je ne voulais pas risquer d'abimer un Apple IIe pour les tests, un court-circuit dans les vieux matériels étant vite arrivés, j'ai décidé de me construire un petit montage de test.
J'ai bien évidemment commencé par cabler sur une plaque Lab, et j'ai décidé, pour m'amuser, d'aller plus loin en construisant le circuit imprimé.

Le coeur du montage est un Arduino. Mon premier montage est à base d'un Arduino Uno que j'avais déjà en stock, mais pour la seconde étape, pour gagner de la place, j'ai utilisé un Arduino mini.

Les Joysticks et Paddles utilisés avec les Apple II sont construits très simplement : deux potentiomètres pour les quatre directions, deux résistances, et deux boutons. Le schéma est à disposition.
Pour la petite histoire, les deux paddles étaient utilisés, l'un pour la direction nord-sud, et l'autre pour la direction est-ouest. Le joystick a réuni les deux en un avec une manette allant dans les quatre directions. Plus simple !

Le joystick est connecté simplement à l'ordinateur avec un connecteur DB9 (9 broches), alors que pour les paddles, il fallait ouvrir la machine et les connecter sur un support de circuit-intégré 16 broches, situé sur la carte mère.

Le montage permet donc de connecter l'un ou l'autre :
- le josytisk avec un connecteur 9 broches femele
- les paddles avec un support ZIF 16 broches

L'alimentation s'effectue avec un chargeur USB standard et un cable USC-C, en 5 Volt.

Des informations sont inscrites sur l'écran 0.96", largement suffisant pour cette utilisation.
Le but est d'afficher une petite croix en fonction de la position des manettes.
Les positions mathématiques horizontales et verticales sont inscrites, tout comme l'état des boutons poussoirs BP0 et BP1.
Deux petites LEDs s'allument lorsque les boutons sont appuyés.

J'ai noté une petite différence de position entre le joystick et les paddles, et le
