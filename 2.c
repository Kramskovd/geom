#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EPS 1e-15


struct vec
{
	double x;
	double y;
};

int find_o(struct vec *a, int n);
void sort(struct vec *a, int first, int last, int(*cmp)(struct vec, struct vec, struct vec));
void insert_sort(struct vec *a, int n);

int cmp (struct vec o, struct vec a, struct vec b) {
    return (a.x-o.x)*(b.y-a.y)-(a.y-o.y)*(b.x-a.x);

}

void sort(struct vec *a, int first, int last, int(*cmp)(struct vec, struct vec, struct vec))
{
    int i, j;
    struct vec x,y;

    while(first < last){
        i = first;
        j = last-1;
        x = a[first]; 

        while(i <= j){ 
            while(cmp(a[0], x, a[i]) < 0) i++;
            while(cmp(a[0], x, a[j]) > 0) j--; 

            if(i <= j) {
 
                y = a[i];
                a[i] = a[j];
                a[j] = y;
                i++;j--;
            }
        }

        if(last-first <=2)   
          break;

        if ((i-first) < (last-i)){   
            if (first < i) 
                sort(a, first,i, cmp);
            first = i;
        }else{
            if (i < last-1)
                sort(a, i,last, cmp);  
            last = i; 
        }
	}
}
int find_o(struct vec *a, int n){
    int i, j, m;
    struct vec t;

    m = 0;

    if(n == 2)
        return 2;

    for(i = 1; i < n; i++){
        if(a[i].x < a[m].x){
            m = i;
        }else if((a[i].x - a[m].x < EPS && a[m].x - a[i].x < EPS) && a[i].y < a[m].y){
            m = i;
        }
    }

    t = a[0];
    a[0] = a[m];
    a[m] = t; 

    sort(a, 1, n, cmp);

    j = 1;
    for(i = 2; i < n; i++){
        while( cmp(a[j-1], a[j], a[i]) < 0){
            j--;
        }
        if((a[j].x - a[i].x > EPS || a[i].x - a[j].x > EPS) || (a[j].y - a[i].y > EPS || a[i].y - a[j].y > EPS)){
            j++;
            a[j] = a[i]; 
        }
        
    }


    return ++j;

}