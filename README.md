# Ptit Deck

![Bannière du projet](https://github.com/Rogue0neS/Ptit_Deej/blob/main/Image/IMG_20241115_113932-ezgif.com-webp-to-png-converter.png)

Ptit Deck est un projet de contrôleur de son pour PC qui se base sur un autre projet Github du nom de [Deej](https://github.com/omriharel/deej). Ce petit périphérique permet de contrôler le son des logiciels de son PC par exemple Chrome, Discord, Steam etc... grâce à 3 encodeurs ! Il peut aussi émuler des touches de claviers grâce aux boutons des encodeurs grâce à un Arduino Pro Micro.

## Table des Matières
- [Aperçu](#aperçu)
- [Fonctionnalités](#fonctionnalités)
- [Comment ça fonctionne ? ](#how-it-works)
  - [Hardware](#hardware)
    - [Schéma](#schéma)
- [Fonctionnement](#utilisation)
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

- 1* [Arduino Pro Micro](https://fr.aliexpress.com/item/1005007344997490.html?spm=a2g0o.productlist.main.1.273eY14jY14jRo&algo_pvid=0fc8494b-7e6a-483b-9a76-f03b6d2d3b88&algo_exp_id=0fc8494b-7e6a-483b-9a76-f03b6d2d3b88-0&pdp_npi=4%40dis%21EUR%2112.60%216.30%21%21%2194.02%2147.01%21%402103890917322087676977886ee431%2112000040353942248%21sea%21RE%212248866871%21X&curPageLogUid=U7RpGUphRdin&utparam-url=scene%3Asearch%7Cquery_from%3A)
- 3* [Encoders](https://fr.aliexpress.com/item/1005004428157989.html?spm=a2g0o.productlist.main.5.2d5f5e710fElG0&algo_pvid=a2517023-5090-419f-8db0-c8981c49e6e6&algo_exp_id=a2517023-5090-419f-8db0-c8981c49e6e6-2&pdp_npi=4%40dis%21EUR%211.85%211.57%21%21%211.91%211.62%21%40211b80f717322088141608303e21c4%2112000029151962175%21sea%21RE%212248866871%21X&curPageLogUid=hcUkJx7oeP6D&utparam-url=scene%3Asearch%7Cquery_from%3A)
- 1* [Ecran OLED 1.2"](https://fr.aliexpress.com/item/1005004355547926.html?spm=a2g0o.productlist.main.1.5c0574d4aSpLyn&algo_pvid=1361eb8e-40bf-4f53-9ff6-7d59b8226b79&algo_exp_id=1361eb8e-40bf-4f53-9ff6-7d59b8226b79-0&pdp_npi=4%40dis%21EUR%211.21%211.21%21%21%211.25%211.25%21%40211b80f717322088542461418e21c4%2112000029444147546%21sea%21RE%212248866871%21X&curPageLogUid=WplzHR74HPfk&utparam-url=scene%3Asearch%7Cquery_from%3A)
- 3* [LED WS2812B](https://fr.aliexpress.com/item/2036819167.html?spm=a2g0o.productlist.main.1.2c504d1bk205P0&algo_pvid=b3ffcc70-accb-4e9c-abca-3b19428af1f3&algo_exp_id=b3ffcc70-accb-4e9c-abca-3b19428af1f3-0&pdp_npi=4%40dis%21EUR%214.49%213.14%21%21%214.63%213.24%21%40211b617b17322088738071086ed391%2112000033705280747%21sea%21RE%212248866871%21X&curPageLogUid=9fMYF4K9XVti&utparam-url=scene%3Asearch%7Cquery_from%3A)
- Fils électrique
- Boîtier en impression 3D

### Schéma

Voici le schéma de cablâge du projet :

![Schéma de cablage](https://github.com/Rogue0neS/Ptit_Deej/blob/main/Image/Sch%C3%A9ma_Ptit_Deck.drawio.png)

## Fonctionnement

Le Ptit Deck possède 3 modes de fonctionnement :
- Le premier mode permet de contrôler le son de son PC grâce aux 3 encoders, il permet aussi d'utiliser des raccourcis clavier.
- Le second mode permet d'avoir encore plus de raccourcis clavier mais ne permet pas le contrôle du son.
- Le dernier mode permet de contrôler les LED ARGB. Pour changer de paramètre il suffit d'appuyer sur le deuxième encoder. Dans la première page on peut contrôler la luminosité grâce au premier encoder et les autres pages permettent d'appliquer des couleurs customiser grâce aux 3 encoders qui modifie respectivement les couleurs RGB de la LED selectionné .

## Galerie

Voici une galerie d'image du Ptit Deck. [Galerie d'image](https://github.com/Rogue0neS/Ptit_Deck/tree/main/Image)

## Licence

Ptit Deej est sous la [licence MIT](./LICENSE).
