#include <boost/lambda/lambda.hpp>
#include <boost/bind/bind.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/trim.hpp>
#include <boost/assign/list_of.hpp>
#include <iostream>
#include <iterator>
#include <algorithm>
#include "bind.h"

/*bind example*/
void connect(){
    button playButton, stopButton;
    player thePlayer;

    playButton.onClick = boost::bind(&player::play, &thePlayer, boost::placeholders::_1);
    stopButton.onClick = boost::bind(&player::stop, &thePlayer, boost::placeholders::_1);

    playButton.onClick(3);
    stopButton.onClick(4);

}

/*string_to_upper*/
void string_to_upper()
{
    std::string orig_str = "abc";
    std::string upper_str = boost::to_upper_copy(orig_str);
    cout << "------------------------------" << endl;
    cout << "boost::to_upper_copy(" <<orig_str <<") --> "<< upper_str << endl;
    boost::to_upper_copy(orig_str);
    cout << "Original string: " << orig_str << endl;

    cout << "------------------------------" << endl;
    cout << "boost::to_upper(" <<orig_str <<") --> "<< upper_str << endl;
    boost::to_upper(orig_str);
    cout << "Original string: " << orig_str << endl;
}

void trim()
{
    cout << "------------------------------" << endl;
    cout << "boost::trim_left()" << endl;

    std::string s = "  123456789";
    std::string s2 = "00123456789";

    cout << s << "--> ";
    boost::trim_left(s);
    cout << s << endl;

    cout << s2 << "--> ";
    boost::trim_left_if(s2, boost::is_any_of("0"));
    cout << s2 << endl;
}

int main(int argc, char *argv[])
{
   string_to_upper();
   trim();
}
