#include "classConcept.h"

int main() {

	float a, b, c;
	cout << "Please enter the sides(a-b-c)" << endl;
	cin >> a >> b >> c;
	Triangle triangle1(a, b, c);//const tetiklendi.

	Triangle triangle2 = triangle1;//copy const tetiklendi.
	Triangle triangle3(triangle1);//copy const tetiklendi.farklı yazım hali.

	cout << "-Triangle 1 -" << endl; //1. üçgen kullanıcının girdiği bilgilere göre oluşturulur.
	cout << "Side A:" << triangle1.getSideA() << endl;
	cout << "Side B:" << triangle1.getSideB() << endl;
	cout << "Side C:" << triangle1.getSideC() << endl;

	cout << "-Triangle 2 -" << endl; //2. üçgen hazır bir üçgendir.
	triangle2.setValue(12, 16, 20);
	cout << "Side A:" << triangle2.getSideA() << endl;
	cout << "Side B:" << triangle2.getSideB() << endl;
	cout << "Side C:" << triangle2.getSideC() << endl;

	cout << "- Triangle 1 -" << endl;
	triangle1.triangleType();
	cout << "- Triangel 2" << endl;
	triangle2.triangleType();

	cout << "- Triangle 1 area -" << endl;
	cout << triangle1.calculateArea() << endl;

	cout << "- Triangle 2 area -" << endl;
	cout << triangle2.calculateArea() << endl;

	return 0;
}