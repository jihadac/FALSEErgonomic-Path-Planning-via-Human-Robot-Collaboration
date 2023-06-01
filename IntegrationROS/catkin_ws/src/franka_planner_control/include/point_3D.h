class Point3D
{
    public:
        double x;
        double y;
        double z;
        Point3D(double a, double b, double c);
        Point3D();
        double getDistance(const Point3D& p1, const Point3D& p2);
        Point3D getMiddle(const Point3D& pt1, const Point3D& pt2);
};

Point3D::Point3D(double a, double b, double c){
    x = a;
    y = b;
    z = c;
}

Point3D::Point3D(){}

double getDistance(const Point3D& p1, const Point3D& p2){
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y)+(p1.z-p2.z)*(p1.z-p2.z));
}

Point3D getMiddle(const Point3D& pt1, const Point3D& pt2){
    Point3D res;
    res.x = (pt1.x + pt2.x)*0.5;
    res.y = (pt1.y + pt2.y)*0.5;
    res.z = (pt1.z + pt2.z)*0.5;
    return res;
}