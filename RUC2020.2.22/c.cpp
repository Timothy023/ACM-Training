#include <bits/stdc++.h>
using namespace std;

const double esp = 1e-12;


struct node {
    double x, y;
    node() {}
    node(double _x, double _y) {
        x = _x; y = _y;
    }
    friend node operator + (node i, node j) {
        return node(i.x + j.x, i.y + j.y);
    }
    friend node operator - (node i, node j) {
        return node(i.x - j.x, i.y - j.y);
    }
    friend double operator * (node i, node j) {
        return i.x * j.x + i.y * j.y;
    }
    friend double operator ^ (node i, node j) {
        return i.x * j.y - i.y * j.x;
    }
}p[10];
double dis(node i, node j) {
    return sqrt((i - j) * (i - j));
}

double dot(node i, node j, node k) {
    return (j - i) * (k - i);
}
double cross(node i, node j, node k) {
    return (j - i) ^ (k - i);
}

double area(node b, node c, double r) {
    node a(0.0, 0.0);
    if (dis(b, c) < esp) return 0.0;
    double h = fabs(cross(a, b, c)) / dis(b, c);
    if (dis(a, b) > r - esp && dis(a, c) > r-esp) {
        double angle = acos(dot(a, b, c) / dis(a, b) / dis(a, c));
        if (h > r- esp) return 0.5 * r * r * angle;
        else if (dot(b, a, c) > 0 && dot(c, a, b) > 0) {
            double angle1 = 2 * acos(h / r);
            return 0.5 * r * r * fabs(angle - angle1) +0.5 *r * r * sin(angle1);
        }
        else return 0.5 * r * r * angle;
    }
    else {
        if (dis(a, b) < r + esp && dis(a, c) < r + esp) return 0.5 * fabs(cross(a, b, c));
        else {
            if (dis(a, b) > dis(a, c)) swap(b, c);
            if (fabs(dis(a, b)) < esp) return 0.0;
            if (dot(b, a, c) < esp) {
                double angle1 = acos(h / dis(a, b));
                double angle2 = acos(h / r) - angle1;
                double angle3 = acos(h / dis(a, c))- acos(h / r);
                return 0.5 * dis(a, b) * r * sin(angle2)
                     + 0.5 * r * r * angle3;
            }
            else {
                double angle1 = acos(h / dis(a, b));
                double angle2 = acos(h / r);
                double angle3 = acos(h / dis(a, c)) - angle2;
                return 0.5 * r * dis(a, b) * sin(angle1 + angle2)
                     + 0.5 * r * r * angle3;
            }
        }        
    }
}

int main () {
    int n = 4;
    double rx, ry, R;
    scanf ("%lf%lf%lf", &rx, &ry, &R);
    scanf ("%lf%lf%lf%lf", &p[1].x, &p[1].y, &p[3].x, &p[3].y);
    p[2].x = p[1].x; p[2].y = p[3].y;
    p[4].x = p[3].x; p[4].y = p[1].y;
    p[5] = p[1];
    node O(rx, ry);
    for (int i = 1; i <= n + 1; ++i) p[i] = p[i] - O;
    O = node(0, 0);
    double sum = 0;
    for (int i = 1; i <= n; ++i) {
        int j = i + 1;
        double s = area(p[i], p[j], R);
        if (cross(O, p[i], p[j]) > 0) sum += s;
        else sum -= s;
    }
    printf ("%.6lf\n", fabs(sum));
    return 0;
}