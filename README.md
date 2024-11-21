#Ptit Deck

![Bannière du projet]("D:\IMG_20241115_113932-ezgif.com-webp-to-png-converter.png")

Ptit Deck est un projet de contrôleur de son pour PC qui se base sur un autre projet Github du nom de Deej. Ce petit périphérique permet de contrôler le son des logiciels de son PC par exemple Chrome, Discord, Steam etc... grâce à 3 encodeurs ! Il peut aussi émuler des touches de claviers grâce aux boutons des encodeurs grâce à un Arduino Pro Micro.

## Table des Matières
- [Aperçu](#aperçu)
- [Fonctionnalités](#fonctionnalités)
- [Comment ça fonctionne ? ](#how-it-works)
  - [Hardware](#hardware)
    - [Schéma](#schéma)
- [Utilisation](#utilisation)
- [Personnalisation](#personnalisation)
- [Contribution](#contribution)
- [Licence](#licence)

## Aperçu

![Capture d'écran du clavier](https://github.com/Rogue0neS/Ptit_Deej/blob/main/Image/IMG20241113205654-ezgif.com-webp-to-png-converter.png)


## Fonctionnalités

Voici les fonctionnalités du Ptit Deck

- Contrôle du son Master du PC 
- Contrôle du son de différent application (Chrome, Steam, Discord, etc...)
- Emulation de touches de clavier (ex : Mute, Alt+F4, Ctrl+C Ctrl+V, etc...)
- Affichage d'information sur l'écran OLED de 1.2"
- 3 Leds ARGB avec enregistrement de leur état sur l'EEPROM de l'Arduino Pro Micro

## Comment ça fonctionne ?

### Hardware

Voici la liste des composants pour récréer ce projet :

-1* Arduino Pro Micro
-3* Encoders
-1* Ecran OLED 1.2"
-3* LED WS2812B
-Fils électrique
-Boîtier en impression 3D

### Schéma

Voici le schéma de cablâge du projet :

![Schéma de cablage]("D:\Schéma_Ptit_Deck.drawio.png")
