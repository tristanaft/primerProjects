template<typename T> int compare(const T&, const T&);

int main(){
    //compare("hi","world");
    //the deduced types are char[3] and char[6], and so cannot be compared
    compare("bye","dad");
    //this is fine.
    return 0;
}