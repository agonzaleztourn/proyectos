struct Poligono{
    array<Punto, 100> puntos;
    unsigned n; //elementos del arreglo
}

(a,b,c,d,...),4)

reserva dinamica y manual de memoria
cantidad variable y no acotada de elementos
Punto a = {1,1};
    Punto b = {-1,1};
    Punto c = {-1,-1};
    Punto d = {1,-1};



   Poligono p{{a,b,c,d},4};
   Punto e;

   cout << GetPerimetro(p) << endl;
   e = GetVertice(p);
   cout << e.x <<','<< e.y << endl;
   
   SetVertice(p);
   cout << GetPerimetro(p);