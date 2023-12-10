# Instructable voor plan B

Een instructable is een stappenplan - zonder verdere uitleg - hoe je vertrekkend van de bill of materials en gebruik makend van de technische tekeningen de robot kan nabouwen. Ook de nodige stappen om de microcontroller te compileren en te uploaden staan beschreven.  

## stap 1
Bestel alle componenten uit de bill of materials  
## stap 2
Leg de breadboards in de lengte naast elkaar.
## stap 3
Maak de zijstukken los, maar behoud één zijstuk op één breadboard.
## stap 4
Nu moet je een configuratie verkrijgen van breadboards zoals volgt: Groot Breadboard - Klein Breadboard - Groot Breadboard. Hang deze breadboards aan elkaar.
## stap 5
Verwijder de gele sticker aan de onderkant van het breadboard, zodat de onderkant plakkerig wordt.
## stap 6
Plak dit breadboard nu op de baseplate tussen de verhogingen en vlak met de achterkant van de baseplate (Niet bij de uitsteeksels).
## stap 7
Knip de uitsteeksels af totdat er nog 4 gaten overblijven op elk uitsteeksel.
## stap 8
Soldeer de draadjes aan de motoren (eventueel knip je een draad in twee).
## stap 9
Lijm de motorhouders nu vast zodat de palmbomen naar buiten wijzen en ze in hun respectieve hoek zitten, dus aan de linker en rechter achterhoek.
### stap 10
Soldeer de pin headers van de sensor in de rij met 11 gaten naast elkaar, met het lange stuk naar boven (het vlak zonder de componenten).
## stap 11
Soldeer de header van de H-brug met de lange kant naar beneden (lange kant naar de kant zonder componenten).
## stap 12
Bevestig de sensor module met behulp van lijm aan de onderkant van het uitsteeksel op het tweede gaatje. Zorg ervoor dat het lange deel van de headers naar boven steekt en de sensoren naar beneden wijzen.
## stap 13
Bevestig het kogelwiel in het midden van de robot, zodat het de sensor net niet raakt.
### stap 14
Duw de wielen op de motoren.
## stap 15
Duw de motoren in de motorenhouders (op een naar buiten wijzende manier) totdat alleen nog het "gouden" gedeelte van de motor uitsteekt.
## stap 16
!Vanaf nu is het perspectief vanuit de achterkant van de robot.!
Plaats de ESP32 met de micro USB naar achteren tegen de rand en over het kleine breadboard, zodat de linker pins zich op het linker breadboard bevinden en de rechter pins op het rechter breadboard.
## stap 17
Plaats de voltage regulator in de lengte, links van de ESP32, op de linker helft van het linker breadboard.
## stap 18
Plaats de H-Brug in de rechter bovenhoek, met de lange kant van de headers in het breadboard. Zorg ervoor dat hij over de gleuf staat, zodat de twee kanten niet op hetzelfde deel staan.
## stap 19
Bevestig de batterijhouder aan het Batterij Houder Platform met behulp van de schroefjes en moeren. Plaats de batterijhouder zodat de draadjes aan de linkerkant terechtkomen in de volgende stap.
## stap 20
Schuif de Batterij Houder Platform via de voorkant tot het vlak is met het baseplate deel.
## stap 21
Verbind nu alle draden volgens het elektrisch schema:
https://github.com/ThatGuyOliver/Linefollower/blob/main/technische%20tekeningen/elektronisch/PlanB/PlanB_schema.pdf
Je kan eventueel plakband gebruiken als de kabels niet goed zijn.
## stap 22
Eventueel laad je de batterijen op.
## stap 23
Zet de schakelaar van de batterijhouder op "OFF".
## stap 24
Installeer Visual Studio Code op je computer.
https://code.visualstudio.com/download
## stap 25
Wanneer je op het startscherm bent, klik je in de linkerbalk op extensions.
## stap 26
Zoek naar en installeer Platform IO.
## stap 27
Nu klik je op de alien en wordt Platform IO gestart. Hierna herlaad je Visual Studio.
## stap 28
Download deze zip en unzip naar een bereikbare locatie.
https://github.com/ThatGuyOliver/Linefollower/blob/main/code/finaal/Line%20Follower.zip
## stap 29
In Visual Studio klik je op de Alien op de linker tab en daarna op open project. 
Selecteer de map met de bestanden die je net hebt uitgepakt. Wacht tot het project is ingeladen.
## stap 30
In de explorer tab klik je de folder src open.
## stap 31
Klik vervolgens op main.cpp.
## stap 32
In deze file zoek je naar de parameters SSID, PSWD en MyHostName.
## stap 33
!Bij deze parameters pas je alleen de tekst tussen de "aanhalingstekens" aan!
De SSID naar de naam van je WIFI netwerk, PSWD naar het wachtwoord van je Wifi netwerk en Myhostname naar iets van jouw voorkeur.
## stap 34
Nu verbind je de ESP32 met je computer door de kabel in de USB micro te verbinden met een USB-poort van de computer waarop Visual Studio staat.
## stap 35
Je download en unzipt https://github.com/ThatGuyOliver/Linefollower/blob/main/instructable/CP210x_Universal_Windows_Driver.zip
Dit is de driver voor de esp32.
## stap 36
Nu installeer je deze driver, dit is afhankelijk van platform tot platform.
## stap 37
Na een succesvolle installatie herstart je best Visual Studio Code en sluit je de ESP32 opnieuw aan.
## stap 38
Keer terug naar het project.
## stap 39
Laad het programma op de ESP32 door op 'upload' te klikken (dit is een knop op de onderste balk, de pijl naar rechts).
## stap 40
Na een succesvolle upload open je de serial monitor, dit is het symbool met de stekker.
## stap 41
Wanneer je alles correct hebt gedaan, zou hier na enkele seconden het IP van je ESP32 verschijnen. !Noteer dit.!
## stap 42
Nu trek je de kabel uit de ESP32.
## stap 43
Plaats de batterijen in de batterijhouder.
Als deze nog niet open is, dan schuif je er eerst het deksel eraf. 
## stap 44
Schuif het deksel er weer op.
## stap 45
Zet de schakelaar van de batterijhouder op 'ON'.
