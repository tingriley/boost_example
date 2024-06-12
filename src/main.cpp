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
using namespace std;

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
    string s = "Boost C++ Libraries";
    cout << s << " -> ";
    cout << boost::to_upper_copy(s) << '\n';
}

void trim()
{
    string phone="00423333444";
    cout << phone << " -> ";
    // remove leading 0 from the phone number
    boost::trim_left_if(phone, boost::is_any_of("0")); // phone == "423333444"
    cout << phone << '\n';
}

int main(int argc, char *argv[])
{
   string_to_upper();
   trim();
}
