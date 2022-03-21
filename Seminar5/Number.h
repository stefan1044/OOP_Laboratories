class Number{

    // add data members
private:
    int base,length;
    char* value;

public:

    Number(const char * value, int base); // where base is between 2 and 16

    ~Number();



    // add operators and copy/move constructor
    Number(const Number& copy);//copy constructor
    Number(Number&& move);//move constructor
    Number& operator=(Number&& move);//move assignment operator

    friend Number operator+(const Number& other,const Number& other1);
    friend Number operator-(const Number& other,const Number& other1);
    bool operator > (const Number& other);
    bool operator >= (const Number& other);
    bool operator < (const Number& other);
    bool operator <= (const Number& other);
    bool operator == (const Number& other);
    bool operator --();
    bool operator --(int a);
    char operator[](int poz);


    void SwitchBase(int newBase);

    void Print();

    int  GetDigitsCount(); // returns the number of digits for the current number

    int  GetBase(); // returns the current base

};