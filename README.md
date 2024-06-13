# Merjenje-kapacitivnosti-z-Arduino
 
Opis delovanja/koncepta meritve in naprave:
Naloga merjenja kapacitivnosti z Arduino vključuje uporabo mikrokrmilnika Arduino za določanje vrednosti kapacitivnosti kondenzatorja. Postopek običajno vključuje uporabo Arduino mikrokrmilnika skupaj z zunanjim vezjem, ki omogoča merjenje spremembe napetosti na kondenzatorju.
Prvi korak je priprava vezja, ki vključuje kondenzator, upor in Arduino mikrokrmilnik. Nato se kondenzator napolni z določeno napetostjo in Arduino beleži čas, ki je potreben za napolnitev kondenzatorja do določene napetosti. Na podlagi tega časa je mogoče izračunati vrednost kapacitivnosti kondenzatorja.
Naloga merjenja kapacitivnosti z Arduino lahko vključuje tudi uporabo posebnih knjižnic in programov za izračun vrednosti kapacitivnosti. Ta naloga je pomembna pri razvoju elektronskih naprav, saj omogoča natančno določanje vrednosti kapacitivnosti kondenzatorjev, ki se uporabljajo v električnih vezjih.


# KOSOVNICA:

|Uporabljen predmet|Št. kosov|
|---|---|
|Arduino UNO R3|   1   |
|Protoboard|   1   |
|Upori|   2   |
|Kondenzator|   n št. kondenzatorjev   |
|I2C LCD zaslon|   1   |
|Digitalni merilnik kapacitivnosti|   1   |
|Žičke|   6-10   |

# Vezalna shema:

![image](https://github.com/NoSiht/Merjenje-kapacitivnosti-z-Arduino/assets/161247741/e58da991-aab1-420e-b7c2-e1e0fd61614b)

# Komentar vezja:
10 kΩ upor vzamemo za računanje neznanih kondenzatorjev. Lahko bi uporabili tudi drugačen upor, ampak bi morali tudi dodelati kodo, da lahko računa s tem uporom.
220 Ω upor uporabimo za stabilizacijo vezja.

# Skica ohišja:
![image](https://github.com/NoSiht/Merjenje-kapacitivnosti-z-Arduino/assets/161247741/7ea2c81a-83ab-462a-9bec-480ca04d0f48)

# Komentar in tabela meritev:
### Arduino:
|      | Odčitana vrednost | Izmerjena vrednost |
|---|---|---|
|1.| 330 nF | 359 nF |
|2.| 47 nF | 45 nF |
|3.| 22 uF | 27 uF |
|4.| 47 uF | 45,2 nF |
|5.| 1 uF | 1,03 uF |

### Merilni inštrument:
|      | Odčitana vrednost | Izmerjena vrednost |
|---|---|---|
|1.| 330 nF | 359 nF |
|2.| 47 nF | 46,1 nF |
|3.| 22 uF | 24,5 uF |
|4.| 47 uF | 43,3 uF |
|5.| 1 uF | 1,03 uF |

### Komentar:
Natančnost meritev: Arduino in merilni inštrument sta pri večini meritev dokaj natančna, še posebej pri manjših vrednostih.
Odstopanja: Večja odstopanja so prisotna pri večjih kapacitetah (22 µF in več), kjer Arduino kaže nekoliko večje razlike kot merilni inštrument.
Skladnost: Obe napravi kažeta skladne rezultate pri merjenju manjših kapacitet (npr. 330 nF).

# Komentar na delovanje naprave:

### Komponente in povezave:
1. Arduino Uno: Uporablja se za merjenje kapacitivnosti.
2. LCD zaslon (HD44780 + I2C modul): Uporablja se za prikaz rezultatov meritev.
3. Upor R1 (10k) in R2 (220 ohm): Vezani v vezje za pravilno delovanje.
4. Kondenzator C1: Kondenzator, ki ga merimo.

### Delovanje vezja:
1. Polnjenje in praznjenje kondenzatorja:
  - R1 (10k ohm) in C1 tvorita RC vezje, kjer se kondenzator polni in prazni preko upora.
  - Arduino meri čas, ki je potreben, da se kondenzator napolni do določene napetosti (npr. 63.2% polne napetosti), kar ustreza časovni konstanti RC.
2. Povezave z LCD zaslonom:
  - SDA in SCL pini Arduina so povezani z ustreznimi pini na I2C modulu LCD zaslona.
  - To omogoča, da Arduino pošilja rezultate meritev na zaslon preko I2C komunikacije.

### Postopek merjenja:
1. Inicializacija: Arduino inicializira LCD zaslon in pripravi vhodne/izhodne pine.
2. Polnjenje kondenzatorja:
  - Arduino nastavi pin na HIGH, kar omogoča, da se kondenzator začne polniti preko upora R1.
  - Meri čas, potreben, da napetost na kondenzatorju doseže 63.2% napajalne napetosti (običajno 5V).
3. Izračuno kapacitivnosti:
  - Arduino porabi izmerjen čas in znano vrednost upora R1 za izračun kapacitivnosti: C = t/R.
4. Prikaz rezultata:
  - Izračunano vrednost kapacitivnosti prikaže na LCD zaslonu.

### Zaključek:
To vezje omogoča merjenje kapacitivnosti z Arduinom preko polnjenja in praznjenja kondenzatorja v RC vezju in merjenja časa, potrebnega za dosego določene napetosti. Natančnost meritev je odvisna od natančnosti uporabljenih komponent in merilne tehnike. Prikazovanje rezultatov na LCD zaslonu omogoča enostavno spremljanje meritev v realnem času.
