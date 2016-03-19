
#include "Input.h"

using namespace std;

float x1,y1;
float x2,y2;
float xc,yc,r;
int xe, ye, rx, ry;
void takePoints();
void takePointsCircle();
void takePointsEllipse();

int main()
{
    int input;
    int input1;   // inputs for switch case

    while(input != 4)
    {
        cout << "Graphics operations\n";
        cout << "1.Straight Line\n";
        cout << "2.Circle\n";
        cout << "3.Ellipse\n";
        cout << "4.Exit\n";
        cin >> input;

        switch(input){
        case 1:
            cout << "Choose line drawing algorithm\n";
            while(input1 != 5)
            {
                cout << "1.DDA Algorithm\n";
                cout << "2.Bresenham Algorithm\n";
                cout << "3.Wu Algorithm\n";
                cout << "4.Exit to main menu\n";
                cout << "5.Exit\n";
                cin >> input1;

                Input line;
                takePoints();

                if(input1 == 1)
                {
                    line.DDAAlgorithm(x1,y1,x2,y2);
                }
                else if(input1 == 2)
                {
                    line.BresenhamAlgorithm(x1,y1,x2,y2);
                }
                else if(input1 == 3)
                {
                    line.WuAlgorithm(x1,y1,x2,y2);
                }
                else if(input1 == 4)
                {
                    cout << "Main menu";
                    break;
                }
                else if(input1 == 5)
                {
                    exit(2);
                }
                else
                {
                    cout << "Invalid Entry! Try again";
                }

            }
            break;
        case 2:
            cout << "Choose circle drawing algorithm\n";
            while(input1 != 4)
            {
                cout << "1.Coordinate Algorithm\n";
                cout << "2.Parametric Algorithm\n";
                cout << "3.Exit to main menu\n";
                cout << "4.Exit\n";
                cin >> input1;

                Circle circle;
                takePointsCircle();

                if(input1 == 1)
                {
                    circle.CircleCoordinate(xc, yc, r);
                }
                else if(input1 == 2)
                {
                    circle.CircleParametric(xc, yc, r);
                }
                else if(input1 == 3)
                {
                    cout << "Main menu";
                    break;
                }
                else if(input1 == 4)
                {
                    exit(4);
                }
                else
                {
                    cout << "Invalid Entry! Try again";
                }

            }

            break;

        case 3:
            cout << "Choose Ellipse drawing algorithm\n";
            while(input1 != 5)
            {
                cout << "1.Cartesian Algorithm\n";
                cout << "2.Mid Point Algorithm\n";
                cout << "3.Parametric Algorithm\n";
                cout << "4.Exit to main menu\n";
                cout << "5.Exit\n";
                cin >> input1;

                Ellipses ellipses;
                takePointsEllipse();

                if(input1 == 1)
                {
                    ellipses.EllipseCartesian(xc,yc,rx,ry);
                }
                else if(input1 == 2)
                {
                    ellipses.EllipseMidPoints(x1,y1,x2,y2);
                }
                else if(input1 == 3)
                {
                    ellipses.EllipseParametric(x1,y1,x2,y2);
                }
                else if(input1 == 4)
                {
                    cout << "Main menu";
                    break;
                }
                else if(input1 == 5)
                {
                    exit(3);
                }
                else
                {
                    cout << "Invalid Entry! Try again";
                }

            }
            break;
        case 4:
            exit(1);
            break;
        default :
            cout << "Invalid Entry! Try again";
            break;
        }
    }

}


void takePoints()
{
    cout << "Enter the first coordinate points of line : \n";
    cin >> x1 >> y1;
    cout << "Enter the second coordinate points of line : \n";
    cin >> x2 >> y2;
}

void takePointsCircle()
{
    cout << "Enter the centre of circle : \n";
    cin >> xc >> yc;
    cout << "Enter the radius of circle : \n";
    cin >> r;
}

void takePointsEllipse()
{
    cout << "Enter the centre of ellipse : \n";
    cin >> xe >> ye;
    cout << "Enter the radius of ellipse : \n";
    cin >> rx >> ry;
}
