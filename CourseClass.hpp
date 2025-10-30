#ifndef COURSECLASS_HPP
#define COURSECLASS_HPP

class Course {
private:
    std::string courseCode;
    std::string title;
    std::string descp;
    std::string teacher;

public:
    void add();
    void view();
    void del();
    void edit();
};

#endif