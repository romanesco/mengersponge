#include <iostream>
#include <cmath>
using namespace std;

void outputTriangle(double x1, double y1, double z1,
		    double x2, double y2, double z2,
		    double x3, double y3, double z3,
		    double n1, double n2, double n3,
		    double scale,
		    double xcenter, double ycenter,
		    double zcenter) {
  /*
  double u1=x2-x1, v1=y2-y1, w1=z2-z1,
    u2=x3-x1, v2=y3-y1, w2=z3-z1;
  
  // vertices are ordered counterclockwise
  double n1 = v1*w2-v2*w1, n2= w1*u2-w2*u1, n3 = u1*v2-v1*u2;
  double norm=sqrt(n1*n1+n2*n2+n3*n3);
  n1=n1/norm; n2=n2/norm; n3=n3/norm;
  */

  x1 = (x1-xcenter)*scale;
  x2 = (x2-xcenter)*scale;
  x3 = (x3-xcenter)*scale;

  y1 = (y1-ycenter)*scale;
  y2 = (y2-ycenter)*scale;
  y3 = (y3-ycenter)*scale;

  z1 = (z1-zcenter)*scale;
  z2 = (z2-zcenter)*scale;
  z3 = (z3-zcenter)*scale;

  cout << "facet normal "
       << n1 << " " << n3 << " " << -n2 << endl
       << "    outer loop" << endl
       << "        vertex " << x1 << " " << z1 << " " << -y1 << endl
       << "        vertex " << x2 << " " << z2 << " " << -y2 << endl
       << "        vertex " << x3 << " " << z3 << " " << -y3 << endl
       << "    endloop" << endl
       << "endfacet" << endl;

}
