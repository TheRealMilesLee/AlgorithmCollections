#include <cfloat>
#include <cmath>
#include <cstdlib>
#include <iostream>

using namespace std;

// A structure to represent a Point in 2D plane
class Point
{
 public:
  int x, y;
};

/**
 * @brief Need to sort array of points according to X coordinate
 *
 * @param a is the x coordinate of the first point
 * @param b is the y coordinate of the first point
 * @return int
 */
int compareX(const void *a, const void *b);

/**
 * @brief Needed to sort array of points according to Y coordinate
 * @param a is the x coordinate of the first point
 * @param b is the y coordinate of the first point
 * @return int
 */
int compareY(const void *a, const void *b);

/**
 * @brief A utility function to find the distance between two points
 *
 * @param p1 is the first point
 * @param p2 is the second point
 * @return float
 */
float dist(Point p1, Point p2);

/**
 * @brief A Brute Force method to return the smallest distance between two points in P[] of size n
 * @param P is the array of points
 * @param n is the size of the array
 * @return float is the smallest distance
 */
float bruteForce(Point P[], int n);

/**
 * @brief A utility function to find minimum of two float values
 * @param x is the first float value
 * @param y is the second float value
 * @return float is the minimum of the two values
 */
float min(float x, float y);

/**
 * @brief A utility function to find the distance between the closest points of strip of given size.
 * All points in strip[] are sorted according to y coordinate. They all have an upper bound on minimum distance as d.
 * Note that this method seems to be a O(n^2) method, but it's a O(n) method as the inner loop runs at most 6 times
 * @param strip is the array of points
 * @param size is the size of the array
 * @param d is the minimum distance
 * @return float is the smallest distance
 */
float stripClosest(Point strip[], int size, float d);

/**
 * @brief A recursive function to find the smallest distance.
 * The array P contains all points sorted according to x coordinate
 * @param P is the array of points
 * @param n is the size of the array
 * @return float is the smallest distance
 */
float closestUtil(Point P[], int n);

/**
 * @brief The main function that finds the smallest distance. This method mainly uses closestUtil()
 * @param P is the array of points
 * @param n is the size of the array
 * @return float is the smallest distance
 */
float closest(Point P[], int n);
// Driver code
int main()
{
  Point P[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
  int n = sizeof(P) / sizeof(P[0]);
  cout << "The smallest distance is " << closest(P, n) << endl;
  return 0;
}

int compareX(const void *a, const void *b)
{
  Point *p1 = (Point *)a;
  Point *p2 = (Point *)b;
  return (p1->x - p2->x);
}

int compareY(const void *a, const void *b)
{
  Point *p1 = (Point *)a;
  Point *p2 = (Point *)b;
  return (p1->y - p2->y);
}

float dist(Point p1, Point p2) { return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y)); }

float bruteForce(Point P[], int n)
{
  float min = FLT_MAX;
  for (int i = 0; i < n; ++i)
    for (int j = i + 1; j < n; ++j)
      if (dist(P[i], P[j]) < min)
        min = dist(P[i], P[j]);
  return min;
}

float min(float x, float y) { return (x < y) ? x : y; }

float stripClosest(Point strip[], int size, float d)
{
  float min = d;  // Initialize the minimum distance as d

  qsort(strip, size, sizeof(Point), compareY);

  // Pick all points one by one and try the next points till the difference
  // between y coordinates is smaller than d.
  // This is a proven fact that this loop runs at most 6 times
  for (int i = 0; i < size; ++i)
    for (int j = i + 1; j < size && (strip[j].y - strip[i].y) < min; ++j)
      if (dist(strip[i], strip[j]) < min)
        min = dist(strip[i], strip[j]);

  return min;
}

float closestUtil(Point P[], int n)
{
  // If there are 2 or 3 points, then use brute force
  if (n <= 3)
    return bruteForce(P, n);

  // Find the middle point
  int mid = n / 2;
  Point midPoint = P[mid];

  // Consider the vertical line passing
  // through the middle point calculate
  // the smallest distance dl on left
  // of middle point and dr on right side
  float dl = closestUtil(P, mid);
  float dr = closestUtil(P + mid, n - mid);

  // Find the smaller of two distances
  float d = min(dl, dr);

  // Build an array strip[] that contains
  // points close (closer than d)
  // to the line passing through the middle point
  Point strip[n];
  int j = 0;
  for (int i = 0; i < n; i++)
    if (abs(P[i].x - midPoint.x) < d)
      strip[j++] = P[i];

  // Find the closest points in strip.
  // Return the minimum of d and closest
  // distance is strip[]
  return min(d, stripClosest(strip, j, d));
}

float closest(Point P[], int n)
{
  qsort(P, n, sizeof(Point), compareX);

  // Use recursive function closestUtil()
  // to find the smallest distance
  return closestUtil(P, n);
}
