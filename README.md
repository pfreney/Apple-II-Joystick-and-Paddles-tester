# Apple ][ Joystick and Paddles tester

## Introduction

As a collector of Apple hardware, I had a few (+30) Apple joysticks and paddles to test. As I didn't want to risk damaging an Apple IIe for the tests, a short circuit in old equipment can happen very quickly, so I decided to build myself a little test circuit.

![Screenshot of the Apple Joystick and Paddles.](/pictures/joystick_and_paddles.jpg)


The specifications were :
- test the directions by displaying the coordinates on the screen and a moving cursor;
- test the two buttons PB0 and PB1, display the result on the screen and light an LED for each.

The joysticks and paddles used with Apple IIs are very simply constructed: two potentiometers for the four directions, two resistors and two buttons. The schematics of the joystick and paddles are available in this repository.

The joystick is simply connected to the computer with a DE-9M connector (9-pin male), while the paddles had to be opened up and connected to a 16-pin IC socket on the motherboard.

The assembly allows you to connect either :
- the joystick with a 9-pin female connector;
- the paddles with a 16-pin ZIF (zero insertion force) socket.
Power is supplied by a standard USB charger and a 5-volt USC-C cable.

The core of the assembly is an Arduino mini.\
Information is displayed on a 0.96-inch screen, more than sufficient for this application.\
The idea is to display a small cross according to the position of the joysticks.\
Horizontal and vertical mathematical positions are shown, as is the status of push-buttons PB0 and PB1.\
Two additional small LEDs light up when the buttons are pressed.

I noticed a small difference in position between the joystick and the paddles, so I added a button to select one or the other, and the calculations are done by programming.

The complete schematic is available in this repository.

The whole unit is housed in a 100x60x25 mm ABS mounting box. Two holes have been drilled to accommodate the Arduino's USB-C power cable and DE-9F connector.


![Screenshot of the pcb in is box.](/pictures/Testeur_Joystick_boitier_complet.jpg)


## Construction

For the list of components:

- 1 x Arduino mini: https://www.aliexpress.com/item/1994733794.html
- 1 x 0.96-inch OLED I2C display (VCC, GND, SCL, SDA): https://fr.aliexpress.com/item/1005006901360788.html
- 1 x DE-9F female solder connector: https://fr.aliexpress.com/item/4001214300548.html
- 1 x 16-pin ZIF connector: https://fr.aliexpress.com/item/32857974149.html
- 2 x 150 kΩ smd 1206 resistors (R1, R2): https://fr.aliexpress.com/item/1005005681179895.html
- 1 x resistor (R3) smd 1206 10 kΩ: https://fr.aliexpress.com/item/1005005681179895.html
- 2 x resistor (R4, R5) smd 1206 180 Ω: https://fr.aliexpress.com/item/1005005681179895.html
- 1 x 2-pin smd pushbutton 3x6x2.5 mm: https://fr.aliexpress.com/item/1005006364026072.html
- 2 x LED smd 1206 white: https://fr.aliexpress.com/item/4001031824623.html
- 1 x ABS case 100x60x25 mm: https://www.aliexpress.com/item/1005006412728406.html

The printed circuit board was manufactured by JLCPCB https://jlcpcb.com.

[!NOTE]
- the links are to AliExpress, they are given as examples only. The links may be dead, as the AliExpress seller may have stopped selling the desired product.
- the above links are for batch purchases, not single units, for cost reasons.

The Arduino is soldered directly onto the circuit board, saving space in terms of height, as the case closes, and the whole unit is protected when stored. The connectors allow the Arduino to be quickly removed and replaced in the event of failure. This will not be the case here.

![Screenshot of the pcb.](/pictures/Testeur_Joystick_composants.jpg)


## Cost

The total cost, including postage, of the complete circuit is less than 10 € per unit.

In reality, it's more complicated to calculate, as I buy components in batches that I use to make other assemblies. To give you an idea, I bought a batch of 1200 various resistors for 5.79 € and a batch of 250 various push-buttons for 4.09 €.\
So, if you order the components individually from any retailer, the price is likely to be different (I didn't do it myself).

For the printed circuit board, the minimum order from JLCPCB is 5 pieces. Each circuit cost me 0.92 €, including postage and taxes to France (total 4.59 €. Please note that I paid with PayPal, and that the manufacturer charges an additional 0.53 €.


## Programming

The Arduido IDE application was used. There's nothing really special about the programming of this assembly. Almost every line of the program is documented. Sorry, the comments are in French. The program is available in this repository.


## Use

Nothing too complicated, just plug the joystick into the 9-pin connector on the side of the box, or plug the paddles into the green bracket (with the lever) on the assembly.
Don't forget to power up via the USB-C port with any charger or computer.\
All that's left to do is manipulate the joystick to see the cross move across the screen.\
If you press one of the two joystick buttons, the LED lights up and the information on the screen changes to “ON”.\
The same applies to the paddles.

Here's a short video to explain how it works:
https://www.youtube.com/watch?v=9ZfeMaLszHQ


## Licence

You can do what you like with it. I could be wrong, but I don't really think that a manufacturer will build this assembly to sell thousands of copies and earn millions of euros or dollars :wink:\
For me, it's been a good and fun experience making this little montage, and that's why I'm making it freely available. 

You can contact me for questions or informations here : https://www.freney.net (-> contact).


