
// 1.Jelaskan, mengapa suatu algoritma dibutuhkan untuk menyelesaikan suatu masalah
//      Algoritma terdapat struktur data yang dapat menjadi acuan atau dasar dalam menyelesaikan suatu masalah
// 2.Dalam algoritma, di klasifikasikan menjadi 2 data struktur. Sebutkan 2 data struktur tersebut
//      Quadratic dan Loglinear
// 3.Sebutkan Faktor-Faktor yang mempengaruhi efisiensi suatu program algoritma
//      -Terlalu banyak perintah dalam perulangannya, bisa diakali dengan perintah looping
//      -Penggunaan dan pemanggil fungsi
//      -Variabel yang tidak urut
//      -Meringkas suatu fungsi dan main
// 4.Dari 6 algoritma yang sudah dipelajari. Algoritma manakah yang paling efisien untuk mengurutkan data yang ukurannya kecil. Jelaskan kenapa anda memilih itu
//      Insertion Sort, dimana didalam insertion sort terdapat suatu batasan kondisi sebuah jumlah/panjang data
// 5.Sebutkan dari algoritma yang telah dipelajari mana yang termasuk kedalam Quadratic dan mana yang termasuk kedalam Loglinear
//      Quadratic :
//      -   Quick Sort
//      -   Insertion Sort
//      -   Bubble Sort
//      -   Selection Sort
//      Loglinear :
//      -   Tipe Data
//      -   Prosedur
// 6. Buatlah sebuah program yang mengimplementasikan selection sort menggunakan bahasa c++. Berikut merupakan algorthm selection sort
//      1. Repeat step 2 and 3 varying, j from 0 to n-2
//      2. Find the maximum value in arr[j] to arr[n-1]:
//              a.set min_index = j
//              b.repeat step c varying j+1 to n-1
//              c.if arr[i] < arr [min_index]:
//                  1.min_index = j
//      3. swap arr[i] with arr [min_index]
//     there are additional requirement to create the program :
//        a.the maximum number of data is the sum of the last two digits of your student number +20-2x15+10+20
//        b.change the "y" in the algorithm to the two initials of your name.
//        c.change "arr" with your nicknames

#include <iostream>
using namespace std;

int abra[20];	
int cmp_count = 0; 
int mov_count = 0; 
int n;

void input() {
	while (true)
	{
		cout << "Masukkan panjang element array: ";
		cin >> n;

		if (n <= 1830)
			break;
		else
			cout << "\nMaksimum panjang array adalah 1830" << endl;
	}

	cout << "\n====================" << endl;
	cout << "\nEnter Array element" << endl;
	cout << "\n====================" << endl;

	for (int i = 0; i < n; i++)
	{
		cout << "<" << (i + 1) << ">";
		cin >> abra[i];
	}
}

void swap(int x, int ay)
{
	int temp;

	temp = abra[x];
	abra[x] = abra[ay];
	abra[ay] = temp;
}
void selectionsort(int low, int high)
{
	int pivot, i, j;
	if (low > high)		//langkah algoritma NO.1
		return;

	//partition the list into two parts:
	//one containing elements less that or equal to pivot
	//outher containing elements greather than pivot

	pivot = abra[low];		//Langkah Algoritma No.2

	i = low + 1;			//Langkah Algoritma No.3
	j = high;				//Langkah Algoritma No.4

	while (i <= j)			//Langkah Algoritma No.10
	{
		//search for an element greater than pivot
		while ((abra[i] <= pivot) && (i <= high))		//Langkah Algoritma No.5
		{
			i++;										//Langkah Algoritma No.6
			cmp_count++;
		}
		cmp_count++;

		//search for an element less than or equal to pivot
		while ((abra[j] > pivot) && (j >= low))		//Lngkah Algoritma No.7
		{
			j--;									//Langkah Algoritma No.8
			cmp_count++;
		}
		cmp_count++;

		//if the greater element is on the left of the element
		if (i < j)									//Langkah Algoritma No.9
		{
			//swap the element at index i with the element at index j
			swap(i, j);
			mov_count++;
		}
	}
	//now containt the index of the last element in the sorted list
	if (low < j)									//Langkah Algoritm No.11
	{
		//move the pivot to its correct position in the list
		swap(low, j);
		mov_count++;
	}
	//sort the list on the left of pivot using quick sort
	selectionsort(low, j - 1);							//Langkah Algoritma No.12

	//sort the list on the right of pivot using quick sort
	selectionsort(j + 1, high);							//Langkah Algortma No.13
}

void display() {
	cout << "\n===============" << endl;
	cout << "Sorted Array" << endl;
	cout << "\n===============" << endl;

	for (int i = 0; i < n; i++)
	{
		cout << abra[i] << " ";
	}

	cout << "\n\nNumber of Comparassions: " << cmp_count << endl;
	cout << "Number of data movement: " << mov_count << endl;
}


int main()
{
	input();
	selectionsort(0, n - 2);
	display();
	system("pause");

	return 0;
}
