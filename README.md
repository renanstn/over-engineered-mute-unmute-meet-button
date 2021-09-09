# over-engineered-mute-unmute-meet-button

[![Python](https://img.shields.io/badge/python-%2314354C.svg?style=flat&logo=python&logoColor=white)](https://www.python.org/)
[![Flask](https://img.shields.io/badge/flask-%23000.svg?style=flat&logo=flask&logoColor=white)](https://flask.palletsprojects.com/en/2.0.x/)
[![Arduino](https://img.shields.io/badge/-Arduino-00979D?style=flat&logo=Arduino&logoColor=white)](https://www.arduino.cc/)

## Que p**** é essa?

Incrível e absolutamente desnecessário dispositivo de controle remoto que muta/desmuta uma chamada no Google Meet através da rede local. _Overcomplicado,_ porém muito estiloso! :sunglasses:

<img src="images/front.jpg" height="500"/> <img src="images/side.jpg" height="500"/>

## Como funciona?

- Metade da magia está ao enviar uma request POST usando a placa ESP32 conectada no wifi local
- A outra metade é um servidorzinho [Flask](https://flask.palletsprojects.com/en/2.0.x/) que escuta essas requests e usa a lib `keyboard` para dar `ctrl+d` na máquina

Funciona também se você pegar o seu mouse e simplesmente _clicar no botão_ de unmute, mas aposto que seu mouse não é tão legal quanto esse troço! :shipit:
