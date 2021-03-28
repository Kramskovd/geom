#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EPS 1e-15

struct circle
{
	double x;
	double y;
	double r;
	int sostoyanie;
};
double rasstoyanie(struct circle p1, struct circle p2);
void initialization(struct circle *a, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		a[i].r = 0;
		a[i].sostoyanie = 1;
	}
}

int programm(struct circle *a, int n)
{
	double length, min;
	int i, j, k, i1, i2;
	initialization (a, n);
	for (k=0; k<n; k++)
	{
		min = 0;
		for (i = 0; i < n; i++)
		{
			if(a[i].sostoyanie == 1)
			{
				for(j = 0; j < n; j++)
				{
					if(i!=j)
					{
						length = rasstoyanie(a[i], a[j]);
						if(a[j].sostoyanie == 0)
						{
							length = length - a[j].r;
						}
						else
						{
							length /= 2;
						}
						if((min<EPS)&&(-min>-EPS))
						{
							min = length;
							i1 = i;
							i2 = i;
						}
						else
							if (min-length>EPS)
							{
								min = length;
								i1 = i;
								i2 = i;
							}
					}
				}
			}
		}
		a[i1].r = min;
		a[i1].sostoyanie = 0;
		if (a[i2].sostoyanie == 1)
		{
			a[i2].r = min;
			a[i2].sostoyanie = 0;
		}
	}
	return 0;
}
double rasstoyanie(struct circle p1, struct circle p2)
{
	return sqrt((p2.x-p1.x)*(p2.x-p1.x)+(p2.y-p1.y)*(p2.y-p1.y));
}
