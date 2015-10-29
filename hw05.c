#include <stdio.h>
#include <math.h>


struct point2d
{
    double x;
    double y;
};


struct triangle
{
    struct point2d a;
    struct point2d b;
    struct point2d c;
};

double area (struct triangle t);

double area (struct triangle t)
{
    double s;

    s = 0.5 * fabs ((t.b.x - t.a.x) * (t.c.y - t.a.y) - (t.c.x -
            t.a.x) * (t.b.y - t.a.y));
    return s;
}

double distance (struct point2d a, struct point2d b);

double distance (struct point2d a, struct point2d b)
{
    double A;

    A = sqrt ((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));

    return A;
}

int main (void)
{
    struct triangle t = (struct triangle) { {2., 2.}, {-2., 1.}, {0., -3} };

    double A1 = distance (t.a, t.b);
    double A2 = distance (t.a, t.c);
    double A3 = distance (t.b, t.c);

    double s = area (t);

    printf ("radius = %f\n", 2 * s / (A1 + A2 + A3));

    return 0;
}
