# GS-EDGE

 Sistema de Monitoramento de Alagamentos
Este protótipo é um sistema de monitoramento de alagamentos desenvolvido com Arduino Uno. Ele utiliza sensores para medir o nível da água e detectar presença de chuva, exibindo os resultados em um display LCD 16x2. O sistema também aciona LEDs e um buzzer para alertar o usuário sobre a gravidade da situação.

  Funcionalidade:
Nível Baixo (Normal):
LED verde aceso
Nenhum alerta sonoro

Nível Médio (Atenção):
LED amarelo aceso
Sem buzzer

Nível Alto (Alerta):
LED vermelho aceso
Buzzer ligado continuamente

O valor da chuva também é exibido no LCD como um indicativo visual (chuva ou sol), mas não interfere no alerta – que depende apenas da elevação do nível de água.

📺 LCD:
Na inicialização, o display mostra uma mensagem e o título do sistema. Em seguida, exibe constantemente:

Linha 1: Nível da água (%)

Linha 2: Intensidade da chuva (%)

⚙️ Dependências:
Arduino IDE (v1.8+ ou 2.0+)
Biblioteca padrão LiquidCrystal (inclusa no Arduino IDE)
Placa Arduino Uno ou compatível

🛠️ Componentes Utilizados:
1 × Arduino Uno

1 × Sensor de Nível de Água (ou potenciômetro simulando)

1 × Sensor de Chuva (ou potenciômetro simulando)

1 × Display LCD 16x2

3 × LEDs (verde, amarelo, vermelho)

1 × Buzzer piezoelétrico

4 × Resistores (LEDs e LCD)

1 × Protoboard

Cabos jumpers

   Como Reproduzir:
Clonar o repositório => https://github.com/GS-WebDev-FrontEnd/GS-EDGE 

Abrir o projeto:
Abra o arquivo .ino com o Arduino IDE.

Simular o Projeto:
Use a plataforma Wokwi para fazer a simulação.

  Demonstração:
Assista ao vídeo explicativo, mostrando o funcionamento do sistema, desafios enfrentados e como foram resolvidos:


