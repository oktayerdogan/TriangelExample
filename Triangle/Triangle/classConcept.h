#include <iostream>
#include <string>
using namespace std;

class Triangle {
public:
	Triangle(float a, float b, float c);
	bool isTriangle(float a, float b, float c);
	float getSideA() const;
	float getSideB() const;
	float getSideC() const;
	void setValue(float a, float b, float c);
	bool isEquilateral();
	bool isScalene();
	bool isIsosceles();
	void triangleType();
	float calculateArea();
private:
	float sideA, sideB, sideC;
};

bool Triangle::isTriangle(float a, float b, float c) {
	if (!((abs(b - c) < a) && (a < (b + c)))) {
		cout << "Invalid A" << endl;
		return false;
	}
	if (!((abs(a - c) < b) && (b < (a + c)))) {
		cout << "Invalid B" << endl;
		return false;
	}
	if (!((abs(b - a) < c) && (c < (b + a)))) {
		cout << "Invalid C" << endl;
		return false;
	}
	return true;
}
Triangle::Triangle(float a, float b, float c) {
	while (!isTriangle(a, b, c)) { //True olursa tekrardan deðer girmemizi ister.False olursa girilen deðerlerle üçgen oluþturulabilir ve tekrar deðer giriniz kýsmýna girmez.! iþaretine dikkat et.
		cout << "Please enter the sides(a-b-c)" << endl;
		cin >> a >> b >> c;
	}
	sideA = a;
	sideB = b;
	sideC = c;
	cout << "Triangle created." << endl;
}
float Triangle::getSideA() const { //get fonksiyonlarýyla üçgenlerin kenar uzunluklarýný konsolda görüyorum.
	return sideA;
}
float Triangle::getSideB() const {
	return sideB;
}
float Triangle::getSideC() const {
	return sideC;
}
void Triangle::setValue(float a, float b, float c) {
	while (!isTriangle(a,b,c)){
		cout << "Please enter the sides(a-b-c)" << endl;
		cin >> a >> b >> c;
	}
	sideA = a;
	sideB = b;
	sideC = c;
}
bool Triangle::isEquilateral() { //eþkenar ücgen
	return sideA == sideB && sideB == sideC;
}
bool Triangle::isIsosceles() { //ikizkenar ücgen
	if (isEquilateral()) { // her eþkenar üçgen ayný zamanda ikizkenar ücgendir bu yüzden kontrol ediyorum.
		return true;
	}
	else {
		return sideA == sideB || sideA == sideC || sideB == sideC;
	}
}
bool Triangle::isScalene() { //çeþitkenar ücgen.
	return !isEquilateral();
}
void Triangle::triangleType() {
	if (isEquilateral()) {
		cout << "Equilateral Triangle." << endl;
	}
	else if(isIsosceles()){
		cout << "Isosceles Triangle." << endl;
	}
	else {
		cout << "Scalene Triangle." << endl;
	}
}
float Triangle::calculateArea() {
	float area;
	if (isEquilateral()) {
		area = (pow(sideA, 2) * sqrt(3) / 4);
		return area;
	}
	float s = (sideA + sideB + sideC) / 2;
	area = sqrt(s * (s - sideA) * (s - sideB) * (s - sideC));
	return area;
}