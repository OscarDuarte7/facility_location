
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Point_set_2.h>
#include <list>
typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef CGAL::Point_set_2<K>::Edge_iterator  Edge_iterator;
typedef CGAL::Point_set_2<K>::Vertex_handle  Vertex_handle;
typedef K::Point_2                           Point_2;
CGAL::Point_set_2<K> PSet;
Point_2 ar1[5];
int main()
{
  std::list<Point_2> Lr;
  Point_2 p1(12,14);
  Point_2 p2(5,4);
  Point_2 p3(2,11);

  // Puntos a comparar
  Point_2 p4(5,6);
  Point_2 p5(6.7,3.8);
  Point_2 p6(11,20);
  Point_2 p7(-5,6);
  Point_2 p8(3,4);
  Point_2 p9(4,31);
  Point_2 p10(-10,-10);
  Lr.push_back(p1); Lr.push_back(p2); Lr.push_back(p3);

  PSet.insert(Lr.begin(),Lr.end());
   // init
  ar1[0]=p4; ar1[1]=p5; ar1[2]=p3; ar1[3]=p7; ar1[4]=p8;
  Point_2 actual(3,4);
  // nearest neighbor ...

int cercanos[3] = {0,0,0};

for(int i=0; i < 5; i++){

  Vertex_handle v = PSet.nearest_neighbor(ar1[i]);

  
  if (v->point()==p1)
      cercanos[0]++;
  if (v->point()==p2)
      cercanos[1]++;
  if (v->point()==p3)
      cercanos[2]++;

}

if(cercanos[0] >= cercanos[1] && cercanos[0] >= cercanos[2]){
  std::cout << "El mejor punto posible es: " << p1;
}
if(cercanos[1] >= cercanos[0] && cercanos[1] >= cercanos[2]){
  std::cout << "El mejor punto posible es: " << p2;
}
if(cercanos[2] >= cercanos[1] && cercanos[2] >= cercanos[0]){
  std::cout << "El mejor punto posible es: " << p1;
}


  return 0;
}