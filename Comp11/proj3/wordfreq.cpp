/*****************************************************************************
name: wordfreq.cpp
purpose:  implementation of a FrequenyTable, this program reads in data,
          alphabetizes all of the strings, and counts and prints the number
          of times each string is present in the data
usage: Function relies on implementation of FrequencyTable1.cpp and
        FrequencyTable2.cpp
input: data as a series of strings
output: alphabetized list of the strings with a frequency counter before each
        piece of data
note: this program requies that the used funnel a file with test data
by: Nathan Justice
modified: 4/19/13
*****************************************************************************/

#include <iostream>
using namespace std;

#include "FrequencyTable.h"

FrequencyTable maketable(FrequencyTable table);
void print(FrequencyTable table);

int main()
{
  FrequencyTable table;

  table = maketable(table);

  print(table);

  table.destroy();

  return 0;
}

/******************************************************************************
purpose: reads in data from a file
input: a class of type FrequencyTable, includes all the private and public
        variables and functions
returns: a class of type FrequencyTable
*****************************************************************************/
FrequencyTable maketable(FrequencyTable table)
{
  string word;
  int size;

  while(cin >> word){//reads in strings until there is no more data
    size = word.size();

      for(int i = 0; i < size; i++){
	word[i] = tolower(word[i]);//lowercases the word
      }

      if(isalpha(word[0])){
        table.insert(word);
      }
  }

  return table;
}

/******************************************************************************
purpose: prints a Frequency Table built from the maketable() function, this
          function first prints out the frequency of each word in the list,
          followed by the word in alphabetical order.
input: a table of class FrequencyTable
returns: n/a
*****************************************************************************/
void print(FrequencyTable table)
{
  int size = table.size();
  string word;
  int freq;

  for(int i = 0; i < size; i++){
    table.get(i, &word, &freq);//gets pointers to the Nodes
    cout << freq << " " << word << endl;
  }
}


