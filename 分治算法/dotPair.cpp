// 分治算法：最近点对问题
// 问题描述：二维空间平面上有n个点，求具有最短距离的两个点
// 输入：点集合
// 输出: 最近点对及其距离
#include <bits/stdc++.h>
using namespace std;

#define INF 99999
#define MAXRANGE 10 //　坐标范围(-10,10)
#define N 5         // 点的个数

struct Point
{
    double x, y;
};

double Distance(Point a, Point b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

bool cmpX(Point a, Point b)
{
    return a.x < b.x;
}

bool cmpY(Point a, Point b)
{
    return a.y < b.y;
}

// 求出最近点对记录，并将两点记录再a、b中,返回最近距离
double ClosestDotPair(Point points[], int len, Point &a, Point &b)
{
    double d;
    Point a1, b1, a2, b2;
    if (len < 2)
        return INF;
    else if (len == 2)//若子集大小为２则直接返回两点距离
    {
        a = points[0];
        b = points[1];
        d = Distance(points[0], points[1]);
    }
    else
    {
        int i, j;
        double dl, dr;
        Point *pl = new Point[len];
        Point *pr = new Point[len];
        //　得到中线
        double mid = points[(len - 1) / 2].x;
        for (i = 0; i < len / 2; i++)
            pl[i] = points[i];
        for (j = 0, i = len / 2; i < len; i++)
            pr[j++] = points[i];
        dl = ClosestDotPair(pl, len / 2, a1, b1);
        dr = ClosestDotPair(pr, len - len / 2, a2, b2);
        // 根据左右子集求得的结果更新最近点对和距离
        if (dl < dr){d = dl;a = a1;b = b1;}
        else{d = dr;a = a2; b = b2;}

        //　Merge，看中线附近的邻域内还存不存在最小点
        Point *tmp = new Point[len];
        int k;
        for (i = 0, k = 0; i < len; i++)
        {
            if (fabs(points[i].x - mid) <= d)
                tmp[k++] = points[i];
        }
        sort(tmp, tmp + k, cmpY);
        for (i = 0; i < k; i++)//只需要对左半邻域的点考察６个右半邻域的点
        {
            if (tmp[i].x - mid >= 0)
                continue;
            int cnt = 0;
            for (j = i + 1; j < k && cnt < 6; j++)
            {
                if (tmp[j].x - mid >= 0)
                {
                    if (Distance(tmp[i], tmp[j]) < d)
                    {
                        d = Distance(tmp[i], tmp[j]);
                        a = tmp[i];
                        b = tmp[j];
                    }
                    cnt++;
                }
            }
        }
    }
    return d;
}

int main()
{
    srand(unsigned(time(NULL)));
    Point *points = new Point[N];
    Point a, b;
    for (int i = 0; i < N; i++)
    {
        points[i].x = rand() % (int)(2 * MAXRANGE * MAXRANGE) / MAXRANGE - MAXRANGE;
        points[i].y = rand() % (int)(2 * MAXRANGE * MAXRANGE) / MAXRANGE - MAXRANGE;
    }
    sort(points, points + N, cmpX);
    cout << "随机生成如下" << N << "个点：" << endl;
    for (int i = 0; i < N; i++)
        printf("(%.2lf,%.2lf)\n", points[i].x, points[i].y);
    double distance = ClosestDotPair(points, N, a, b);
    cout << "最近点对为：" << endl;
    printf("(%.2lf,%.2lf)和(%.2lf,%.2lf)\n", a.x, a.y, b.x, b.y);
    cout << "距离为:" << endl;
    printf("%.4lf\n", distance);
    return 0;
}