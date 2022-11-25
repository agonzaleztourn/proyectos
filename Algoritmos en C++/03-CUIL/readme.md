# Algoritmos-y-Estructuras-de-Datos

Integrantes:

- Conte, Hernan Antonio
- Desiderioscioli, Tomas
- Gonzalez Tourn Agustina
- Mamani Inca, Anthony Emanuel
- Marino, Ezequiel Matias
- Maunus, John-fritz

---

*Definición de CUIL*: Es un número de identificación que brinda ANSES para registrar tus aportes jubilatorios, acceder a las Asignaciones Familiares y realizar trámites en otras entidades públicas, bancos, registros de automotor, entre otros.
El CUIL consta de 11 dígitos. Los dos primeros dígitos se corresponden al sexo informado en el DNI del usuario, los ochos siguientes al DNI y el último dígito se calcula a partir de los 10 anteriores (dígito verificador).

---


## Modelo IPO:

OBJETIVO: DETERMINAR EL CUIL PARA UNA PERSONA FISICA

ENTRADA: 

- DNI
- Sexo

SALIDA:

- CUIL

--- 
## DEFINICION DEL PROBLEMA
---
Se quiere obtener como salida el CUIL de una persona física. Se necesita como entrada para esto el DNI del usuario y su sexo como figura en el mismo para realizar un un cálculo que determine el dígito verificador. En resumen, se necesitan dos entradas (DNI, Sexo) para obtener una salida (CUIL). 
Restricciones: El problema se limita a la obtención del CUIL para personas físicas y que inicien con los valores "20" y "27" según el sexo. 

---
## Solución
---
Nuestro programa debe solicitarle al usuario su sexo y su DNI a fin de resolver el problema.
Para devolver el CUIL utilizará una funcion llamada ObtenerCuil.

---
### Interacción con el usuario


El usuario debe ingresar su sexo y DNI. En el caso del sexo solamente se contemplan las opciones F para femenino y M para masculino, el programa no va a seguir hasta que alguna de esas opciones sea ingresada. En el caso del DNI debe ingresar un número de 8 cifras obligatoriamente. Para documentos menores a 10 millones, debe agregar un cero adelante.


---
### Variables


**DNI**: tipo string. 

**Sexo**: utilizamos un enumerador estructurado que tome los valores Femenino y Masculino. Para obtener el dato del usuario utilizaremos una variable del tipo Char que sólo puede tomar los valores F y M.

---
### Función principal


Prototipo de la funcion **ObtenerCuil**: toma dos valores: DNI de tipo string y sexo del tipo estructurado Sexo y devuelve un string que se corresponde al cuil. 
Para Sexo==Femenino, agrega "27" al cuil. Caso contrario un "20".
Posteriormente concatena el string DNI. En este punto el string cuil tiene 10 caracteres. Finalmente concatena el dígito verificador luego de calcularlo.
Precondiciones: Debe recibir el DNI formado por dígitos y de longitud=8. Sexo = tipo de dato Sexo. Para cumplir con estas condiciones se utilizan funciones que validen los datos ingresados.
Postcondiciones: Debe devolver el CUIL de 11 dígitos separado por guiones de la forma xx-xxxxxxxx-x.

---
### Cálculo del dígito verificador:


Necesitamos obtener los caracteres de cuil individualmente, para esto los vamos a extraer con ayuda de un ciclo for y guardar en un arreglo. Como necesitamos operar con estos caracteres se convierten un tipo de dato numérico entero.

A cada uno de los 10 dígitos del arreglo se los multiplica por: 5, 4, 3, 2, 7, 6, 5, 4, 3, 2 respectivamente

Se suman los valores obtenidos y al resultado se lo divide por 11, quedandonos con el resto de la operación.
El dígito verificador será entonces 11-resto si es menor a 10. En caso de ser 10, el dígito que se anexa es 1. En otro caso, 0. Se convierte al tipo string para concatenarlo a Cuil.

---
### EJEMPLO


ObtenerCuil("12345678",Masculino)

cuil += "20" 


cuil += "12345678"


cuil = "2012345678"


cuilComoArregloDeDigitos[2,0,1,2,3,4,5,6,7,8]


2 0 1 2 3 4 5 6 7 8 

x 

5 4 3 2 7 6 5 4 3 2 

———————————————————— 

10+0+3+4+21+24+25+24+21+16= 148 


148 % 11 = 5  

DigitoVerificador= 11-5 = 6 

cuil += to_string(DigitoVerificador)

Finalmente


cuil = "20-12345678-6"


