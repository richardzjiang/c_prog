/* disp: print a 2 dimensional output using the input */
void disp(int hbound, int vbound, char input[]/*, int pixelsize*/)
{
	int x, y;

	for (y = 0; y < vbound; ++y) {
		for (x = 0; x < hbound; ++x)
			printf("%c", input[x,y]);
		putchar('\n');
	}
}
