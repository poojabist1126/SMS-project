

#ifndef GRADECLASS_HPP
#define GRADECLASS_HPP

class Grade {
private:
    std::string roll;
    std::string courseCode;
    std::string marks;

public:
    void add();
    void view();
    void del();
    void edit();
};

#endif