#include <stdio.h>
#include <math.h>

int relax(void)
{
    int l, a, xa, ya, xb, yb;
    scanf("%d %d\n%d %d\n%d %d", &l, &a, &xa, &ya, &xb, &yb);
    float luan = 0;
    float larissa = 0;
    float total = 0;
    for (int i = 0; i <= l; i++)
    {
        for (int j = 0; j <= a; j++)
        {
            double dist_luan = sqrt((double)(xa - i) * (xa - i) + (ya - j) * (ya - j));
            double dist_larissa = sqrt((double)((xb - i) * (xb - i) + (yb - j) * (yb - j)));
            if (dist_luan == dist_larissa) continue;
            dist_luan < dist_larissa ? luan++ : larissa++;
            total++;
        }
    }
    printf("%.9f %.9f\n", luan / total, larissa / total);
    return 0;
}

int main() {
    return relax();
} 