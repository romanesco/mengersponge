#include <iostream>
#include <cmath>
#include <array>
using namespace std;

#include "outputtriangle.hpp"

const int DEPTH=4;

typedef array<char, DEPTH> Seq;

int N = pow(3,DEPTH);

void int2seq(const int &n, Seq &s)
{
  int m=n;
  for (int i=0; i<DEPTH; i++) {
    s[i] = m % 3;
    m /= 3;
  }
}

bool inSponge(const Seq &i, const Seq &j, const Seq &k)
{
  bool in = true;
  int a;
  for (int d=0; d<DEPTH; d++) {
    a = ((i[d] == 1) ? 1 : 0) +
      ((j[d] == 1) ? 1 : 0) +
      ((k[d] == 1) ? 1 : 0);
    if (a >= 2) in = false;
  }
  return in;
}

bool inSponge(const int &n, const int &m, const int &l)
{
  if ( (n<0) || (m<0) || (l<0) || 
       (n>=N) || (m>=N) || (l>=N) ) {
    return false;
  }
  
  Seq i, j, k;
  int2seq(n, i);
  int2seq(m, j);
  int2seq(l, k);
  
  return inSponge(i,j,k);
}

int main()
{
  cout << "solid " << endl;

  double scale = 1.0/N;

  bool a,b;
  b = false;
  for (int m=0; m<N; m++) {
    for (int l=0; l<N; l++) {
      for (int n=0; n<=N; n++) {
	a = inSponge(n,m,l);
	if (a == !b) { // on the boundary
	  if (a) { // consider normal outer direction
	    // output 3 squares (use symmetry)
	    outputTriangle(n,m,l,
			   n,m+1,l+1,
			   n,m+1,l,
			   -1,0,0, scale);
	    outputTriangle(n,m,l,
			   n,m,l+1,
			   n,m+1,l+1,
			   -1,0,0, scale);
	    outputTriangle(l,n,m,
			   l+1,n,m+1,
			   l,n,m+1,
			   0,-1,0, scale);
	    outputTriangle(l,n,m,
			   l+1,n,m,
			   l+1,n,m+1,
			   0,-1,0, scale);
	    outputTriangle(m,l,n,
			   m+1,l+1,n,
			   m+1,l,n,
			   0,0,-1, scale);
	    outputTriangle(m,l,n,
			   m,l+1,n,
			   m+1,l+1,n,
			   0,0,-1, scale);
	  } else {
	    outputTriangle(n,m,l,
			   n,m+1,l,
			   n,m+1,l+1,
			   1,0,0, scale);
	    outputTriangle(n,m,l,
			   n,m+1,l+1,
			   n,m,l+1,
			   1,0,0, scale);
	    outputTriangle(l,n,m,
			   l,n,m+1,
			   l+1,n,m+1,
			   0,1,0, scale);
	    outputTriangle(l,n,m,
			   l+1,n,m+1,
			   l+1,n,m,
			   0,1,0, scale);
	    outputTriangle(m,l,n,
			   m+1,l,n,
			   m+1,l+1,n,
			   0,0,1, scale);
	    outputTriangle(m,l,n,
			   m+1,l+1,n,
			   m,l+1,n,
			   0,0,1, scale);
	  }
	}
	b = a;
      }
    }
  }

  cout << "endsolid " << endl;

}
