
class Base{
public:
    int pub_mem() {return 1;}; //if this is void, get error below when I call this...
protected:
    int prot_mem;
private:
    char priv_mem;
};

struct Pub_Deriv: public Base{
    void memfcn(Base &b) { b = *this; } //LEGAL
};
struct Priv_Deriv: private Base{
    void memfcn(Base &b) { b = *this; } //LEGAL
};
struct Prot_Deriv: protected Base{
    void memfcn(Base &b) { b = *this; } //LEGAL
};
struct Derived_from_public: public Pub_Deriv{
    void memfcn(Base &b) { b = *this; } //LEGAL
};
struct Derived_from_private: public Priv_Deriv{
    //void memfcn(Base &b) { b = *this; } //ILLEGAL
};
struct Derived_from_protected: public Prot_Deriv{
    void memfcn(Base &b) { b = *this; } //LEGAL
};

int main(){
    Pub_Deriv d1; //Base mems are pub
    Priv_Deriv d2; //Base mems are priv
    Prot_Deriv d3;
    Derived_from_public dd1;
    Derived_from_private dd2;
    Derived_from_protected dd2;
    //d1.pub_mem();
    //d2.pub_mem(); //ERROR

    Base *p = &d1;
    //p = &d2; //ERROR, CAN ONLY DERIVED-TO-BASE IF IT INHERITS PUBLICLY
    //p = &d3; //ERROR ^
    p = &dd1;
    //p = &dd2; ERROR ^
    //p = &dd3; ERROR ^




    return 0;
}