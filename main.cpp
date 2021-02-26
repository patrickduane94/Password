#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

int countUpper(const char* str){
    int upperCount=0;
    for(int i=0; i<strlen(str); i++){
        if(isupper(str[i])){
            upperCount++;//count number of uppercase letters
        }
    }
    return upperCount;
}
int countLower(const char* str){
    int lowerCount=0;
    for(int i=0; i<strlen(str); i++){
        if(islower(str[i])){
            lowerCount++;//count number of lowercase letters
        }
    }
    return lowerCount;
}
bool subString1(const char* str, const char* sub1){
    if(strstr(str, sub1) != NULL){
        return true;
    }
    else{
        return false;
    }
}
bool subString2(const char* str, const char* sub2){
    if(strstr(str, sub2) != NULL){
        return true;
    }
    else{
        return false;//checks if password contains substrings
    }
}
bool specialChar(const char* str, const char* special){
    if(strcspn(str, special) != strlen(str)){
        return true;
    }
    else{
        return false;//checks if password contains special character from array to be created in main
    }
}
bool searchLetters(const char* str, const char* letters){
    if(strcspn(str, letters) == strlen(str)){
        return true;
    }
    else{
        return false;//checks if password contains forbidden letters
    }
}
int main() {
    int tries=0;
    while(true){
        bool p=true;
        char letters[]={'l','i','o','z','I','O','S','\0'};
        char special[]={'!','@','#','$','%','^','&','*','(',')','_','-','`','~','<','>','?','\0'};//arrays for letter/character requirements
        char password[100];
        char abc[4]="abc";
        char num[4]="123";
        cout<<"Please create a new password:"<<endl;
        cin.getline(password, 100);
        tries++;//increment tries each attempt
        if(strlen(password)<8){
            cout<<"Password is too short, 8 characters minimum."<<endl;
            p=false;
        }
        if(strlen(password)>12){
            cout<<"Password is too long, 12 characters maximum."<<endl;
            p=false;
        }
        if(countUpper(password)<1){
            cout<<"Password must contain at least one uppercase letter."<<endl;
            p=false;
        }
        if(countLower(password)<1){
            cout<<"Password must contain at least one lowercase letter."<<endl;
            p=false;
        }
        if(subString1(password, abc)==true){
            cout<<"Password cannot contain 'abc' substring."<<endl;
            p=false;
        }
        if(subString2(password, num)==true){
            cout<<"Password cannot contain '123' substring."<<endl;
            p=false;
        }
        if(searchLetters(password, letters)==false){
            cout<<"Password cannot contain lowercase l, i, o, or z. Password cannot contain uppercase I, O, or S."<<endl;
            p=false;
        }
        if(specialChar(password, special)==false){
            cout<<"Password must contain at least one special character."<<endl;
            p=false;
        }
        if(tries==6){
            cout<<"You have used all 5 retries. Try again later."<<endl;
            p=false;
            break;
        }
        if(p==true){//p is true only if password passes all requirements
            cout<<"Password set successfully."<<endl;
            break;
        }
    }
    return 0;
}
