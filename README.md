# cadeado Eletrônico com Leitor RFID

Projeto desenvolvido como parte do curso técnico em Eletrônica de 2020 a 2022, com o objetivo de aplicar na prática os conhecimentos adquiridos em sensores, controle com Arduino, eletrônica básica e automação.

## 🔐 Descrição

Criamos um **cadeado eletrônico com controle por RFID**, utilizando um **display LCD**, **trava solenoide**, **Arduino** e uma **fonte de 12V**. O projeto foi montado em formato de **cofre**, para tornar o funcionamento mais visual e interativo.

### 🧠 Lógica do Sistema

- Ao iniciar, o sistema exibe no display:  
  `"Bem-vindo, por favor, aproxime o cartão"`

- Quando um cartão RFID é aproximado:
  - **Se for autorizado:** a trava é liberada e o display mostra `"Olá, bem vindo!!"`
  - **Se for negado:** o sistema exibe `"Não autorizado!!"`

- O sistema aguarda **3 segundos** antes de fechar a trava novamente, garantindo tempo para abertura e segurança no fechamento.

## ⚙️ Componentes Utilizados

- 🔄 **Arduino UNO ou ESP32**
- 🔒 **Trava solenoide**
- 💳 **Leitor RFID RC522**
- 📟 **Display LCD 16x2 com I2C**
- 🔌 **Fonte de 12V**
- 🧠 **Jumpers, resistores, protoboard etc.**

## 🛠️ Tecnologias e Bibliotecas

- **Arduino IDE**
- Bibliotecas:
  - `LiquidCrystal_I2C`
  - `Wire.h`
  - `SPI.h`
  - `MFRC522.h`

## 🗃️ Estrutura do Código

- Definição de IDs autorizados
- Comunicação via I2C e SPI
- Controle da trava com `digitalWrite`
- Leitura do cartão com `mfrc522.PICC_ReadCardSerial`
- Verificação de acesso e mensagens no display

## 📸 Demonstração


![gif do projeto](./imagens/IMG_8924.gif)

## 👥 Equipe

Projeto realizado por 
- Lara Ewellen De Carvalho Rocha.
- Leonan Teixeira De Jesus.
- Kayke Andrade Dantas.
- Ana Eliza Moreira Santos Rodrigues.
- Leticia Coelho Brito.
- Pedro Henrique Sousa Aguiar.

do curso técnico em Eletrônica do **Instituto Federal de Brasília (IFB)**.

## 🧾 Licença

Este projeto é livre para fins acadêmicos e educacionais. Sinta-se à vontade para adaptar e melhorar!

---

> _“Tecnologia acessível e aplicada: cada componente, uma possibilidade; cada linha de código, uma solução.”_
