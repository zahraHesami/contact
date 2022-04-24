#include <iostream>
#include <vector>
#include <fstream>
#include<string.h>
using namespace std;
struct phonebook
{
    string name;
    string family;
    string nickname;
    vector<long long> phonenumber;
    long long number;
    int year;
    int month;
    int day;
    string email;
    char ch, keepgoing = 'y';
    int getinfo()
    {
        cout << "enter name" << '\n';
        cin >> name;
        cout << "enter family" << '\n';
        cin >> family;
        cout << "do you have nickname?(y/n)" << '\n';
        cin >> ch;
        if (ch == 'y' || ch == 'Y')
        {
            cout << "enter nickname" << '\n';
            cin >> nickname;
        }
        if (ch == 'n' || ch == 'N')
        {
            nickname = ":";
        }

        while (keepgoing != 'n')
        {
            cout << "enter phonenumber" << '\n';
            cin >> number;
            phonenumber.push_back(number);
            cout << "do you want keepgoing?(y/n)" << '\n';
            cin >> keepgoing;
        }
        int n = 0;
        n = phonenumber.size();

        cout << "enter birthday" << '\n';
        cin >> year >> month >> day;
        cout << "enter email" << '\n';
        cin >> email;
        return n;
    }
    void showinfo()
    {
        cout << " name :" << name << '\n';
        cout << " family :" << family << '\n';
        cout << "nickname :" << nickname << '\n';
        for (int i = 0; i < phonenumber.size(); i++)
        {
            cout << "phonenumber :" << phonenumber.at(i) << '\n';
        }
        cout << " birthday :" << year << month << day << '\n';
        cout << " email :" << email << '\n';
    }
    bool checkinfo()
    {
        if (year < 0 || month > 12 || month < 0 || day < 0 || day > 31)
        {
            return false;
        }
        if (month > 6 && day > 30)
        {
            return false;
        }
        if (month == 12 && day > 29)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    bool checkemail()
    {
        int n = 0, p = 0, k = 0, m = 0;
        for (int i = 0; i < email.size(); i++)
        {
            if (email.at(i) == '.')
            {
                n++;
                p = i;
            }
            if (email.at(i) == '@')
            {
                k++;
                m = i;
            }
        }
        if (n >= 2 || n == 0)
            return false;
        if (k >= 2 || k == 0)
            return false;
        if (m > p)
            return false;
        else
        {
            return true;
        }
    }
    bool checkphonenumber()
    {
        int counte = 0;
        for (int i = 0; i < phonenumber.size(); i++)
        {
            if (phonenumber.at(i) > 99999999999 || phonenumber.at(i) < 1111111111)
                counte++;
        }
        if (counte > 0)
        {
            return false;
        }
        return true;
    }
    bool checkname()
    {
      
        if (name.length()<3)
        {
            return false;
        }
        if (family.length()<3)
        {
            return false;
        }
        else{
             return true;
        }
           
    }
    bool checknickname(){
        if(nickname==":"){
            return true;
        }
        else{
            if(nickname.length()<3){
            return false;
        }  
        }
      return true;
    }
};
void creatphonebook(vector<phonebook> &);
void showphonebook(vector<phonebook> &);
void searchinfo1(vector<phonebook>);
void searchinfo2(vector<phonebook>);
void searchinfo3(vector<phonebook>);
void searchinfo4(vector<phonebook>);
void deletepeople(vector<phonebook> &);
void changnickname(vector<phonebook> &);
void deletenickname(vector<phonebook> &);
void deletephonenumber(vector<phonebook> &);
void addphonenumber(vector<phonebook> &);
void changeemail(vector<phonebook> &);
void writefile(phonebook, int);
void readfile(vector<phonebook> &);
void writefile2(vector<phonebook>);
void sortbyname(vector<phonebook> &);
int compare(string, string);
void sortbydate(vector<phonebook> &);
int main()
{
    vector<phonebook> people;
    readfile(people);
    char a;
    int flag = 1;

    while (flag != 0)
    {
        cout << "Choose one of them " << '\n';
        cout << "1)Add people " << '\n';
        cout << "2)Search and show information" << '\n';
        cout << "3)Delete people" << '\n';
        cout << "4)Change information" << '\n';
        cout << "5)sorting information" << '\n';
        cout << "6)exit" << '\n';
        cin >> a;
        if (a == '1')
        {
            creatphonebook(people);
        }
        if (a == '2')
        {
            int d;
            int flag1 = 0;
            while (flag1 == 0)
            {
                cout << "1)search whit name and family and show information" << '\n';
                cout << "2)search  white phonenumber and show information" << '\n';
                cout << "3)search  white nickname and birthday and show information" << '\n';
                cout << "4)search  white email and show information" << '\n';
                cout << "5) show all information" << '\n';
                cout << "6) return" << '\n';
                cin >> d;
                switch (d)
                {
                case 1:
                    searchinfo1(people);
                    break;
                case 2:
                    searchinfo2(people);
                    break;
                case 3:
                    searchinfo3(people);
                    break;
                case 4:
                    searchinfo4(people);
                    break;
                case 5:
                    showphonebook(people);
                    break;
                case 6:
                    flag1 = 1;
                    break;
                default:
                    break;
                }
            }
        }
        if (a == '3')
        {
            deletepeople(people);
        }
        if (a == '4')
        {
            int flag2 = 0;
            char answer;
            while (flag2 == 0)
            {
                cout << "1)Change nickname" << '\n';
                cout << "2)Delete nickname" << '\n';
                cout << "3)Delete phonenumber" << '\n';
                cout << "4)Add phonenumber" << '\n';
                cout << "5)Change email" << '\n';
                cout << "6)return" << '\n';
                cin >> answer;
                switch (answer)
                {
                case '1':
                    changnickname(people);
                    break;
                case '2':
                    deletenickname(people);
                    break;
                case '3':
                    deletephonenumber(people);
                    break;
                case '4':
                    addphonenumber(people);
                    break;
                case '5':
                    changeemail(people);
                    break;
                case '6':
                    flag2 = 1;
                    break;
                default:
                    break;
                }
            }
        }
        if (a == '5')
        {
            int flag = 1, a = 0;
            while (flag == 1)
            {
                cout << "Choose one of them " << '\n';
                cout << "1)Sort the string alphabetically" << '\n';
                cout << "2)Sort the string by date " << '\n';
                cout << "3)return" << '\n';
                cin >> a;
                switch (a)
                {
                case 1:
                    sortbyname(people);
                    showphonebook(people);
                    break;
                case 2:
                    sortbydate(people);
                    showphonebook(people);
                    break;
                case 3:
                    flag = 0;
                default:
                    break;
                }
            }
            writefile2(people);
        }
        if (a == '6')
        {
            flag = 0;
        }
    }
    system("pause");
    return 0;
}
void creatphonebook(vector<phonebook> &people)
{
    phonebook people1;
    int n;
    n = people1.getinfo();
    if (people1.checkinfo()&& people1.checkemail() && people1.checkphonenumber() && people1.checkname()&&people1.checknickname())
    {
        people.push_back(people1);
        writefile(people1, n);
    }
    else
    {
        cout << "incorrect information" << '\n';
    }
}
void showphonebook(vector<phonebook> &people)
{
    for (int i = 0; i < people.size(); i++)
    {
        people.at(i).showinfo();
    }
}
void searchinfo1(vector<phonebook> people)
{
    string name, family;
    int flag = 0;
    cout << "enter name" << '\n';
    cin >> name;
    cout << "enter family" << '\n';
    cin >> family;
    for (auto people1 : people)
    {
        if (people1.name == name && people1.family == family)
        {
            flag = 1;
            people1.showinfo();
        }
    }
    if (flag == 0)
    {
        cout << "not found" << '\n';
    }
}
void searchinfo2(vector<phonebook> people)
{
    long long phonenumber;
    int flag = 0, n = 0;
    cout << "enter phonenumber " << '\n';
    cin >> phonenumber;
    for (int j = 0; j < people.size(); j++)
    {
        for (int i = 0; i < people.at(j).phonenumber.size(); i++)
        {
            if (people.at(j).phonenumber.at(i) == phonenumber)
            {
                flag = 1;
                n = j;
            }
        }
    }
    if (flag == 1)
    {
        people.at(n).showinfo();
    }
    if (flag == 0)
    {
        cout << "not found" << '\n';
    }
}
void searchinfo3(vector<phonebook> people)
{
    string nickname;
    char a;
    int year;
    int month;
    int day;
    int flag = 0;
    cout << "have nickname ?(y/n)";
    cin >> a;
    if (a == 'y' || a == 'Y')
    {
        cout << "enter nickname" << '\n';
        cin >> nickname;
        cout << "enter birthday" << '\n';
        cin >> year >> month >> day;
        for (auto people1 : people)
        {
            if (people1.nickname != " :")
            {
                if (people1.nickname == nickname && people1.year == year && people1.month == month && people1.day == day)
                {
                    people1.showinfo();
                    flag = 1;
                }
            }
        }
    }
    else
    {
        cout << "enter birthday" << '\n';
        cin >> year >> month >> day;
        for (auto people1 : people)
        {
            if (people1.year == year && people1.month == month && people1.day == day)
            {
                people1.showinfo();
                flag = 1;
            }
        }
    }
    if (flag == 0)
    {
        cout << "not found" << '\n';
    }
}
void searchinfo4(vector<phonebook> people)
{
    string email;
    int flag = 0;
    cout << "enter email " << '\n';
    cin >> email;
    for (auto people1 : people)
    {
        if (people1.email == email)
        {
            flag = 1;
            people1.showinfo();
        }
        if (people1.email != email)
        {
            flag = 2;
        }
    }
    if (flag == 2)
    {
        cout << "not found" << '\n';
    }
}
void deletepeople(vector<phonebook> &people)
{
    long long number;
    bool find = false;
    int n =-1,flag=0;
    cout << "enter phonenumber" << '\n';
    cin >> number;
    for (int i = 0; i < people.size() && (!find); i++)
    {
        for (int j = 0; j < people.at(i).phonenumber.size(); j++)
        {
            if (people.at(i).phonenumber.at(j) == number)
            {
                n = i;
                flag=1;
                find = true;
            }
        }
    }
    if (n>=0)
    {
        people.erase(people.begin() + n);
        writefile2(people);
    }
    if(flag==0){
        cout<<"not found"<<'\n';
    }
    
}
void changnickname(vector<phonebook> &people)
{
    long long number;
    char a;
    string nickname1;
    int index = -1;
    cout << "enter phonenumber" << '\n';
    cin >> number;
    cout << "enter new nickname" << '\n';
    cin >> nickname1;
    for (int i = 0; i < people.size(); i++)
    {
        if (people.at(i).nickname != ":")
        {
            for (int j = 0; j < people.at(i).phonenumber.size(); j++)
            {
                if (people.at(i).phonenumber.at(j) == number)
                {
                    people.at(i).nickname = nickname1;
                    index = i;
                }
            }
        }
    }
    if (index == -1)
    {
        cout << "she/he doese not have nickname " << '\n';
    }
}
void deletenickname(vector<phonebook> &people)
{
    long long number;
    string a1 = "";
    int index1 = 0;
    cout << "enter phonenumber" << '\n';
    cin >> number;
    for (int i = 0; i < people.size(); i++)
    {
        for (int j = 0; j < people.at(i).phonenumber.size(); j++)
        {
            if (people.at(i).nickname != ":")
            {
                if (people.at(i).phonenumber.at(j) == number)
                {
                    index1 = i;
                    people.at(i).nickname = a1;
                }
            }
        }
        if (people.at(i).nickname == ":")
        {
            cout << "she/he doese not have nickname" << '\n';
            index1=2;
            break;
        }
    }
    if (index1 == 0)
    {
        cout << "not found" << '\n';
    }
}
void addphonenumber(vector<phonebook> &people)
{
    long long number, newnumber;
    int index = 0;
    cout << "enter phonenumber" << '\n';
    cin >> number;
    cout << "enter new phonenumber" << '\n';
    cin >> newnumber;
    for (int i = 0; i < people.size(); i++)
    {
        for (int j = 0; j < people.at(i).phonenumber.size(); j++)
        {
            if (people.at(i).phonenumber.at(j) == number)
            {
                people.at(i).phonenumber.push_back(newnumber);
                index = 1;
            }
        }
    }
    if (index == 0)
    {
        cout << "not found" << '\n';
    }
}
void changeemail(vector<phonebook> &people)
{
    long long number;
    int index = 0, n = 0;
    string email1;
    cout << "enter phonenumber" << '\n';
    cin >> number;
    cout << "enter new email" << '\n';
    cin >> email1;
    for (int i = 0; i < people.size(); i++)
    {
        for (int j = 0; j < people.at(i).phonenumber.size(); j++)
        {
            if (people.at(i).phonenumber.at(j) == number)
            {
                index = 1;
                n = i;
            }
        }
    }
    if (index == 1)
    {
        people.at(n).email = email1;
    }
    if (index == 0)
    {
        cout << "not found" << '\n';
    }
}
void deletephonenumber(vector<phonebook> &people)
{
    long long number;
    int index = 0, n = 0, flag = 1;
    cout << "enter phonenumber" << '\n';
    cin >> number;
    for (int i = 0; i < people.size(); i++)
    {
        for (int j = 0; j < people.at(i).phonenumber.size(); j++)
        {
            if (people.at(i).phonenumber.at(j) == number)
            {
                n = j;
                index = i;
                flag = 0;
            }
        }
    }
    if (people.at(index).phonenumber.size() == 1)
    {
        cout << "There is only one phone number. Can not be deleted!" << '\n';
    }
    else if (flag == 1)
    {
        cout << "not found" << '\n';
    }
     if (people.at(index).phonenumber.size() > 1){
          people.at(index).phonenumber.erase(people.at(index).phonenumber.begin() + n);
      }
     } 
void writefile(phonebook people1, int n)
{
    ofstream myfile("phonebook.txt", ios::app);
    if (myfile)
    {
        myfile << people1.name << '\t';
        myfile << people1.family << '\t';
        myfile << people1.nickname << '\t';
        for (int i = 0; i < n; i++)
        {
            myfile << people1.phonenumber.at(i) << '\t';
        }
        myfile << "0" << '\t';
        myfile << people1.year << '\t';
        myfile << people1.month << '\t';
        myfile << people1.day << '\t';
        myfile << people1.email << '\t';
        myfile << '\n';

        myfile.close();
    }
    else
    {
        cerr << "There is an error in the file";
    }
}
void readfile(vector<phonebook> &people)
{
    ifstream myfile("phonebook.txt", ios::in);
    phonebook person1;
    long long number = -1;
    if (myfile)
    {

        while (myfile)
        {
            myfile >> person1.name;
            myfile >> person1.family;
            myfile >> person1.nickname;
            person1.phonenumber.clear();
            do
            {
                myfile >> number;
                person1.phonenumber.push_back(number);
            } while (number != 0);
            person1.phonenumber.pop_back();
            myfile >> person1.year;
            myfile >> person1.month;
            myfile >> person1.day;
            myfile >> person1.email;
            people.push_back(person1);
        }
        people.pop_back();
        myfile.close();
    }

    else
    {
        cerr << "There is an error in the file";
    }
}
void writefile2(vector<phonebook> people)
{
    ofstream myfile("phonebook.txt", ios::trunc);
    if (myfile)
    {
        for (int i = 0; i < people.size(); i++)
        {
            myfile << people.at(i).name << '\t';
            myfile << people.at(i).family << '\t';
            myfile << people.at(i).nickname << '\t';
            for (int j = 0; j < people.at(i).phonenumber.size(); j++)
            {
                myfile << people.at(i).phonenumber.at(j) << '\t';
            }
            myfile << "0" << '\t';
            myfile << people.at(i).year << '\t';
            myfile << people.at(i).month << '\t';
            myfile << people.at(i).day << '\t';
            myfile << people.at(i).email << '\t';
            myfile << '\n';
        }
        myfile.close();
    }
    else
    {
        cerr << "There is an error in the file";
    }
}
void sortbyname(vector<phonebook> &people)
{
    phonebook temp;
    for (int i = 1; i < people.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (compare(people.at(i).family, people.at(j).family) > 0 ||
                (compare(people.at(i).family, people.at(j).family) == 0 &&
                 compare(people.at(i).name, people.at(j).name) > 0))
            {
                temp = people.at(i);
                people.at(i) = people.at(j);
                people.at(j) = temp;
            }
        }
    }
}
int compare(string x, string y)
{
    int sizex = 0, sizey = 0, size = 0;
    sizex = x.size();
    sizey = y.size();
    if (sizex > sizey)
    {
        size = sizey;
    }
    if (sizex < sizey)
    {
        size = sizex;
    }
    for (int i = 0; i < size; i++)
    {
        if (int(x[i]) > 65 && int(x[i]) < 92)
        {
            x[i] += 32;
        }
        if (int(y[i]) > 65 && int(y[i]) < 92)
        {
            y[i] += 32;
        }
        if (int(x[i]) == int(y[i]))
            continue;
        if (int(x[i]) < int(y[i]))
            return 1;
        if (int(x[i]) > int(y[i]))
            return -1;
    }
    if (x.size() < y.size())
        return 1;
    if (x.size() > y.size())
        return -1;
    return 0;
}
void sortbydate(vector<phonebook> &people)
{
    phonebook temp;
    for (int i = 1; i < people.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (people.at(i).year < people.at(j).year ||
                (people.at(i).year == people.at(j).year && people.at(i).month < people.at(j).month) ||
                (people.at(i).year == people.at(j).year && people.at(i).month == people.at(j).month && people.at(i).day < people.at(j).day))
            {
                temp = people.at(i);
                people.at(i) = people.at(j);
                people.at(j) = temp;
            }
        }   }
 cout << "sort is successFully!" << endl;
}
