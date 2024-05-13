// Hiya Noel here again
// We are gonna estimate the value of pi using the Monte Carlo method
// Here, we take a square of side 2 units and a circle of radius 1 unit
// The area of the square is 4 and the area of the circle is pi
// The ratio of the area of the circle to the area of the square is pi/4
// We randomly generate points in the square and check if they lie inside the circle
// The ratio of the number of points inside the circle to the total number of points is pi/4
// So the value of pi = 4 * (number of points inside the circle) / (total number of points)

#include <cstdlib>
#include <iostream>
#include <time.h>
#include <math.h>

using namespace std;

// Number of times to generate random points inside the square. Higher the number, we can be more confident about the result
// (But runtime increases tenfold with each zero added to the number of samples)
#define samples 1000000000

int main(void) {
    int points_in_circle = 0;
    int total_points = 0;

    srand(time(0));

    for (int i = 0; i < samples; i++) {
        // Generating random x and y coordinates
        double x = double(rand()) / RAND_MAX;
        double y = double(rand()) / RAND_MAX;

        // Calculating the distance from the centre: x^2 + y^2
        double distance = x*x + y*y;

        // Checking if the point is inside the circle:
        if (distance <= 1) {
            points_in_circle++;
        }

        total_points++;
    }

    cout << points_in_circle << "  " << total_points << endl;
    double pi = double(4.0 * points_in_circle) / total_points;
    cout << pi << endl;
}