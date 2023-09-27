#include<memory>
#include<iostream>

struct destination{
    unsigned int id;
    explicit destination(unsigned des_id = 0) : id(des_id) {}
}; // represents where we are connecting to

struct connection{
    destination* dest;
}; // information needed for connection

connection connect(destination* dest) {
    connection new_conn;
    new_conn.dest = dest;
    std::cout << "Setup connection to " << new_conn.dest->id << std::endl;
    return new_conn;
};

void disconnect(connection conn) {
    std::cout << "Stop connection to " << conn.dest->id << std::endl;
    //free connection
}

void endConnection(connection *pc){ 
    disconnect(*pc); //need to define a deleter function
}

void f(destination &d /*other params*/){
    //get connection, remember close when done
    connection c = connect(&d);
    std::shared_ptr<connection> p(&c,endConnection);
    //setting up this shared pointer will automatically disconnect c
    //when the function ends, so that is the "managing"

    //use connection
    std::cout << "Using connection: " << c.dest -> id << std::endl;
}

int main(){
    destination d(5);
    f(d);


    return 0;
}