#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include "util.h"

using namespace std;
std::string convToLower(std::string src)
{
    std::transform(src.begin(), src.end(), src.begin(), ::tolower);
    return src;
}

/** Complete the code to convert a string containing a rawWord
    to a set of words based on the criteria given in the assignment **/
std::set<std::string> parseStringToWords(string rawWords)
{
    //convert to lowercase
    rawWords = convToLower(rawWords);
    //clear extra whitespace on sides
    rawWords = trim(rawWords);
    std::set<std::string> wordSet;
    std::istringstream ss(rawWords);
    string word = "";
    for(unsigned int i=0; i<rawWords.length(); i++){
        char c = rawWords.at(i);
        //word ends if punctuation or space are met
        if(c ==' '|| std::ispunct(c)){
            //word has to be bigger than one letter
            if(word.length()>1){
                wordSet.insert(word);
            }
            word = "";
        }
        else{
            word+=c;
        }
    }
    return wordSet;
}

/**************************************************
 * COMPLETED - You may use the following functions
 **************************************************/

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// trim from start
std::string &ltrim(std::string &s) {
    s.erase(s.begin(), 
	    std::find_if(s.begin(), 
			 s.end(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
std::string &rtrim(std::string &s) {
    s.erase(
	    std::find_if(s.rbegin(), 
			 s.rend(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))).base(), 
	    s.end());
    return s;
}

// trim from both ends
std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}
