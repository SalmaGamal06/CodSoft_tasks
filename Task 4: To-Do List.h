#include <iostream>
#include <vector>
using namespace std;

#ifndef CODSOFT_TO_DO_LIST_H
#define CODSOFT_TO_DO_LIST_H

class List{
public:
    vector<pair<string,string>> list;
    void add(string& str);
    void view();
    void remove(int x);
    void task_completed(int x);

};

#endif //CODSOFT_TO_DO_LIST_H
