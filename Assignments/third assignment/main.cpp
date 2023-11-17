#include <iostream>
#include "classes.h"
using namespace std;
int main()
{
    cout << "*************************************************" << endl;
    cout << "Part 1" << endl;
    cout << "*************************************************" << endl;
    int numberOfShape = 0;
    cout << "Enter Number Of the Shape" << endl;
    cin >> numberOfShape;
    Shape **shapes = new Shape *[numberOfShape];
    int shapeTypeFlag = 0;
    for (int shapeArrayIndex = 0; shapeArrayIndex < numberOfShape; shapeArrayIndex++)
    {
        if (shapeTypeFlag == 0)
        {
            double radius;
            cout << "Enter circle radius" << endl;
            cin >> radius;
            shapes[shapeArrayIndex] = new Circle(radius, 1, 5);
            shapeTypeFlag++;
        }
        else if (shapeTypeFlag == 1)
        {
            double length, width;
            cout << "Enter rectangle length and width" << endl;
            cin >> length >> width;
            shapes[shapeArrayIndex] = new Rectangle(length, width, 1, 5);
            shapeTypeFlag++;
        }
        else
        {
            double length, height;
            cout << "Enter triangle length and height" << endl;
            cin >> length >> height;
            shapes[shapeArrayIndex] = new Triangle(length, height, 1, 5);
            shapeTypeFlag = 0;
        }
    }
    char choice;
    do
    {
        cout << "a)print coordinates for all shapes" << endl;
        cout << "b)print the area for all shapes" << endl;
        cout << "q)for quit" << endl;
        cin >> choice;
        switch (choice)
        {
        case 'a':
            for (int i = 0; i < numberOfShape; i++)
            {
                cout << i + 1 << ") ";
                float *coord = shapes[i]->getCoordinates();
                cout << "(" << coord[0] << "," << coord[1] << ")" << endl;
            }
            break;
        case 'b':
            for (int i = 0; i < numberOfShape; i++)
            {
                cout << i + 1 << ") " << getShapeArea(shapes[i]) << endl;
            }
            break;
        case 'q':
            break;
        default:
            cout << "You are enter a wrong choice" << endl;
        }

    } while (choice != 'q');
    cout << "*************************************************" << endl;
    cout << "Part 2" << endl;
    cout << "*************************************************" << endl;
    Circle c1(4, 1, 5), c2(5, 1, 6);
    Rectangle r1(3, 3, 3, 3), r2(4, 4, 4, 4);
    Triangle t1(5, 5, 7, 5), t2(6, 6, 5, 9);
    double cArea, rArea, tArea;

    cout << "here's the coordinates for all shapes : " << endl;
    cout << "the coordinates for the circles : " << endl;
    c1.getCoordinates();
    c2.getCoordinates();
    cout << "the coordinates for the rectangles : " << endl;
    r1.getCoordinates();
    r2.getCoordinates();
    cout << "the coordinates for the triangles : " << endl;
    t1.getCoordinates();
    t2.getCoordinates();
    cout << "\n************************************************\n"
         << endl;

    cArea = c1 + c2;
    rArea = r1 + r2;
    tArea = t1 + t2;

    cout << "here's the area's for all shape's : " << endl;
    cout << "1. circle's : c1's area = " << c1.getArea() << " c2's area = " << c2.getArea() << " and the sum of all circle's area = " << cArea << endl;

    cout << "2. rectangle's : r1's area = " << r1.getArea() << " r2's area = " << r2.getArea() << " and the sum of all circle's area = " << rArea << endl;

    cout << "3. triangle's : t1's area = " << t1.getArea() << " t2's area = " << t2.getArea() << " and the sum of all circle's area = " << tArea << endl;

    cout << "\n************************************************\n"
         << endl;
    cout << "here's the area's of one object of each shapes using the function getShapeArea() : " << endl;
    cout << "c1 area = " << getShapeArea(&c1) << endl;
    cout << "r1 area = " << getShapeArea(&r1) << endl;
    cout << "t1 area = " << getShapeArea(&t1) << endl;

    cout << endl
         << endl;
    cout << "Thank you for using the application" << endl;
}