#include <cstdio>
#include <cstring>

char mat[350][32];
int main() {

	FILE *fin = fopen("input.txt", "r");
	if (!fin) {
		fprintf(stderr, "Can't open input\n");
		return 1;
	}

	int nrows = 0;
	while (fscanf(fin, "%s", mat[nrows]) == 1) {
		nrows++;
	}

	int ncols = strlen(mat[0]);

	int res = 0;
	for (int i = 0, j = 0; i < nrows; i++) {
		if (mat[i][j] == '#')
			res++;

		j += 3;
		j = (j < ncols ? j : j - ncols);
	}

	printf("%d\n", res);

	fclose(fin);
	return 0;
}