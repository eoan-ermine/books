#include <iostream>

struct Point2D {
    int x;
    int y;
};

class Point3D {
public:
    int x;
    int y;
    int z;
};

int main() {
    Point2D point2D {.x = 1, .y = 2};
    // Point2D point2d { .y = 2, .x = 1}; // error
    Point3D point3D {.x = 1, .y = 2, .z = 2};
    // Point3D point3D {.x = 1, .z = 2} // {1, 0, 2}

    std::cout << "point2D: " << point2D.x << " " << point2D.y << "\n";
    std::cout << "point3D: " << point3D.x << " " << point3D.y << " " << point3D.z;
}
