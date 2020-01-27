2
5
5 2 4 3 1
7
-5 -12 87 2 88 20 11

main:
t = 2;
for( i = 0; i < 2; i++)
{
	fprintf(fout, "\nCase #%d", i+1); // i = 0, i + 1 = 1
	solve(&fin, &fout);
}

solve:
N = 5;
for (bi = ci = i = 0; i < 5; i++)//i:0						i:1 			i:2 			i:3 		i:4 			//i:0    		i:1 		i:2 	 	i:3			i:4 	i:5 	i:6
{
	fscanf(*fin, "%d", a + i);	//a[0] = 5					a[1] = 2 		a[2] = 4 		a[3] = 3 	a[4] = 1 		//a[0]:-5 		a[1]:-12  	a[2]:87		2 			88		20 		11
	if(a[i] % 2 != 0) 			//a[0]:5 5 % 2 != 0 		a[1]:2 2%2 = 0 	a[2] 4%2 = 0
		b[bi++] = a[i];			//bi:0 b[0] = a[0] = 5 bi:1 								b[1] = 3 	b[2] = 1 		//b[0] = -5 				b[1] = 87								b[2]:11
	else
		c[ci++] = a[i];			//							c[0] = 2 		c[1] = 4 									//				c[0] = -12 				c[1]:2 		c[2]:88	c[3]:20
} 								//b: 5 3 1 a: 2 4 		//	b: -5 87 11 c: -12 2 88 20
qsort(b, bi, sizeof(b[0]), cmp);//b: 1 3 5			small to bigger					b: -5 11 87
qsort(c, ci, sizeof(c[0]), cmp);//c: 2 4 											c: -12 2 20 88
for(bi = i = 0; i < 5; i++)
{
	fprintf(*fout, "%d", 
		a[i] % 2 != 0 ? b[bi++] : c[--ci]);		//i:0 a[0]:5	i:1 a[1]:2 		i:2 a[2]:4 							//-5 		-12 	87		2 		88   	20  	11
												//b[0]			c[1]			c[0]			b[1]		b[2]	//b[0]		c[3] 	b[1] 	c[2] 	c[1] 	c[0] 	b[2]
}												//1 4 2 3 5 														//-5 88 11 20 2 -12 87