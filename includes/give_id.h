#ifndef GIVE_ID
#define GIVE_ID
int give_id(){
    static int id{0};
    return id++;
}

#endif