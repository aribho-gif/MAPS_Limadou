#include "TObject.h"
#include "Point.h"



ClassImp(Point)

//________________________________________________________________________
Point::Point():TObject(),
 fX(0.),
 fY(0.),
 fZ(0.){
   // default constructor
 }


//___________________________________________________________________________
Point::Point(double X, double Y, double Z):TObject(),
 fX(X),
 fY(Y),
 fZ(Z){
	//standard constructor 
}	     

//___________________________________________________________________________
Point::~Point()	 {
  // destructor
}

