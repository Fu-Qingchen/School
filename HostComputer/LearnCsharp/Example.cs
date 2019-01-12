using System;
using System.Collections.Generic;

namespace YieldReturn语法解析
{
    class Program
    {
        Point a = new Point4D(1, 1, 1, 1);
        Point4D b = new Point4D(1, 1, 1, 1);
    }
    public class Point
    {
        public int x, y;
        public Point(int x, int y)
        {
            this.x = x;
            this.y = y;
        }
    }
    public class Point3D : Point
    {
        public int z;
        public Point3D(int x, int y, int z) :
            base(x, y)
        {
            this.z = z;
        }
    }
    public class Point4D : Point3D
    {
        public int a;
        public Point4D(int x, int y, int z,int a) :
            base(x, y, z)
        {
            this.z = z;
        }
    }
}