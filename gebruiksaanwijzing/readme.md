# Gebruiksaanwijzing

## opladen / vervangen batterijen
uitleg over het opladen of vervangen van de batterijen

### Opladen
Dit zijn li-ion batterijen van het type 18650.
Deze batterijen laad je best op voor en na een sessie.
Wanneer tijdens een sessie een verminderde prestatie wordt geleverd kan je dan ook best de batterijen opladen.
Voor het opladen van deze batterijen heb je een speciale lader nodig en wordt het ten zeerste afgeraden om een niet geschikte oplaadmethode te gebruiken.

### Vervangen batterijen
Zorg dat de batterijen in de correcte oriëntatie in de batterijhouder gestoken worden. En vergeet het deksel niet terug te plaatsen
Er wordt ook zeker aangeraden dat wanneer je deze batterijen vervangt, je ze afgeeft bij een geschikt inzamelings punt.


## draadloze communicatie
### verbinding maken
uitleg over het verbinden van de robot met laptop / smartphone
#### 1: Putty (op computer)
1.Verbind met hetzelde Wifi netwerk als de esp32
1.1. Het netwerk waarmee de esp32 wordt bepaald wordt bepaald in de main.cpp file.
2. Hostname: zelf gekozen hostname/ip esp32
2.1 Hostname wordt gekozen in main.cpp file
3. Port:  23
4. Connection type: Other: Telnet
#### 2: App IOS Termius
1.Verbind met hetzelde Wifi netwerk als de esp32
2. Navigeer naar Hosts tab
3. Klik op + in de linker hoek
4. New host
5. Hostname 
5.1 Hostname: zelf gekozen hostname 
6. Schakel Use SSH uit
7. Schakel Use Telnet aan
8. Save 
9. Klik nu op de net aangemaakte host

### commando's
debug; Stuurt alle ingestelde parameters en berekende calculation time terug
run; Start of stopt de robot 
set cycle [µs]  Stelt de cycle time in van de robot
set power [0..255] Stelt de maximum power van de robot in
set diff [0..1] 
set kp [0..] Stelt de propertionele correctie van de fout in 
set ki [0..] Stelt de integrale correctie van de fout in 
set kd [0..] Stelt de differentiële correctie van de fout in  
calibrate black  Stelt de waardes gelezen door de sensor in als zwart.
calibrate white Stelt de waardes gelezen door de sensor in als wit.

## kalibratie
uitleg kalibratie  
Er moet worden gekalibreerd omdat er een verschil is tussen de verschillende sensoren, door een tolerantie op de onderdelen, wat eigen is aan productie.

Commando: calibrate black
Wanneer je dit commando stuurt over telnet wordt de reflectie van het opppervlakte waarover de sensor module op dat moment hangt opgeslagen
per sensor opgeslagen als een zwart waarde.
Commando: calibrate white
Wanneer je dit commando stuurt over telnet wordt de reflectie van het opppervlakte waarover de sensor module op dat moment hangt opgeslagen
per sensor opgeslagen als een wit waarde.

Deze waardes worden dan gebruikt om te vergelijken met de huidig gedetecteerd oppervlakte ofdat het een wit of zwart oppervlakte is.
Het is belangrijk dat je deze commandos opnieuw uitvoerd wanneer je van omgeving verandert zodat er correct kan gedetecteerd kan worden.

## settings
De robot rijdt stabiel met volgende parameters:  
#### cycle time: 2500
#### power: 80
#### Diff: 0.10
#### Kp: 30
#### Ki: 0
#### Kd: 1.00
