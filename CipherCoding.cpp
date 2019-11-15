// Section 002
// Sunday, March 11, 2018
// Project 06

#include <iostream>
using std::cout; using std::cin; using std::endl;
#include <string>
using std::string; using std::to_string;
#include <sstream>
using std::stringstream;
#include <vector>
using std::vector;
#include <cmath>
using std::pow;
#include <numeric>
using std::accumulate;
#include <algorithm>
using std::reverse;

// Converts every element in a vector to a string.
string vec_2_str(const vector<long>& v)
{
	std::stringstream ss;
	// Iterate through the vector.
	for (size_t i = 0; i < v.size(); ++i)
	{
		// Check if i is at the beginning of the vector.
		if (i != 0)
		{
			// If not, put a comma in between the elements.
			ss << ",";

		}
		//Output the elements in the vector. 
		ss << v[i];
	}
	// Convert the vector to a string.
	std::string s = ss.str();
	return s;
}
// Creates a nacci sequence.
vector<long> gen_nstep_vector(long limit, long nstep)
{	std::vector<long> fib;
	long nxt_n = 0;
	long nxt_x=0;
	long j = 0;
	fib.push_back(1);
	// Iterate through the vector.
	for (unsigned int i = 0; i < nstep-1; i++)
	{
		// Add the seed numbers into the vector.
		nxt_n = std::pow(2, i);
		fib.push_back(nxt_n);
	}
	// Add all the numbers from the beginning to the end, according to amount of seed numbers needed. 
	while (nxt_x <= limit)
	{
		nxt_x = std::accumulate(fib.begin()+j, fib.begin()+(nstep+j), 0);
		fib.push_back(nxt_x);
		j++;
	}
	// Remove the last element of the vector.
	fib.pop_back();
	return fib;
}
// Creates an encoded binary using a nacci sequence.
string num_to_nstep_coding(long num, long nstep)
{
	std::vector<long> g;
	std::string n;
	long val;
	// Create a nacci sequence.
	g = gen_nstep_vector(num, nstep);
	// Reverse the nacci sequence.
	std::reverse(g.begin(), g.end());
	val = 0;
	// Get the number to compare.
	num = num - g[0];
	// Iterate through the nacci sequence.
	for (size_t i = 0; i < g.size()-1; i++)
	{
		// If a number in the nacci sequence is greater than the comparative number,
		if ( g[i] <= num)
		{
			//subtract the comparative number from the nacci number.
			num = num - g[i];
			// Add a 1 to the binary code string.
			val = 1;
			n += std::to_string(val);
		}
		// For all other instances, add a 0 to the binary code string.
		else
		{
			val = 0;
			n += std::to_string(val);
		}
	}
	n[0] = '1';
	std::reverse(n.begin(), n.end());
	return n;
}
// Finds the sum using the binary coding of a nacci sequence.
long nstep_coding_to_num(const string& coding, const vector<long>& nstep_sequence)
{
	long sum = 0;
	// Iterate through the binary coding.
	for (size_t i = 0; i <= coding.size(); i++)
	{
		// If a value in the binary coding string is 1, 
		if (coding[i] == '1')
		{
			// add the corresponding number in the vector to the sum.
			sum += nstep_sequence[i+1];
		}
	}
	return sum;
}