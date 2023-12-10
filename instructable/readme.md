# Instructable voor plan B

Een instructable is een stappenplan - zonder verdere uitleg - hoe je vertrekkend van de bill of materials en gebruik makend van de technische tekeningen de robot kan nabouwen. Ook de nodige stappen om de microcontroller te compileren en te uploaden staan beschreven.  

### stap 1
bestel alle componenten uit de bill of materials  
### stap 2
Leg de breadboards in hun lengte naast elkaar
### stap 3
Zorg nu dat de breadboards aan elkaar hangen met 1 kleiner stuk ertussen
### stap 4
Maak de zijstukken los maar behoud 1 zijstuk op 1 breadboard. Nu moet je een configuratie bekomen van breadboards die gaat; Groot Breadboard - Klein Breadboard - Groot Breadboard.
Die aan elkaar vast hangen.
### stap 5
Je maakt de gele sticker aan de onderkant los. Zodat de onderkant van het breadboard plakkerig wordt.
### stap 6
Je plakt dit breadboard nu op de baseplate tussen de verhogingen en vlak met de achterkant van de baseplate (Niet bij de uitsteeksels).
### stap 7
Je knipt de uitsteeksels af  totdat er nog 4 gaten overblijven op elk uitsteeksel.
### stap 8
Soldeer de draadjes aan de motoren (eventueel knip je een draad in twee)
### stap 9
Je lijmt de motor houders nu vast zodat de palmbomen naar de buitenkant wijzen en ze in hun respectieve hoek zitten.
Dus aan de linker en rechter achterhoek.
### stap 10
Je soldeert de pin headers van de sensor in de rij met 11 gaten naast elkaar met het lange stuk naar boven (het vlak zonder de componenten)
### stap 11
Nu soldeer je de header van de H-brug met het de lange kant naarbeneden (Lange kant naar de kant zonder componenten)
### stap 12
Je bevestigd de sensor met gebruik van lijm aan de onderkant van het uitsteeksel op het 2de gaatje en zodat het lange deel van de headers naar boven steekt en de sensoren naar beneden.
### stap 13
Het kogelwiel bevestig je in het midden van de robot en zodat het de sensor net niet raakt.
### stap 14
Je duwt de wielen op de motoren
### stap 15
Je duwt de motoren in de motorenhouders in een naar buiten wijzende manier todat alleen nog het "gouden" gedeelte uitsteekt.
### stap 16
!Vanaf nu is het perspectief vanuit de achterkant van de robot.
Je plaatst de ESP32 nu vanachter links, zodat nog juist de rechter kan van de esp32 in het rechter breadboard zit. Zorg er ook voor dat de USB micro naar achter uit steekt.
### stap 17
De voltage regulator plaats je nu links van de esp32, op de linker helft van de linker breadboard.
### stap 18
De H-Brug plaats in de rechter boven hoek, met de lange kant van de headers in het breadboard.
### stap 19
Je bevestigd de batterij houder aan Batterij Houder Platform met de Schroefjes en Moeren
### stap 20
Je schuift de Batterij Houder Platform via de voorkant tot dat het vlak is met het baseplate deel
## stap 21
Nu verbindt je alles volgen het elektrisch schema
https://github.com/ThatGuyOliver/Linefollower/blob/main/technische%20tekeningen/elektronisch/PlanB/PlanB_schema.pdf
## stap 22
Eventueel laadt je de batterijen op.
## stap 23
Je zet de schakelaar van de batterij houder op "OFF"
##stap 24
Je installeerd visual studio.
## stap 25
Wanneer je op het startscherm bent, klik op je in de linkerbalk op extensions. 
## stap 26
Je zoekt naar en installeert platform IO
## stap 27
Nu klik op je de alien en wordt platform io gestart. Hierna herload je visual studio.
## stap 28
Je download https://github.com/ThatGuyOliver/Linefollower/blob/main/code/finaal/Line%20Follower.zip
en unzipt dit.
## stap 29
Op visual studio klik je op de Alien op de linker tab en daarna op open project.
Hierbij selecteer je de map met de bestanden die je net unzipt hebt.
Nu wordt dit project ingeladen.
## stap 30
In de explorer tab klik je de map src.
## stap 31
Dan klik je op main.cpp
## stap 32
In deze file zoek je naar de de parameters SSID, PSWD en MyHostNAme.
## stap 33
!Bij deze parameters pas je alleen de tekst tussen de "" aan!
De SSID naar de naam van je WIFI netwerk, PSWD naar het wachtwoord van je Wifi netwerk en Myhostname naar iets van jouw voorkeur.
## stap 34
Nu verbind je de esp32 met je computer door de kabel in de USB micro te verbinden met een USB poort van de computer waarop Visual Studio staat.
## stap 35
Je laadt het programma op op de esp32 door op upload te klikken dit is een knop op onderste balk. De pijl naar rechts.
## stap 36
Je opent de serial command dit is symbool met de stekker.
##stap 37
Wanneer je alles correct hebt gedaan zou hier na enkele seconden het ip van je esp32 verschijnen.
!Deze schrijf je op!
##stap 38
Nu trek je de kabel uit de esp32.
##stap 39
Je steekt de batterijen in de batterijhouder
##stap 40
Je zet de switch aan
