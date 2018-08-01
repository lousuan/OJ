// 1008_Maya Calendar

// Description
// During his last sabbatical, professor M. A. Ya made a surprising discovery
// about the old Maya calendar. From an old knotted message, professor
// discovered that the Maya civilization used a 365 day long year, called Haab,
// which had 19 months. Each of the first 18 months was 20 days long, and the
// names of the months were pop, no, zip, zotz, tzec, xul, yoxkin, mol, chen,
// yax, zac, ceh, mac, kankin, muan, pax, koyab, cumhu. Instead of having names,
// the days of the months were denoted by numbers starting from 0 to 19. The
// last month of Haab was called uayet and had 5 days denoted by numbers 0, 1,
// 2, 3, 4. The Maya believed that this month was unlucky, the court of justice
// was not in session, the trade stopped, people did not even sweep the floor.

// For religious purposes, the Maya used another calendar in which the year was
// called Tzolkin (holly year). The year was divided into thirteen periods, each
// 20 days long. Each day was denoted by a pair consisting of a number and the
// name of the day. They used 20 names: imix, ik, akbal, kan, chicchan, cimi,
// manik, lamat, muluk, ok, chuen, eb, ben, ix, mem, cib, caban, eznab, canac,
// ahau and 13 numbers; both in cycles.

// Notice that each day has an unambiguous description. For example, at the
// beginning of the year the days were described as follows:

// 1 imix, 2 ik, 3 akbal, 4 kan, 5 chicchan, 6 cimi, 7 manik, 8 lamat, 9 muluk,
// 10 ok, 11 chuen, 12 eb, 13 ben, 1 ix, 2 mem, 3 cib, 4 caban, 5 eznab, 6
// canac, 7 ahau, and again in the next period 8 imix, 9 ik, 10 akbal . . .

// Years (both Haab and Tzolkin) were denoted by numbers 0, 1, : : : , where the
// number 0 was the beginning of the world. Thus, the first day was:

// Haab: 0. pop 0
// Tzolkin: 1 imix 0

// Help professor M. A. Ya and write a program for him to convert the dates from
// the Haab calendar to the Tzolkin calendar.

// Input
// The date in Haab is given in the following format:
// NumberOfTheDay. Month Year

// The first line of the input file contains the number of the input dates in
// the file. The next n lines contain n dates in the Haab calendar format, each
// in separate line. The year is smaller then 5000.

// Output
// The date in Tzolkin should be in the following format:
// Number NameOfTheDay Year

// The first line of the output file contains the number of the output dates. In
// the next n lines, there are dates in the Tzolkin calendar format, in the
// order corresponding to the input dates.

// Sample Input
// 3
// 10. zac 0
// 0. pop 0
// 10. zac 1995

// Sample Output
// 3
// 3 chuen 0
// 1 imix 0
// 9 cimi 2801

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>

using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostringstream;
using std::string;
using std::vector;
using std::map;

// StandardDate 第一天从 0 开始
typedef int StandardDate;

class MayaDate {
public:
    StandardDate date;
    MayaDate();
    MayaDate(StandardDate date);
    ~MayaDate();
};

class Haab : public MayaDate {
private:
    static bool _init;
    static bool init();
public:
    static map<string, int> reverse_dict;
};

class Tzolkin : public MayaDate {
private:
    static bool _init;
    static bool init();
public:
    Tzolkin();
    static vector<string> dict;
    Tzolkin(StandardDate std_date);
    string ToString() const;
};

MayaDate::MayaDate() { date = 0; };
MayaDate::~MayaDate(){};

map<string, int> Haab::reverse_dict;
// 使用 init() 初始化 _init，顺便初始化 dict
bool Haab::_init = Haab::init();
bool Haab::init() {
    // 前 18 个月都是 20 天，用 0-19 表示
    reverse_dict["pop"] = 0;
    reverse_dict["no"] = 1;
    reverse_dict["zip"] = 2;
    reverse_dict["zotz"] = 3;
    reverse_dict["tzec"] = 4;
    reverse_dict["xul"] = 5;
    reverse_dict["yoxkin"] = 6;
    reverse_dict["mol"] = 7;
    reverse_dict["chen"] = 8;
    reverse_dict["yax"] = 9;
    reverse_dict["zac"] = 10;
    reverse_dict["ceh"] = 11;
    reverse_dict["mac"] = 12;
    reverse_dict["kankin"] = 13;
    reverse_dict["muan"] = 14;
    reverse_dict["pax"] = 15;
    reverse_dict["koyab"] = 16;
    reverse_dict["cumhu"] = 17;
    // 最后一个月只有 5 天，用 0-4 表示
    reverse_dict["uayet"] = 18;

    return true;
};

istream & operator>> (istream & is, Haab & haab) {
    int day;
    char dot;
    string month;
    int year;

    is >> day >> dot >> month >> year;
    haab.date = year * 365 + haab.reverse_dict[month] * 20 + day;
    
    return is;
};

vector<string> Tzolkin::dict;
bool Tzolkin::_init = Tzolkin::init();
bool Tzolkin::init() {
    dict.reserve(20);
    // 一个周期 20 天，用不同单词表示
    dict.push_back("imix");
    dict.push_back("ik");
    dict.push_back("akbal");
    dict.push_back("kan");
    dict.push_back("chicchan");
    dict.push_back("cimi");
    dict.push_back("manik");
    dict.push_back("lamat");
    dict.push_back("muluk");
    dict.push_back("ok");
    dict.push_back("chuen");
    dict.push_back("eb");
    dict.push_back("ben");
    dict.push_back("ix");
    dict.push_back("mem");
    dict.push_back("cib");
    dict.push_back("caban");
    dict.push_back("eznab");
    dict.push_back("canac");
    dict.push_back("ahau");

    return true;
};

Tzolkin::Tzolkin(){};

Tzolkin::Tzolkin(StandardDate std_date) {
    date = std_date;
}

string Tzolkin::ToString() const {
    int year = date / 260;
    int day = date % 260;

    ostringstream s;
    s << day % 13 + 1 << ' ' << dict[day % 20]  << ' ' << year;
    return s.str();
};

int main() {
    std::ios::sync_with_stdio(false);
    int n;
    cin >> n;
    cout << n << endl;
    Haab haab;
    Tzolkin tzolkin;
    for (int i = 0; i != n; ++i) {
        cin >> haab;
        tzolkin.date = haab.date; 
        // cout << tzolkin.date << ": ";
        cout << tzolkin.ToString() << endl;
    }
    return 0;
}