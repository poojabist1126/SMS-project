#ifndef STUDENTCLASS_HPP
#define STUDENTCLASS_HPP

class Student {
private:
    std::string name;
    std::string address;
    std::string roll;
    std::string contact;

public:
    void add();
    void view();
    void del();
    void edit();
};

#endif