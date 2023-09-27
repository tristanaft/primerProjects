template<typename T> T calc(T, int);
template<typename T> T fcn(T, T);

int main(){

    double d; float f; char c;
    //calc(c, 'c'); legal? type is char and 'c' is cast to int? T: char
    //calc(d,f);    legal can convert float to int? T: double
    //fcn(c, 'c');  legal types match T: char
    //fcn(d,f);     illegal, types don't match


    return 0;
}