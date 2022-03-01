#include <bits/stdc++.h>

using namespace std;

struct Rect{
  int x1,y1,x2,y2;
  int area()
  {
    return (y2-y1)*(x2-x1);
  }
};
int intersection(Rect a , Rect b)
{
  int xOfOverlap = max(0,min(a.x2,b.x2)-max(a.x1,b.x1));
  int yOfOverlap = max(0,min(a.y2,b.y2)-max(a.y1,b.y1));
  return xOfOverlap * yOfOverlap;
}

int main()
{
  ifstream fin("billboard.in");
  ofstream fout("billboard.out");
  Rect b1 , b2 , truck;
  fin >> b1.x1 >> b1.y1 >> b1.x2 >> b1.y2;
  fin >> b2.x1 >> b2.y1 >> b2.x2 >> b2.y2;
  fin >> truck.x1 >> truck.y1 >> truck.x2 >> truck.y2;
  int ans = b1.area() + b2.area() - intersection(b1,truck) - intersection(b2,truck); 
  fout << ans << endl;
}
