struct pt {
	double x, y;
};

int cmp (struct pt a, struct pt b) {
	return a.x < b.x || a.x == b.x && a.y < b.y;
}

int cw (struct pt a, struct pt b, struct pt c) {
	return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
}

int ccw (struct pt a, struct pt b, struct pt c) {
	return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
}

void sort(struct pt *a, int first, int last, int(*cmp)(struct pt, struct pt));
void sort(struct pt *a, int first, int last, int(*cmp)(struct pt, struct pt))
{
    int i, j;
    struct pt x;

    while(first < last){
        i = first;
        j = last-1;
        x = a[first]; 

        while(i <= j){ 
            while(cmp(a[i], x) == 0) i++;
            while(cmp(a[j], x) == 1) j--; 

            if(i <= j) {
                swap(a+i, a+j);
                i++;j--;
            }
        }

        if(last-first <=2)   
          break;

        if ((i-first) < (last-i)){   
            if (first < i) 
                quick_sort(a, first,i);
            first = i;
        }else{
            if (i < last-1)
                quick_sort(a, i,last);  
            last = i; 
        }
	}
}

void convex_hull (struct pt *a, int n) {
	struct pt p1, p2;
    
    if (n == 1)  return;

	sort (a, 0, n, &cmp);
	
    p1 = a[0];
    p2 = a[n-1];

    struct pt *up;
    struct pt *down;

	up.push_back (p1);
	down.push_back (p1);

	for (size_t i=1; i<a.size(); ++i) {
		if (i==a.size()-1 || cw (p1, a[i], p2)) {
			while (up.size()>=2 && !cw (up[up.size()-2], up[up.size()-1], a[i]))
				up.pop_back();
			up.push_back (a[i]);
		}
		if (i==a.size()-1 || ccw (p1, a[i], p2)) {
			while (down.size()>=2 && !ccw (down[down.size()-2], down[down.size()-1], a[i]))
				down.pop_back();
			down.push_back (a[i]);
		}
	}
	a.clear();
	for (size_t i=0; i<up.size(); ++i)
		a.push_back (up[i]);
	for (size_t i=down.size()-2; i>0; --i)
		a.push_back (down[i]);
}