//1.
//
//Finds the largest value in the array "a" of length "length"
double find_max_in_array(double a[], int length)
{
	double max = a[0];
	for (int i = 1; i < length; ++i)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
	}
	return max;
}
//Tidskomplexitet = O(n)
//Bara en loop i funktionen

//2.
//
// Reverses the string "s" in place, but there is a bug
void incorrect_reverse_string(char* s)
{
	int n = strlen(s);
	for (int i = 0; i < n; ++i)
	{
		char temp = s[i];
		s[i] = s[n - i - 1];
		s[n - i - 1] = temp;
	}
}
//Tidskomplexitet = O(n)
//Bara en loop i funktionen

//3.
//
// Reverses the string "s" in place
void reverse_string(char* s)
{
	int n = strlen(s);
	for (int i = 0; i < n / 2; ++i)
	{
		char temp = s[i];
		s[i] = s[n - i - 1];
		s[n - i - 1] = temp;
	}
}
//Tidskomplexitet = O(n)
//Bara en loop i funktionen

//4.
//
// Compares two arrays of length "length" and returns 1 if they are equal
double arrays_are_equal(double a[], double b[], int length)
{
	for (int i = 0; i < length; ++i)
	{
		if (a[i] != b[i])
		{
			return 0;
		}
	}
	return 1;
}
//Tidskomplexitet = O(n)
//Bara en loop i funktionen

//5.
//
// Returns the sum of how many times each needle occurs in the haystack,
// both arrays of length "length"
int find_number_of_matches(int needles[], int haystack[], int length)
{
	int nr_matches = 0;
	for (int n = 0; n < length; ++n)
	{
		for (int h = 0; h < length; ++h)
		{
			if (needles[n] == haystack[h])
			{
				++nr_matches;
			}
		}
	}
	return nr_matches;
}
//Tidskomplexitet  = O(n^2)
//En nestlad for loop

//6.
//
// Sorts the array "a" of length "length" in ascending order using
//selection sort
void sort_array(double a[], int length)
{
	for (int sorted = 0; sorted < length - 1; ++sorted)
	{
		int smallest_in_rest = sorted;
		for (int in_rest = sorted + 1; in_rest < length; ++in_rest)
		{
			if (a[in_rest] < a[smallest_in_rest])
			{
				smallest_in_rest = in_rest;
			}
		}
		double temp = a[sorted];
		a[sorted] = a[smallest_in_rest];
		a[smallest_in_rest] = temp;
	}
}
//Tidskomplexitet = O(n^2)
//En nestlad for loop

//7.
//
// Returns 1 if the array "a" of length "length" is sorted in ascending
//order
int is_array_sorted(double a[], int length)
{
	for (int i = 0; i < length - 1; ++i)
		if (a[i] > a[i + 1])
			return 0;
	return 1;
}
//Tidskomplexitet = O(n)
//Bara en for loop

//8.
//
// Returns 1 if the array "a" of length "length" is sorted in ascending
//order
int is_array_sorted_2(double a[], int length)
{
	double *copy = malloc(length * sizeof(double));
	memcpy(copy, a, length * sizeof(double));
	sort_array(copy, length);
	int result = arrays_are_equal(a, copy, length);
	free(copy);
	return result;
}
//Tidskomplexitet = O(n^2)
//Funktions anropet sort_array, är den dominerande termen.

//9.
//
// Sorts the array "a" of length "length" in random order
void shuffle_array(double a[], int length) {
	for (int randomized = 0; randomized < length; ++randomized) {
		// Select a random position in the rest of the array
		int selected = randomized + rand() % (length - randomized);
		// Swap the current position with the random position
		double oldvalue = a[randomized];
		a[randomized] = a[selected];
		a[selected] = oldvalue;
	}
}
//Tidskomplexitet = O(n)
//Bara en for loop

//10.
//
// Sorts the array "a" of length "length" in random order, but more thoroughly
void shuffle_array_really_well(double a[], int length) {
	shuffle_array(a, length);
	shuffle_array(a, length);
	shuffle_array(a, length);
}
//Tidskomplexitet = O(n)
//Funktions anropet shuffle_array.

//11.
//
// Sorts the array "a" of length "length" in random order, even more thoroughly
void shuffle_array_really_really_well(double a[], int length) {
	shuffle_array(a, length);
	shuffle_array(a, length);
	shuffle_array(a, length);
	shuffle_array(a, length);
	shuffle_array(a, length);
}
//Tidskomplexitet = O(n)
//Funktions anropet shuffle_array

//12.
//
// Sorts the array "a" of length "length" in random order, ridiculously
//well
void shuffle_array_really_really_really_well(double a[], int length)
{
	for (int i = 0; i < length; ++i)
		shuffle_array(a, length);
}
//Tidskomplexitet = O(n^2)
//Funktions anropet shuffle_array är nestlad i en for loop.

//13.
//
// Sorts the array "a" of length "length" in random order, even more
//ridiculously well
void shuffle_array_really_really_really_really_well(double a[], int length)
{
	shuffle_array(a, length);
	shuffle_array_really_well(a, length);
	shuffle_array_really_really_well(a, length);
	shuffle_array_really_really_really_well(a, length);
}
//Tidskomplexitet = O(n^2)
//Funktions anropet shuffle_array_really_really_really_well, 
//är den dominerande termen

//14.
//
void bogosort_array(double a[], int length)
{
	while (! is_array_sorted(a, length))
		shuffle_array(a, length);
}
//Tidskomplexitet = O(n^3)
//Funktions anropet is_array_sorted är nestlad i while loop, 
//funktions anropet shuffle_array är nestlad i den loopen.

//15.
//
//Nej.