# Simulación de estructuras dinámicas - Polígono

---

# Autor: Gonzalez Tourn Agustina

---

## Problema: dada una cierta cantidad de puntos en el plano, determinar el perímetro del polígono que forman.

---
## Representación matemática del problema
![Alt text](Poligono_math.png?raw=true "Resolucion matematica")

---

## **Solucion 1 : Representación contigua mediante arreglo**

**Ventajas**: es una solución simple y rápida. Dentro de la reserva dinámica de memoria trabajamos con el Call Stack.

**Desventajas**: cantidad de vértices que podemos agregar es limitada y queda memoria sin utilizar. 

**Solución propuesta**: se indica fin de la secuencia con un numero natural que indica la cantidad de vértices.

**Ventajas de la solución propuesta**: al asociar cada vértice con un natural podemos crear fácilmente un índice para la secuencia. 

**Desventajas**: al agregar la variable que indica la cantidad de vértices se pueden cometer errores en los cálculos. 

**Ventajas de indicar el final de la secuencia repitiendo un vértice**: no necesitamos una variable extra para indicar el final de la secuencia.

**Desventajas**: si se ingresa por error un valor repetido se considera finalizada la secuencia.

### **Tipos de datos**
![Alt text](datos_cont.png?raw=true "struct poligono")
| Funciones | Precondiciones | Postcondiciones | Complejidad Algorítmica |
| --- | --- | --- | --- |
| `AddVertice : Poligono X N X Punto -> Void / AddVertice(poligono,n,p)` | El polígono debe estar inicializado. La posición del punto a agregar debe ser mayor o igual a uno y menor a 100. La posición no puede ser mayor a n, siendo n la cantidad de vértices del polígono, ni menor a 1.| El n-ésimo vértice del polígono es p. Se aumenta en uno la longitud de la secuencia poligono. | O(n) |
| `GetVertice : Poligono X N -> Punto / GetVertice(poligono,n) = v` | El polígono debe estar inicializado. La posición del punto a consultar debe ser mayor o igual a uno y menor a 100. La posición no puede ser mayor a n, siendo n la cantidad de vértices del polígono, ni menor que 1. | El n-ésimo vértice del polígono es v | O(1) |
| `SetVertice: Poligono X N X Punto -> void /SetVertice(poligono,n,p)` | El polígono debe estar inicializado. La posición del vértice a modificar debe ser menor o igual a n, siendo n la cantidad de vértices del poligono, y mayor o igual a 1. | El n-ésimo vértice del polígono toma el valor p | O(1) |
| `RemoveVertice: Poligono X N X Punto -> void /RemoveVertice(poligono,n,p)` | El polígono debe estar inicializado. La posición del vértice a remover debe ser menor o igual a n, siendo n la cantidad de vértices del polígono, y mayor o igual a 1. | Se elimina el vértice en la posición n y se disminuye en uno la longitud de la secuencia polígono. | O(n) |
| `GetCantidadLados : Poligono -> N / GetCantidadLados(poligono)=L` | El polígono debe estar inicializado. | La cantidad de lados del poligono es L | O(1) |
| `GetPerimetro : Poligono -> R / GetPerimetro(poligono)=p` | El polígono debe estar inicializado  | P es el perímetro del polígono. | O(n) |

---
#
## **Solución 2: Representación enlazada mediante nodos y punteros a siguientes nodos**.

**Ventajas**: no tenemos un límite de vértices para agregar al polígono ya que vamos solicitando memoria Heap con el uso de punteros.

**Desventajas**: esta solución insume más recursos: requiere más ciclos de reloj y la intervención del sistema operativo para dar más memoria. También es más propensa a errores. Si no se maneja apropiadamente la memoria Heap podemos tener espacio utilizado inaccesible.
### **Tipos de datos**
![Alt text](datos_link.png?raw=true "struct poligono")
| Funciones | Precondiciones | Postcondiciones | Complejidad Algorítmica |
| --- | --- | --- | --- |
| `AddVertice : Poligono X N X Punto -> Void / AddVertice(poligono,n,p)` | La posición no puede ser mayor a n, siendo n la cantidad de vértices(nodos) del polígono, ni menor a 1.| El n-ésimo nodo del polígono es p. | O(n) |
| `GetVertice : Poligono X N -> Punto / GetVertice(poligono,n) = v` | La posición no puede ser mayor a n, siendo n la cantidad de vértices(nodos) del polígono, ni menor que 1. | El n-ésimo vértice del polígono es v | O(n) |
| `SetVertice: Poligono X N X Punto -> void /SetVertice(poligono,n,p)` |  La posición del vértice(nodo) a modificar debe ser menor o igual a n, siendo n la cantidad de vértices del poligono, y mayor o igual a 1. | El n-ésimo vértice del polígono toma el valor p | O(n) |
| `RemoveVertice: Poligono X N X Punto -> void /RemoveVertice(poligono,n,p)` | La posición del vértice a remover debe ser menor o igual a n, siendo n la cantidad de vértices del polígono, y mayor o igual a 1. | Se elimina el nodo en la posición n  | O(n) |
| `GetCantidadLados : Poligono -> N / GetCantidadLados(poligono)=L` |  | La cantidad de lados del poligono es L | O(n) |
| `GetPerimetro : Poligono -> R / GetPerimetro(poligono)=p` | El polígono debe tener al menos dos vértices | P es el perímetro del polígono. | O(2n) |
