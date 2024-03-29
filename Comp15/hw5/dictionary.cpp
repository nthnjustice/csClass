#include "dictionary.h"

/******************************************************************************
Precondition: Constructor - no precondition
Postconidtion: Sets the root to a new Node, sets the root's pointer to a 
	dynamic array of nodes to a new array of alphabet size, sets the root's
	flag to false, initializes the dynamic array of pointers to NULL
******************************************************************************/
Dictionary::Dictionary()
{
	root = new Node;
	root->children = new Node*[CAPACITY];
	if (root->children == NULL){
		exit(1);
	}
	root->flag = false;

	for (int i = 0; i < CAPACITY; i++){
		root->children[i] = NULL;
	}
	
}

/******************************************************************************
Precondition: A character is passed into the function
Postconidtion: Returns the integer value that corosponds to the character
******************************************************************************/
int Dictionary::charToInt(char c)
{
	return (c - 'a');
}

/******************************************************************************
Precondition: A string is passed into the function
Postconidtion: Inserts the string into the Dictionary and sets the flag
	to true to signal the end of a word
******************************************************************************/
bool Dictionary::insert(string s)
{
	//Holds the size of the string
	int size = s.length();
	//Temporary Node to traverse the trie
	Node* current = root;

	s = convert(s);

	//Loops the size of the string
	for (int i = 0; i < size; i++){
		//Checks to see if the character is a letter
		if (isalpha(s[i])){
			//Current Node of the dynamic array gets a new Node
			current->children[charToInt(s[i])] = new Node;
			if (current->children[charToInt(s[i])] == NULL){
				return false;
			}
			//Sets flag to default
			if (!current->children[charToInt(s[i])]->flag){
				current->children[charToInt(s[i])]->flag = false;
			}
			//Current moves to appropriate Node in the array
			current = current->children[charToInt(s[i])];
			//The Current Node gets a new dynamic array of pointers to Nodes
			current->children = new Node*[CAPACITY];
			if (current->children == NULL){
				return false;
			}
			//Initializes the array to NULL pointers
			for (int i = 0; i < CAPACITY; i++){
				current->children[i] = NULL;
			}
		}
	}	

	//Signal the end of a word
	current->flag = true;

	return true;
}

/******************************************************************************
Precondition: A string is passed into the function to check if the word
	exists in the Dictionary
Postconidtion: Returns true if the string is in the Dictionary, else false
******************************************************************************/
bool Dictionary::isWord(string s)
{
	//Holds the size of the string
	int size = s.length();
	//Temporary Node to traverse the trie
	Node* current = root;

	s = convert(s);

	//Loops the size of the string
	for (int i = 0; i < size; i++){
		//Checks to see if the character is a letter
		if (isalpha(s[i])){
			//Checks to see if the current Node is not NULL
			if (current->children[charToInt(s[i])] != NULL){
				//Moves the current pointer to the appropriate Node
				current = current->children[charToInt(s[i])];
			}
			//If the Node is NULL
			else{
				return false;
			}
		}
	}

	//Checks to see if the Node signals the end of a word
	if (current->flag){
	return true;
	}
	else{
		return false;
	}
}

/******************************************************************************
Precondition: A string is passed into the function to check if it is a prefix
	for any word in the Dictionary
Postconidtion: Returns true if the string is a prefix of any word in the 
	Dictionary, else false
******************************************************************************/
bool Dictionary::isPrefix(string s)
{
	//Holds the size of the string
	int size = s.length();
	//Temporary Node to traverse the trie
	Node* current = root;

	s = convert(s);

	//Tells that an inserted empty string is a prefix
	if ((size == 0) && (isWord(s))){
		return true;
	}

	//Loops the size of the string
	for (int i = 0; i < size; i++){
		//Checks to see if the character is a letter
		if (isalpha(s[i])){
			//Checks to see if the current Node is not NULL
			if (current->children[charToInt(s[i])] != NULL){
				//Moves the current pointer to the appropriate Node
				current = current->children[charToInt(s[i])];
				//Checks to see if the Node signals the end of a word
			}
		}
	}

	if ((current->flag == true) && (isWord(s))){
		return true;
	}

	//Loops through the array of the deepest level
	for (int i = 0; i < CAPACITY; i++){
		//If one Node points to another array the string is a prefix
		if (current->children[i] != NULL){
			return true;
		}
	}
	
	return false;
}


/******************************************************************************
Precondition: Takes a string to convert
Postconidtion: Converts the string to all lower case
******************************************************************************/
string Dictionary::convert(string s)
{
	//Holds the size of the string
	int size = s.length();

	//Converts the string to all lower case values
	for (int i = 0; i < size; i++){
		if (isalpha(s[i])){
			s[i] = tolower(s[i]);
		}
	}

	return s;
}
