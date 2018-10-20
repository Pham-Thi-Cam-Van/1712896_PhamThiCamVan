#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include<string.h>

#define N1 1000
#define N2 5000
#define N3 10000
#define N4 50000
#define N5 100000
#define N6 250000

int random(int min, int max)
{
	return rand() % (max - min + 1) + min;
}
void mangSorted(int *a, int n)
{
	srand((unsigned int)time(NULL));
	a[0] = { random(0, 10) };
	for (int i = 1; i < n; ++i)
		a[i] = random(a[i - 1], a[i - 1] + 20);
}
void mangReversed(int *a, int n)
{
	srand((unsigned int)time(NULL));
	a[n - 1] = { random(0, 10) };
	for (int i = n - 2; i >= 0; --i)
		a[i] = random(a[i + 1], a[i + 1] - 20);
}
void mangNearlySorted(int *a, int n)
{
	srand((unsigned int)time(NULL));
	a[0] = { random(0, 10) };
	for (int i = 1; i < n; ++i)
		a[i] = random(a[i - 1] - 5, a[i - 1] + 10);
}
void mangRandom(int *a, int n)
{
	srand((unsigned)time(NULL));
	for (int i = 0; i < n; i++)
		a[i] = rand() % n;
}
void chepMang(int *a, int *state, int n)
{
	for (int i = 0; i < n; i++)
		state[i] = a[i];
}
void xuatMang(int *a, int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}
void swap(int &a, int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}
void SelectionSort(int *a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[min]>a[j])
				min = j;
		}
		swap(a[min], a[i]);
	}
}
void InterchangeSort(int *a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[min]>a[j])
				swap(a[min], a[j]);
		}
	}
}
void InsertionSort(int *a, int n)
{
	int x, j;
	for (int i = 1; i < n; i++)
	{
		x = a[i];
		j = i - 1;
		while (j >= 0 && a[j]>x)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = x;
	}
}
void BubbleSort(int *a, int n)
{
	for (int i = 0; i < n-1; i++)
	{
		for (int j = n - 1; j > i; j--)
		{
			if (a[j - 1]>a[j])
			{
				swap(a[j - 1], a[j]);
			}
		}
	}
}
void ShakerSort(int *a, int n)
{
	int l = 0, r = n - 1, i;
	while (l < r)
	{
		for (i = r; i>l; i--)
		{
			if (a[i - 1] > a[i])
			{
				swap(a[i], a[i - 1]);
			}
		}
		for (i = l + 1; i < r; i++)
		{
			if (a[i + 1] < a[i])
			{
				swap(a[i], a[i + 1]);
			}
		}
		l++;
		r--;
	}
}
void ShellSort(int *a, int n)
{
	int h = n / 2, i;
	while (h > 0)
	{
		i = h;
		while (i < n)
		{
			for (int j = i - h; j >= 0; j = j - h)
			{
				if (a[j]>a[j + h])
				{
					swap(a[j], a[j + h]);
				}
			}
			i++;
		}
		h = h / 2;
	}
}
void QuickSort(int *a, int l, int r)
{
	if (l >= r) return;
	int x = a[(l + r) / 2], i = l, j = r;
	while (i <= j)
	{
		while (a[i] < x)
		{
			i++;
		}
		while (a[j] > x)
		{
			j--;
		}
		if (i <= j){
			{
				swap(a[i], a[j]);
				i++; j--;
			}
		}
	}
	QuickSort(a, l, j);
	QuickSort(a, i, r);
}
void Merge(int *a, int l, int t, int r)
{
	int *c;
	c = (int*)malloc((r + 1)*sizeof(int));
	int p = l, i = l, j = t + 1;
	while (i <= t&&j <= r){
		if (a[i] < a[j]){
			c[p] = a[i];
			i++;
		}
		else{
			c[p] = a[j];
			j++;
		}
		p++;
	}
	while (i <= t){
		c[p] = a[i];
		i++;
		p++;
	}
	while (j <= r){
		c[p] = a[j];
		j++;
		p++;
	}
	for (i = l; i <= r; i++)
	{
		a[i] = c[i];
	}
	free(c);
}
void MergeSort(int *a, int l, int r)
{
	if (l >= r) return;
	int t = (l + r) / 2;
	MergeSort(a, l, t);
	MergeSort(a, t + 1, r);
	Merge(a, l, t, r);
}
void taoHeap(int *a, int n)
{
	int i, x, r;
	for (i = 1; i < n; i++)
	{
		x = a[i];
		r = i;
		while (r>0)
		{
			if (a[r] > a[(r - 1) / 2])
			{
				a[r] = a[(r - 1) / 2];
				r = (r - 1) / 2;
				a[r] = x;
			}
			else
			{
				r = (r - 1) / 2;
			}
		}
	}
}
void chinhHeap(int *a, int n)
{
	int i, j, r, x;
	for (i = n - 1; i >= 1; i--)
	{
		x = a[i];
		r = 0;
		j = r * 2 + 1;
		a[i] = a[0];
		while (j < i)
		{
			if (j + 1 < i&&a[j + 1] > a[j])
			{
				j++;
			}
			if (x < a[j])
			{
				a[r] = a[j];
				r = j;
				j = 2 * r + 1;
			}
			else break;
		}
		a[r] = x;
	}
}
void HeapSort(int *a, int n)
{
	taoHeap(a, n);
	chinhHeap(a, n);
}
void RadixSort(int *a, int n)
{
	int max = a[0], i, j, h = 1;
	int *c;
	c = (int*)malloc(n*sizeof(int));
	for (i = 1; i < n; i++)
	{
		if (a[i]>max)
		{
			max = a[i];
		}
	}
	while (max / h != 0)
	{
		int b[10] = { 0 };
		for (i = 0; i < n; i++)
		{
			b[a[i] / h % 10]++;

		}
		for (i = 1; i < 10; i++)
		{
			b[i] += b[i - 1];
		}
		for (i = n - 1; i >= 0; i--)
		{
			c[--b[a[i] / h % 10]] = a[i];
		}

		for (i = 0; i < n; i++)
		{
			a[i] = c[i];
		}
		h = h * 10;
	}
	free(c);
}
void ghiMang(int *a, int n, char* tenFile)
{
	FILE* fp = fopen(tenFile, "wt");
	for (int i = 0; i < n; i++)
	{
		fprintf(fp, "%d  ", a[i]);
	}
	fclose(fp);
}

void ghiFileIn(int *a, int n, char state[], char size[])
{
	strcat(state, "_");
	strcat(state, size);
	strcat(state, ".inp");
	ghiMang(a, n, state);
	int i = strlen(state);
	state[i - 4] = '\0';
}
void ghiFileOut(int *a, int n, char sort[], char state[])
{
	strcat(sort, "_");
	strcat(sort, state);
	strcat(sort, ".out");
	ghiMang(a, n, sort);
}
void xuatFile(int *a, int n, char state[], double tGian[], int &ptTGian)
{
	ptTGian = 0;
	clock_t start, end;
	int *ttMang = new int[n];
	chepMang(a, ttMang, n);
	char str1[50] = "SelectionSort";
	char str2[50] = "InterchangeSort";
	char str3[50] = "InsertionSort";
	char str4[50] = "BubbleSort";
	char str5[50] = "ShakerSort";
	char str6[50] = "ShellSort";
	char str7[50] = "QuickSort";
	char str8[50] = "MergeSort";
	char str9[50] = "HeapSort";
	char str10[50] = "RadixSort";
	start = clock();
	SelectionSort(a, n);
	end = clock();
	tGian[ptTGian] = (double)(end - start);
	ptTGian++;
	ghiFileOut(a, n, str1, state);
	chepMang(ttMang, a, n);
	start = clock();
	InterchangeSort(a, n);
	end = clock();
	tGian[ptTGian] = (double)(end - start);
	ptTGian++;
	ghiFileOut(a, n, str2, state);
	chepMang(ttMang, a, n);
	start = clock();
	InsertionSort(a, n);
	end = clock();
	tGian[ptTGian] = (double)(end - start);
	ptTGian++;
	ghiFileOut(a, n, str3, state);
	chepMang(ttMang, a, n);
	start = clock();
	BubbleSort(a, n);
	end = clock();
	tGian[ptTGian] = (double)(end - start);
	ptTGian++;
	ghiFileOut(a, n, str4, state);
	chepMang(ttMang, a, n);
	start = clock();
	ShakerSort(a, n);
	end = clock();
	tGian[ptTGian] = (double)(end - start);
	ptTGian++;
	ghiFileOut(a, n, str5, state);
	chepMang(ttMang, a, n);
	start = clock();
	ShellSort(a, n);
	end = clock();
	tGian[ptTGian] = (double)(end - start);
	ptTGian++;
	ghiFileOut(a, n, str6, state);
	chepMang(ttMang, a, n);
	start = clock();
	QuickSort(a, 0, n - 1);
	end = clock();
	tGian[ptTGian] = (double)(end - start);
	ptTGian++;
	ghiFileOut(a, n, str7, state);
	chepMang(ttMang, a, n);
	start = clock();
	MergeSort(a, 0, n - 1);
	end = clock();
	tGian[ptTGian] = (double)(end - start);
	ptTGian++;
	ghiFileOut(a, n, str8, state);
	chepMang(ttMang, a, n);
	start = clock();
	HeapSort(a, n);
	end = clock();
	tGian[ptTGian] = (double)(end - start);
	ptTGian++;
	ghiFileOut(a, n, str9, state);
	chepMang(ttMang, a, n);
	start = clock();
	RadixSort(a, n);
	end = clock();
	tGian[ptTGian] = (double)(end - start);
	ptTGian++;
	ghiFileOut(a, n, str10, state);
	delete[]ttMang;
}

void ghiFileCSV(int *a, int n, char* tenFile, double tGian[], int ptTGian, char sortAlg[])
{
	FILE* fp = fopen(tenFile, "at");
	fprintf(fp, "%s,%d,", sortAlg, n);
	for (int i = 0; i < ptTGian - 1; i++)
	{
		fprintf(fp, "%lf,", tGian[i]);
	}
	fprintf(fp, "%lf\n", tGian[ptTGian - 1]);
	fclose(fp);
}
void main()
{
	FILE *fp = fopen("Result.csv", "wt");
	fprintf(fp, "Input State,Input Size,Selection,Interchange,Insertion,Bubble,Shaker,Shell,Quick,Merge,Heap,Radix\n");
	fclose(fp);
	double tGian[15];
	int ptTGian;
	//MANG DA CO THU TU SORTED
	char state1[50] = "Sorted";
	//N1=1000
	int n = N1;
	int *a = new int[n];
	mangSorted(a, n);
	ghiFileIn(a, n, state1, "1000");
	xuatFile(a, n, state1, tGian, ptTGian);
	int len = strlen(state1);
	state1[len - 5] = '\0';
	ghiFileCSV(a, n, "Result.csv", tGian, ptTGian, state1);
	//N1=5000
	n = N2;
	a = new int[n];
	mangSorted(a, n);
	ghiFileIn(a, n, state1, "5000");
	xuatFile(a, n, state1, tGian, ptTGian);
	state1[len - 5] = '\0';
	ghiFileCSV(a, n, "Result.csv", tGian, ptTGian, state1);
	//N1=10000
	n = N3;
	a = new int[n];
	mangSorted(a, n);
	ghiFileIn(a, n, state1, "10000");
	xuatFile(a, n, state1, tGian, ptTGian);
	state1[len - 5] = '\0';
	ghiFileCSV(a, n, "Result.csv", tGian, ptTGian, state1);
	//N1=50000
	n = N4;
	a = new int[n];
	mangSorted(a, n);
	ghiFileIn(a, n, state1, "50000");
	xuatFile(a, n, state1, tGian, ptTGian);
	state1[len - 5] = '\0';
	ghiFileCSV(a, n, "Result.csv", tGian, ptTGian, state1);
	//N1=100000
	n = N5;
	a = new int[n];
	mangSorted(a, n);
	ghiFileIn(a, n, state1, "100000");
	xuatFile(a, n, state1, tGian, ptTGian);
	state1[len - 5] = '\0';
	ghiFileCSV(a, n, "Result.csv", tGian, ptTGian, state1);
	//N1=250000
	n = N6;
	a = new int[n];
	mangSorted(a, n);
	ghiFileIn(a, n, state1, "250000");
	xuatFile(a, n, state1, tGian, ptTGian);
	state1[len - 5] = '\0';
	ghiFileCSV(a, n, "Result.csv", tGian, ptTGian, state1);
	//MANG CO THU TU NGUOC REVERSED
	char state2[50] = "Reversed";
	//N1=1000
	n = N1;
	a = new int[n];
	mangReversed(a, n);
	ghiFileIn(a, n, state2, "1000");
	xuatFile(a, n, state2, tGian, ptTGian);
	len = strlen(state2);
	state2[len - 5] = '\0';
	ghiFileCSV(a, n, "Result.csv", tGian, ptTGian, state2);
	//N1=5000
	n = N2;
	a = new int[n];
	mangReversed(a, n);
	ghiFileIn(a, n, state2, "5000");
	xuatFile(a, n, state2, tGian, ptTGian);
	state2[len - 5] = '\0';
	ghiFileCSV(a, n, "Result.csv", tGian, ptTGian, state2);
	//N1=10000
	n = N3;
	a = new int[n];
	mangReversed(a, n);
	ghiFileIn(a, n, state2, "10000");
	xuatFile(a, n, state2, tGian, ptTGian);
	state2[len - 5] = '\0';
	ghiFileCSV(a, n, "Result.csv", tGian, ptTGian, state2);
	//N1=50000
	n = N4;
	a = new int[n];
	mangReversed(a, n);
	ghiFileIn(a, n, state2, "50000");
	xuatFile(a, n, state2, tGian, ptTGian);
	state2[len - 5] = '\0';
	ghiFileCSV(a, n, "Result.csv", tGian, ptTGian, state2);
	//N1=100000
	n = N5;
	a = new int[n];
	mangReversed(a, n);
	ghiFileIn(a, n, state2, "100000");
	xuatFile(a, n, state2, tGian, ptTGian);
	state2[len - 5] = '\0';
	ghiFileCSV(a, n, "Result.csv", tGian, ptTGian, state2);
	//N1=250000
	n = N6;
	a = new int[n];
	mangReversed(a, n);
	ghiFileIn(a, n, state2, "250000");
	xuatFile(a, n, state2, tGian, ptTGian);
	state2[len - 5] = '\0';
	ghiFileCSV(a, n, "Result.csv", tGian, ptTGian, state2);
	//MANG CO THU TU NGAU NHIEN RANDOM
	char state3[50] = "Random";
	//N1=1000
	n = N1;
	a = new int[n];
	mangRandom(a, n);
	ghiFileIn(a, n, state3, "1000");
	xuatFile(a, n, state3, tGian, ptTGian);
	len = strlen(state3);
	state3[len - 5] = '\0';
	ghiFileCSV(a, n, "Result.csv", tGian, ptTGian, state3);
	//N1=5000
	n = N2;
	a = new int[n];
	mangRandom(a, n);
	ghiFileIn(a, n, state3, "5000");
	xuatFile(a, n, state3, tGian, ptTGian);
	state3[len - 5] = '\0';
	ghiFileCSV(a, n, "Result.csv", tGian, ptTGian, state3);
	//N1=10000
	n = N3;
	a = new int[n];
	mangRandom(a, n);
	ghiFileIn(a, n, state3, "10000");
	xuatFile(a, n, state3, tGian, ptTGian);
	state3[len - 5] = '\0';
	ghiFileCSV(a, n, "Result.csv", tGian, ptTGian, state3);
	//N1=50000
	n = N4;
	a = new int[n];
	mangRandom(a, n);
	ghiFileIn(a, n, state3, "50000");
	xuatFile(a, n, state3, tGian, ptTGian);
	state3[len - 5] = '\0';
	ghiFileCSV(a, n, "Result.csv", tGian, ptTGian, state3);
	//N1=100000
	n = N5;
	a = new int[n];
	mangRandom(a, n);
	ghiFileIn(a, n, state3, "100000");
	xuatFile(a, n, state3, tGian, ptTGian);
	state3[len - 5] = '\0';
	ghiFileCSV(a, n, "Result.csv", tGian, ptTGian, state3);
	//N1=250000
	n = N6;
	a = new int[n];
	mangRandom(a, n);
	ghiFileIn(a, n, state3, "250000");
	xuatFile(a, n, state3, tGian, ptTGian);
	state3[len - 5] = '\0';
	ghiFileCSV(a, n, "Result.csv", tGian, ptTGian, state3);
	// MANG GAN NHU CO THU TU NEARLY SORTED
	char state4[50] = "NearlySorted";
	//N1=1000
	n = N1;
	a = new int[n];
	mangNearlySorted(a, n);
	ghiFileIn(a, n, state4, "1000");
	xuatFile(a, n, state4, tGian, ptTGian);
	len = strlen(state4);
	state4[len - 5] = '\0';
	ghiFileCSV(a, n, "Result.csv", tGian, ptTGian, state4);
	//N1=5000
	n = N2;
	a = new int[n];
	mangNearlySorted(a, n);
	ghiFileIn(a, n, state4, "5000");
	xuatFile(a, n, state4, tGian, ptTGian);
	state4[len - 5] = '\0';
	ghiFileCSV(a, n, "Result.csv", tGian, ptTGian, state4);
	//N1=10000
	n = N3;
	a = new int[n];
	mangNearlySorted(a, n);
	ghiFileIn(a, n, state4, "10000");
	xuatFile(a, n, state4, tGian, ptTGian);
	state4[len - 5] = '\0';
	ghiFileCSV(a, n, "Result.csv", tGian, ptTGian, state4);
	//N1=50000
	n = N4;
	a = new int[n];
	mangNearlySorted(a, n);
	ghiFileIn(a, n, state4, "50000");
	xuatFile(a, n, state4, tGian, ptTGian);
	state4[len - 5] = '\0';
	ghiFileCSV(a, n, "Result.csv", tGian, ptTGian, state4);
	//N1=100000
	n = N5;
	a = new int[n];
	mangNearlySorted(a, n);
	ghiFileIn(a, n, state4, "100000");
	xuatFile(a, n, state4, tGian, ptTGian);
	state4[len - 5] = '\0';
	ghiFileCSV(a, n, "Result.csv", tGian, ptTGian, state4);
	//N1=250000
	n = N6;
	a = new int[n];
	mangNearlySorted(a, n);
	ghiFileIn(a, n, state4, "250000");
	xuatFile(a, n, state4, tGian, ptTGian);
	state4[len - 5] = '\0';
	ghiFileCSV(a, n, "Result.csv", tGian, ptTGian, state4);
	printf("Ket qua da duoc luu vao file\n");
	delete[]a;
}