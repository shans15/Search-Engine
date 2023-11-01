// TODO: remove and replace this file header comment
// This is a .cpp file you will edit and turn in.

// Remove starter comments and add your own
// comments on each function and on complex code sections.

#include <iostream>
#include "search.h"
using namespace std;

int main() {
    
  // Use this function to call and test the functions you write inside of
  // search.h.  If you do not call the functions here, nothing will run.

  
  // cout << "milestone 1" << endl;
  // // test 1: basic testing
  // string ans = "hello";
  // cout << "1. " << (ans == cleanToken(".hello")) << endl;
  // cout << "2. " << (ans == cleanToken("...hello")) << endl;
  // // test 2: more punctuations and case sensitive
  // string ans2 = "smile";
  // cout << "3. " << (ans2 == cleanToken(";)smile;)")) << endl;
  // cout << "4. " << (ans2 == cleanToken("SmiLe!,.")) << endl;
  // // test 3: empty string if no alphabets
  // string ans3 = "";
  // cout << "5. " << (ans3 == cleanToken("45673;")) << endl;
  // cout << "6. " << (ans3 == cleanToken("-1.2;3'4}")) << endl;

  // string ans4 = "i'm";
  // cout << "7. " << (ans4 == cleanToken("$$i'm^")) << endl;
  // cout << "8. " << (ans4 == cleanToken("..i'm")) << endl;

  // string ans5 = "h.e.l.l.o";
  // string val = cleanToken(".h.e.l.l.o.");
  // cout << "9. " << (ans5 == cleanToken(".h.e.l.l.o.")) << endl;

  // string ans6 = "the";
  // string val2 = cleanToken(".the");
  // cout << "10. " << (ans6 == val2) << endl;
  
  // cout << endl<< "milestone 2" << endl;
  // // test 1: basic testing
  // set<string> tokens = gatherTokens("to be or not to be");
  // set<string> tokensANS;
  // tokensANS.insert("to");
  // tokensANS.insert("be");
  // tokensANS.insert("or");
  // tokensANS.insert("not");
  // cout << "1. " << (tokens.size() == 4) << endl;
  // cout << "2. " << (tokens == tokensANS) << endl;
  
  // // test 2: testing a famous quote
  // set<string> tokens2 = gatherTokens("\"Maybe my pain was motivation.\" -Lebron James");
  // set<string> tokensANS2;
  // tokensANS2.insert("maybe");
  // tokensANS2.insert("my");
  // tokensANS2.insert("pain");
  // tokensANS2.insert("was");
  // tokensANS2.insert("motivation");
  // tokensANS2.insert("lebron");
  // tokensANS2.insert("james");
  // set<string> tokens2_1 = gatherTokens("maybe my pain was motivation lebron james");  // testing to see if they both result the same
  // cout << "3. " << (tokens2.size() == 7) << endl;
  // cout << "4. " << (tokens2 == tokensANS2) << endl;
  // cout << "5. " << (tokens2 == tokens2_1) << endl;

  // // test 3: testing a sentence filled with random punctuations
  // set<string> tokens3 = gatherTokens("Hi! Sarthak,:- @[]^bYe?#$%&");
  // set<string> tokensANS3;
  // tokensANS3.insert("hi");
  // tokensANS3.insert("sarthak");
  // tokensANS3.insert("bye");
  // cout << "6. " << (tokens3.size() == 3) << endl;
  // cout << "7. " << (tokens3 == tokensANS3) << endl;
  
  // cout << endl << "milestone 3" << endl;
  // map<string, set<string>> index;
  // string filename = "tiny.txt";
  // int num = buildIndex(filename, index);
  // cout << endl << "filename: " << filename << endl;
  // cout << "    # pages: " << num << endl;
  // cout << "    # unique words: " << index.size() << endl;

  // for (auto i : index) {
  //     cout << i.first <<": ";
  //     for (auto j : i.second) {
  //         cout << j << ", ";
  //     }
  //     cout << endl;
  // }

  // index.clear();
  // filename = "cplusplus.txt";
  // num = buildIndex(filename, index);
  // cout << endl << "filename: " << filename << endl;
  // cout << "    # pages: " << num << endl;
  // cout << "    # unique words: " << index.size() << endl;

  // index.clear();
  // filename = "uiccs-news.txt";
  // num = buildIndex(filename, index);
  // cout << endl << "filename: " << filename << endl;
  // cout << "    # pages: " << num << endl;
  // cout << "    # unique words: " << index.size() << endl;
  
  // cout << endl << "milestone 4" << endl;
  // index.clear();
  // filename = "tiny.txt";
  // cout << "filename: " << filename << endl;
  // num = buildIndex(filename, index);
  // string sentence;
  // getline(cin, sentence);
  // set<string> result = findQueryMatches(index, sentence);
  // for (string s : result) {
  //   cout << s << endl;
  // }

  // index.clear();
  // filename = "cplusplus.txt";
  // cout << "filename: " << filename << endl;
  // num = buildIndex(filename, index);
  // string sentence2;
  // getline(cin, sentence2);
  // set<string> result2 = findQueryMatches(index, sentence2);
  // for (string s : result2) {
  //   cout << s << endl;
  // }

  // // creative function
  // Stemming_CreativeFunction();

  // cout << endl << "milestone 5" << endl;
  string filename2 = "cplusplus.txt";
  searchEngine(filename2);

  return 0;
}

