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
|4.| 47 uF | 43,3 nF |
|5.| 1 uF | 1,03 uF |

### Komentar:
Natančnost meritev: Arduino in merilni inštrument sta pri večini meritev dokaj natančna, še posebej pri manjših vrednostih kapacitet.
Odstopanja: Večja odstopanja so prisotna pri večjih kapacitetah (22 µF in več), kjer Arduino kaže nekoliko večje razlike kot merilni inštrument.
Možne napake: Pri meritvi 47 µF so verjetno prisotne napake, saj izmerjene vrednosti ne ustrezajo realni vrednosti kondenzatorja.
Skladnost: Obe napravi kažeta skladne rezultate pri merjenju manjših kapacitet (npr. 330 nF).
