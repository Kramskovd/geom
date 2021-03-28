#include <stdio.h>
#include <stdlib.h>

struct vec
{
	double x;
	double y;
};

int programm(struct vec *a, int n);
int find_o(struct vec *a, int n);

int main(void)
{
	FILE *fi, *fo;
    struct vec *a;
    int n, i;

    fi = fopen("input.txt", "r");
    if (!fi){
        fprintf(stderr, "Can't open input.txt...\n");
        return -1;
    }

    if (fscanf(fi, "%d", &n) != 1){ 
        fprintf(stderr, "Can't read parametr 'n'...\n");
        fclose(fi);
        return -1;
    }
	
	if (n <= 1){
        fprintf(stderr, "Wrong parametr 'n'...\n");
        fclose(fi);
        return -1;
	}
	
	a = malloc(sizeof(struct vec)*n); 
	
	if (!a){
		fprintf(stderr, "Memory allocation error...\n");
        fclose(fi);
        return -1;
    }
	
	for (i=0; i < n; i++)
		if (fscanf(fi, "%lf %lf", &(a[i].x), &(a[i].y)) != 2){
			fprintf(stderr, "Can't read element..\n");
            fclose(fi);
            free(a);
            return -1;
		}

	if (fscanf(fi, "%d", &n)!= EOF){
		fprintf(stderr, "Wrong input data..\n");
        fclose(fi);
        free(a);
        return -1;
	}
	fclose(fi);
	n = find_o(a, n);
	fo = fopen("output.txt", "w");
	if(!fo)
	{
		fprintf(stderr, "Can't open output.txt...\n");
		return -1;
	}

	for (i = 0; i < n; i++) 
    	{
	    fprintf(fo,"%d) (%lf, %lf) \n", i+1, a[i].x, a[i].y);

    	}

	free(a);
	return 0;
}
