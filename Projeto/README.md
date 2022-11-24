# Versão Serial

Executando o código localizado no arquivo PROJV1-Serial.cpp na AWS com o hardware t3.micro
![image](https://user-images.githubusercontent.com/74461314/196826746-71bc3fc8-fbee-4632-8699-5e48f790e5f2.png)

# Versão Paralela

Executando o código localizado no arquivo PROJV2-Paralela.cpp na AWS com o hardware t3.micro
![image](https://user-images.githubusercontent.com/74461314/196829457-d9901cea-0661-4f37-9285-c0aa41fc29c5.png)

# Projeto V3 Versão Serial com programação dinamica  

1 bilhão de Iterações, tempo Medio de execução = 1m 19,67s

![image](https://user-images.githubusercontent.com/74374381/200983805-faba2c71-9c37-496d-940b-3bdd91491c6b.png)
![image](https://user-images.githubusercontent.com/74374381/200984143-67ba7beb-6eb9-4e64-97c6-6080a90c20c0.png)
![image](https://user-images.githubusercontent.com/74374381/200984325-55340a0c-e54b-485b-9913-8d026fd6f4fb.png)


# Projeto V3 Versão Paralela com programação dinamica e OpenMP

1 bilhão de Iterações,2 Núcleos, tempo Medio de execução = 1m 2,04s

Speedup em relação ao Projeto V3 Versão Serial: 1m 19,67s / 1m 2,04s = 1.17

![image](https://user-images.githubusercontent.com/74374381/200982173-da3dad02-33f3-4ce7-9132-1210c6356cac.png)
![image](https://user-images.githubusercontent.com/74374381/200982379-4bda08e5-4bf7-4682-a08e-1b2595cd085a.png)
![image](https://user-images.githubusercontent.com/74374381/200982536-b73f36c1-6a2d-42dc-a167-bb83aa029152.png)

Grafico do speedup

![image](https://user-images.githubusercontent.com/74374381/200991101-413c0b1c-7929-4137-843f-63e2338af601.png)

# Projeto V4 Versão Final
O principal problema era como conseguir mostrar o maior numero de casas decimais possiveis, ja que o maior tipo de dado do c(double) tem apenas 15 casas decimais.
Para resolver isso usamos a biblioteca gmp

![image](https://user-images.githubusercontent.com/74374381/203760053-f686a646-105c-45b4-8597-aaf78de2ce98.png)

Com ela podemos declarar uma variavel de tamanho arbitrario, limitado apenas pela sua quantidade de memoria

![image](https://user-images.githubusercontent.com/74374381/203760394-9f0dd41a-ca03-4b5c-af19-fed96985508f.png)

a variavel Auxiliar acima apresenta 5000000 bits de memoria.

Sobre o paralelismo, as threads sao totalmente independentes; nos nossos testes usamos 2 threads apenas e elas rodam





