# Instructable voor plan B

Een instructable is een stappenplan - zonder verdere uitleg - hoe je vertrekkend van de bill of materials en gebruik makend van de technische tekeningen de robot kan nabouwen. Ook de nodige stappen om de microcontroller te compileren en te uploaden staan beschreven.  

### stap 1
bestel alle componenten uit de bill of materials  
### stap 2
Leg de breadboards in hun lengte naast elkaar
### stap 3
Zorg nu dat de breadboards aan elkaar hangen met 1 kleiner stuk ertussen
### stap 4
Maak de zijstukken los, nu bekom je een configuratie van breadboards van Groot Breadboard - Klein Breadboard - Groot Breadboard.
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
### stap 10
Je soldeert de pin headers in de sensor met het lange stuk naar boven (het vlak zonder de componenten) en in de rij met 11 gaten naast elkaar
### stap 11
Nu soldeer je de header met het de lange kant naarbeneden (Lange kant naar de kant zonder componenten)
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
##stap 25
Wanneer je op het startscherm bent, klik op je in de linkerbalk op extensions. 
##stap 26
Je zoekt naar en installeert platform IO
##stap 27
Nu klik op je de alien en wordt platform io gestart. Hierna herload je visual studio.
##stap 28
Hierbij selecteer je de az-delivery-devkit-v4 op het plaform espressif32 met het framework van Arduino.
##stap 26
Maak een nieuwe project aan.
##stap 26
Je download main.zip
https://github.com/ThatGuyOliver/Linefollower/blob/main/code/finaal/main.zip
##stap 27
Je unzipt deze bestanden en plaatst ze op een plek waar je aan kan.
##stap 28
In de explorer tab ga je naar je project.
##stap 29
Je plaatst de Telnet command files in de include en de main in de Src.
##stap 30
Je gaat naar PIO Home
##stap 31
Je klikt op libraries
##stap 32
Je zoekt naat de wifi

##stap 
In de main code pas je de parameters SSID, PSWD en MyHostNAme aan naar de correcte parameters
De SSID naar de naam van je WIFI, PSWD naar het wachtwoord van je netwerk en Myhostname iets naar jouw voorkeur.
Dit doe je in Visual Studio.
## stap 25
Nu verbindt je de esp32 met je computer door de kabel in de USB micro te verbinden met een USB poort van de computer waarop Visual Studio staat.
## stap 26
Je laadt het programma op op de esp32 door op upload te klikken dit is een knop op onderste balk.
## stap 27
Je opent de serial command dit is symbool met de 
