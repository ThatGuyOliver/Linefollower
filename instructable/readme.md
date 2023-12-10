# Instructable voor plan B

Een instructable is een stappenplan - zonder verdere uitleg - hoe je vertrekkend van de bill of materials en gebruik makend van de technische tekeningen de robot kan nabouwen. Ook de nodige stappen om de microcontroller te compileren en te uploaden staan beschreven.  

## stap 1
Bestel alle componenten uit de bill of materials  
## stap 2
Leg de breadboards in hun lengte naast elkaar
## stap 3
Maak de zijstukken los, maar behoud één zijstuk op één breadboard.
## stap 4
Nu moet je een configuratie verkrijgen van breadboards zoals volgt: Groot Breadboard - Klein Breadboard - Groot Breadboard. Deze breadboards hang je vast aan elkaar.
## stap 5
Verwijder de gele sticker aan de onderkant van het breadboard, zodat de onderkant plakkerig wordt.
## stap 6
Je plakt dit breadboard nu op de baseplate tussen de verhogingen en vlak met de achterkant van de baseplate (Niet bij de uitsteeksels).
## stap 7
Je knipt de uitsteeksels af  totdat er nog 4 gaten overblijven op elk uitsteeksel.
## stap 8
Soldeer de draadjes aan de motoren (eventueel knip je een draad in twee)
## stap 9
Je lijmt de motor houders nu vast zodat de palmbomen naar de buitenkant wijzen en ze in hun respectieve hoek zitten.
Dus aan de linker en rechter achterhoek.
### stap 10
Je soldeert de pin headers van de sensor, in de rij met 11 gaten naast elkaar, met het lange stuk naar boven (het vlak zonder de componenten)
## stap 11
Nu soldeer je de header van de H-brug met het de lange kant naarbeneden (Lange kant naar de kant zonder componenten)
## stap 12
Je bevestigt de sensor module met behulp van lijm aan de onderkant van het uitsteeksel op het tweede gaatje, zorg ervoor dat het lange deel van de headers naar boven steekt en de sensoren naar beneden wijzen.
## stap 13
Het kogelwiel bevestig je in het midden van de robot en zodat het de sensor net niet raakt.
### stap 14
Je duwt de wielen op de motoren
## stap 15
Je duwt de motoren in de motorenhouders (in een naar buiten wijzende manier) todat alleen nog het "gouden" gedeelte van de motor uitsteekt.
## stap 16
!Vanaf nu is het perspectief vanuit de achterkant van de robot.
Je plaatst de ESP32 met de micro USB naar achter tegen de radnd en over het kleine breadboard, zodat de linker pins zich op het linker breadboard bevinden en de rechter pins op het rechter breadboard.
## stap 17
De voltage regulator plaats je nu in de lengte, links van de esp32, op de linker helft van de linker breadboard.
## stap 18
De H-Brug plaats in de rechter boven hoek, met de lange kant van de headers in het breadboard. En je zorgt ervoor dat hij over de gleuf staat zodat de 2 kanten niet op hetzelfde deel staan.
## stap 19
Bevestig de batterijhouder aan het Batterij Houder Platform met behulp van de schroefjes en moeren. Plaats de batterijhouder zodat de draadjes aan de linkerkant terechtkomen in de volgende stap
## stap 20
Je schuift de Batterij Houder Platform via de voorkant tot dat die vlak is met het baseplate deel.
## stap 21
Nu verbind je alle draden volgens het elektrisch schema
https://github.com/ThatGuyOliver/Linefollower/blob/main/technische%20tekeningen/elektronisch/PlanB/PlanB_schema.pdf
## stap 22
Eventueel laad je de batterijen op.
## stap 23
Je zet de schakelaar van de batterij houder op "OFF"
## stap 24
Je installeerd visual studio op je computer
## stap 25
Wanneer je op het startscherm bent, klik je in de linkerbalk op extensions. 
## stap 26
Je zoekt naar en installeerd Platform IO
## stap 27
Nu klik op je de alien en wordt platform io gestart. Hierna herlaad je visual studio.
## stap 28
Je download https://github.com/ThatGuyOliver/Linefollower/blob/main/code/finaal/Line%20Follower.zip
en unzipt dit.
## stap 29
Op visual studio klik je op de Alien op de linker tab en daarna op open project.
Hierbij selecteer je de map met de bestanden die je net unzipt hebt.
Nu wordt dit project ingeladen dus wacht je tot dit wordt voltooid.
## stap 30
In de explorer tab klik je de folder src open.
## stap 31
Klik vervolgens op main.cpp.
## stap 32
In deze file zoek je naar de de parameters SSID, PSWD en MyHostName.
## stap 33
!Bij deze parameters pas je alleen de tekst tussen de "aanhalingstekens" aan!
De SSID naar de naam van je WIFI netwerk, PSWD naar het wachtwoord van je Wifi netwerk en Myhostname naar iets van jouw voorkeur.
## stap 34
Nu verbind je de esp32 met je computer door de kabel in de USB micro te verbinden met een USB poort van de computer waarop Visual Studio staat.
## stap 35
Je download en unzipt https://github.com/ThatGuyOliver/Linefollower/blob/main/instructable/CP210x_Universal_Windows_Driver.zip
Dit is de driver voor de esp32.
## stap 36
Nu installeer je deze driver, dit is afhankelijk van platform tot platform.
## stap 37
Na een succesvolle installatie herstart je best visual studio en je sluit je de esp32 opnieuw aan.
## stap 38
Je keert terug naar het project
## stap 39
Je laadt het programma op op de esp32 door op upload te klikken (dit is een knop op onderste balk, de pijl naar rechts.)
## stap 40
Na een succesvolle upload open je de de serial monitor, dit is het symbool met de stekker.
## stap 41
Wanneer je alles correct hebt gedaan zou hier na enkele seconden het ip van je esp32 verschijnen.
!Deze schrijf je op!
## stap 42
Nu trek je de kabel uit de esp32.
## stap 43
Plaats de batterijen in de batterijhouder.
## stap 44
Je zet de switch van de batterihouder op ON
