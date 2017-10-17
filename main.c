#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int i, j, i1, j1, x, k, a, b;
	int min = 2147483647;

	/* 1 (create massive) */
	printf ("Please, enter size of the massive(a b) \n");
	scanf ("%d %d", &a, &b);
	int mas[a][b];
	for (i=0; i<a; i++)
	{
		for (j=0; j<b; j++)
		{
			mas[i][j]=rand() % 100;
		}
	}
	/* print massive */
	for ( i = 0; i < a; i++ )
	{
		for ( j = 0; j < b; j++ )
		{
			printf( "[%d][%d]=%d ", i, j, mas[i][j] );
		}
		printf( "\n" );
	}
	/* 2 */
	printf( "\n" );
	for (j=0; j<b; j++)
	{
		x=mas[0][j];
		mas[0][j]=mas[a-1][b-1-j];
		mas[a-1][b-1-j]=x;
	}
	/*print massive, find minimum element and check it's uniqueness */
	for ( i = 0; i < a; i++ )
	{
		for ( j = 0; j < b; j++ )
		{
			if (mas[i][j]==min)
			{
				k=1;
			}
			if (mas[i][j]<min)
			{
				min=mas[i][j];
				k=0;
				i1=i;
				j1=j;
			}
			printf( "[%d][%d]=%d ", i, j, mas[i][j] );
		} 
		printf( "\n");
	}
	printf( "\n" );
	/* if min elem is alone, then delete column and string with min elem and print new massive */
	if (k==0)
	{
		for (i=0; i<a; i++)
		{
			for (j=0; j<b; j++)
			{
				if (i<i1 && j<j1)
				{
					printf("[%d][%d]=%d ", i, j, mas[i][j] );
				}
				else
				{	
					if (i>i1 && j<j1)
					{
						mas[i-1][j]=mas[i][j];
						printf("[%d][%d]=%d ", i-1, j, mas[i][j] );
					}
					if (j>j1 && i<i1)
					{
						mas[i][j-1]=mas[i][j];
						printf("[%d][%d]=%d ", i, j-1, mas[i][j] );
					}
					if (i>i1 && j>j1)
					{
						mas[i-1][j-1]=mas[i][j];
						printf("[%d][%d]=%d ", i-1, j-1, mas[i][j] );
					}
				}
			}
			printf ("\n");
		}
	}
	/*if min elem is not alone */
	if (k==1)
	{
		printf ("ERROR. Minimum value is not alone. \n");
		return 0;
	}
	/* 4 (create the second massive) */
	printf ("Please, enter the massive. ");
	char text[1000];
	fgets( text, 1000, stdin );
	int a1=0;
	int b1=0;
	while ( text[i] != '\0' )
	{
		switch ( text[i] )
		{
			case ' ':
				b1+=1;
			break;
			case ',':
				a1+=1;
				b1=0;
			break;
			case '.':
			break;
			default:
			break;
		}
		i++;
	}
	int mas1[a1][b1];
	/* fill the massive and print it */
	while ( text[i] != '\0' )
	{
		switch ( text[i] )
		{
			case ' ':
				printf("[%d][%d]=%d ", a1, b1, mas1[a1][b1] );
				b1+=1;
			break;
			case ',':
				printf ( "\n" );
				a1+=1;
				b1=0;
			break;
			case '.':
				printf("[%d][%d]=%d ", a1, b1, mas1[a1][b1] );
			break;
			default:
				mas1[a1][b1]+=text[i];
		}
		i++;
	}
	printf("\n");
	int a2,b2;
	a2=a-1;
	b2=b-1;
	/* 5 (multyply massives) */
	if (b2==a1)
	{
		int matrix[a2][b1],n;
		for (i=0; i<a2; i++)
		{
			for (j=0; j<b1; j++)
			{
				matrix[i][j]=0;
				for (n=0; n<b2; n++)
				{
					matrix[i][j]+=(mas[i][n])*(mas1[n][j]);
				}
				printf ("[%d][%d]=%d ", i,j,matrix[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}
