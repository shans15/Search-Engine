// Sarthak Hans
// Project 2 - Search Engine: Building a document search engine that can locate relevant pages for a user's query with a super-fast response time using the map and set abstractions.

#pragma once

#include <iostream>
#include <set>
#include <map>
#include <sstream>
#include <fstream>
#include <algorithm>

using namespace std;

// Milestone 1
// cleanToken() - extracts all punctuations from the beginning and end of a string
string cleanToken(string s) {
    for (long unsigned int i = 0; i < s.length(); i++) {  // entire string to lowercase
    s[i] = tolower(s[i]);
  }
  while (ispunct(s[0])) {  // removing beginning punctuations
    s.erase(s.begin());
  } 
  int size2 = s.length();  // size 2 after removing beginning punctuations
  for (int i = size2 - 1; i >= 0; i--) {  // removing ending punctuations
    if (ispunct(s[i])) {
      s.pop_back();
    } else {
      break;
    }
  }
  int final_size = s.length(), alpha = 0;  // final size after both
  for (int i = 0; i < final_size; i++) {  // checking if it contains an alphabet
    if (isalpha(s[i])) {
      alpha = 1;
      break;
    }
  }
  if (alpha == 0) {
    return "";
  } else {
    return s;
  }
}

// Milestone 2
// gatherTokens() - extracts the set of unique tokens from the body text
set<string> gatherTokens(string text) {
  set<string> tokens;
  string phrase, clean, empty = "";
  
  stringstream parser(text);
  while (parser >> phrase) {
    clean = cleanToken(phrase);
    if (clean != empty) {
      tokens.insert(clean);
    }
  }
  return tokens;
}


// Milestone 3
// buildIndex() - reads the content from the database file and processes it into the form of an inverted index
int buildIndex(string filename, map<string, set<string>>& index) {
  ifstream readFile;
  readFile.open(filename);
  if (!readFile.is_open()) {
    return 0;
  } else {
    int num = 0;
    string url, keyword;

    while (!readFile.eof()) {
      getline(readFile, url);
      if (url == "") {  // to avoid any extra stored
        break;
      }
      getline(readFile, keyword, '\n');
      set<string> tokens = gatherTokens(keyword);
      
      for (string s : tokens) {
        index[s].insert(url);
      }
      num = num + 1;
    }
    return num;
  }
}

// Milestone 4
// union_loop() - helper function that finds based on ' ' / OR
void union_loop(map<string, set<string>>& index, string keyword, set<string>& result) {
  string url;
  for (string url : index[keyword]) {
    result.insert(url);
  }
}

// intersect_difference() - helper function that either intesects two sets or finds the difference of two sets
void intersect_difference(char val, set<string>& temp, set<string>& result) {
  if (val == '+') {
    set<string> intersect;
    set_intersection(result.begin(), result.end(), temp.begin(), temp.end(), std::inserter(intersect, intersect.begin()));
    
    result = intersect;
  } else if (val == '-') {
    set<string> difference;
    set_difference(result.begin(), result.end(), temp.begin(), temp.end(), std::inserter(difference, difference.begin()));
    
    result = difference;
  }
}


// findQueryMatches() - finding the URL's of a single or compound terms searched from the loaded database
set<string> findQueryMatches(map<string, set<string>>& index, string sentence) {
  set<string> result;
  string keyword, url, clean;
  stringstream parser(sentence);
  while (parser >> keyword) {
    char val = keyword[0];
    if (val == '+') {
      keyword = keyword.erase(0,1);  // removing '+'
      keyword = cleanToken(keyword);
      
      set<string> temp;
      union_loop(index, keyword, temp);
      intersect_difference(val, temp, result);
      
    } else if (val == '-') {
      keyword = keyword.erase(0,1);  // removing '-'
      keyword = cleanToken(keyword);

      set<string> temp;
      union_loop(index, keyword, temp);
      intersect_difference(val, temp, result);
      
    } else {
      keyword = cleanToken(keyword);
      union_loop(index, keyword, result);
    }
  }
  return result;
}

// searchEngine() - constructs inverted index, determines # of webpages processed, and finally finds matching pages of a user-prompted search and returns the urls
void searchEngine(string filename) {
  cout << "Stand by while building index..." << endl;
  set<string> result;
  map<string, set<string>> index;
  int web = buildIndex(filename, index);
  string input;

  map<string, set<string>>::iterator itr;
  set<string> temp;

  cout << "Indexed " << web << " pages containing " << index.size() << " unique terms"   << endl;
  
  cout << endl;
  cout << "Enter query sentence (press enter to quit): ";
  getline(cin, input);
  if (input == "") {
      cout << "Thank you for searching!";
      exit(0);
  }
  while (input != "\n") {
      result = findQueryMatches(index, input);
      cout << "Found " << result.size() << " matching pages" << endl;
      for (string s : result) {  // prints out each result
          cout << s << endl;
      }
      cout << endl;
      cout << "Enter query sentence (press enter to quit): ";
      getline(cin, input, '\n');
    
      if (input == "") {
      cout << "Thank you for searching!";
      exit(0);
      }
  }
}

// creative function
// finding similar terms, specifically 'section' in index to help with searches
void Stemming_CreativeFunction() {
  string filename;
  map<string, set<string>> creative_index;
  cout << "Enter filename: ";
  getline(cin, filename);
  int num = buildIndex(filename, creative_index);
  string sentence;
  cout << "Enter query sentence (press enter to quit): ";
  getline(cin, sentence);

  if (sentence == "") {
    cout << "Thank you for searching!";
    return;
  }
  set<string> result = findQueryMatches(creative_index, sentence);
  if (result.size() == 0) {
    cout << "Couldn't find search based on " << sentence << endl;
    cout << "Trying related searches..." << endl;
    string word = sentence + 's';  // specifically for words like 'sections'
    
    creative_index[sentence]=creative_index[word];  // modifying the key
    creative_index.erase(word);  // erasing the other key
    result = findQueryMatches(creative_index, sentence);
  }
  for (string s : result) {
    cout << s << endl;
  }
}