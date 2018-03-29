//#include <iostream>
#include <string>
#include <catch.hpp>
//using namespace std;


template <int n>
struct Vector { float data[n]; };

template <>
struct Vector<4> {
    union {
        float data[4];
        struct { float x, y, z, w; };
        struct { float r, g, b, a; };
        Vector<2> xy;
        Vector<3> xyz;
        Vector<3> rgb;
    };

    Vector<3> & xyz2() { return reinterpret_cast<Vector<3> &>(data); }
    const Vector<3> & xyz2() const { return reinterpret_cast<const Vector<3> &>(data); }

};

typedef Vector<2> Vec2;
typedef Vector<3> Vec3;
typedef Vector<4> Vec4;


#define ZEROVECTOR CVector()
class CVector
{       // Private 
 float x,y,z,w; // Order list of 4 elements |x|y|z|w|
public:
 static char sBuffer[38];  // holds the string of given vector
 char* toString();    // Return sBuffer with (x,y,z,w) values
 CVector (void);      // zero Vector Constructor
 CVector (float,float,float);   // Constructor
 CVector (CVector&);            // Copy Vector Constructor
 ~CVector();                    // Destructor
 CVector  operator+(CVector&);  // Addition
 CVector  operator-(CVector&);  // Subtraction
 float    dotProduct(CVector&);  
 void  operator=(CVector&);     // Copy Vector
 int  operator==(CVector&);     // Comparison Vector
 CVector  operator*(CVector&);  // Cross Product
 CVector  operator*(float);     // Scalar Multiplication
 float length();                // Magnitude
 void normalize();
};

CVector::CVector (float xi,float yi,float zi){  // Constructor
 x=xi;
 y=yi;
 z=zi;
 w=1.0f; // normalize the vector
}

CVector::CVector (CVector& a){   // Copy Vector Constructor
 x=a.x;
 y=a.y;
 z=a.z;
 w=a.w;
}

void CVector::operator=(CVector& a){  // Copy Vector
 x=a.x;
 y=a.y;
 z=a.z;
 w=a.w;
}
CVector::~CVector(){}    // Destructor

/*CVector  CVector::operator-(CVector& a){  // Subtraction
 return CVector(x -a.x,y -a.y,z -a.z);
}*/

/*CVector  CVector::operator+(CVector& a){  // Addition
 return CVector(cast(float)(x +a.x),cast(float)(y +a.y),cast(float)(z +a.z));
}*/

int main() {
//  cout << "test";
  printf("Vector Example\n");

  /*CVector a = *///CVector a;
//  a = new CVector(1.0f, 2.0f, 3.0f);
//  Vector<2> a = Vector<2>(1, 2);
}


TEST_CASE("x, y, z", "[basics]") {
    CVector c = CVector(1.0f, 2.0f, 3.0f);
//    REQUIRE(c.next() == 0);
//    CHECK(c.next() == 1);

//    static_assert(std::is_same<decltype(c.next()), int>::value, "default counter is int-based");
}

