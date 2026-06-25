#include <iostream>
#include <cctype>
using namespace std;

bool haslower(string password);
bool hasUpper(string password);
bool hasDigit(string password);
bool hasSymbol(string password);
bool hasRepeated(string password);
bool hasSequential (string password);



int main(){
    string password;
    cout<<"-----------------------"<<'\n';
    cout<<"Enter your password to check it's strength: "<<'\n';
    cin>>password;
    cout<<"-----------------------"<<'\n';
    int score = 0;
    if(password.length() < 8){
      score+=0;
    }
    else if(password.length() >= 8 && password.length() <= 11){
      score+=2;
    }
   else if(password.length() >= 12 && password.length() <= 15){
      score+=4;
    }
   else{
   score+=6;
  }

  if(haslower(password)){
   score+=2;
  }
  if(hasUpper(password)){
   score+=2;
  }
  if(hasDigit(password)){
   score+=2;
  }
  if(hasSymbol(password)){
   score+=2;
  }
  if(hasRepeated(password)){
   score-=2;
   cout<<"The password has repeated characters. ";
  }
  if(hasSequential(password)){
   score-=2;
   cout<<"The password has sequential characters. ";
  }
  if(score >= 0 && score <= 4){
    cout<<"Your dog can write a better password than this! "<<"score: "<<score<<'\n';
  }
  else if(score >= 5 && score <= 8){
    cout<<"Damn your grandma is stronger than this. "<<"score: "<<score<<'\n';
  }
   else if(score >= 9 && score <= 12){
    cout<<"Ehh could be better. "<<"score: "<<score<<'\n';
  }
   else if(score >= 13 && score <= 16){
    cout<<"Awesome! Only if your marks were as good as this. "<<"score: "<<score<<'\n';
  }
   else if(score <= 17){
    cout<<"How tf you gonna remember this password??? "<<"score: "<<score<<'\n';
  }
  else{
   cout<<"DAWG WTF ON EARTH IS THIS?????"<<"score: "<<score<<'\n';
  }
  system("pause>0");
}
bool haslower(string password){
   int lowercount = 0;
   bool lower = false;
   for(char c : password){
        if(islower(c)){
            lowercount+=1;
        }
   }
   if(lowercount >= 1){
      lower = !lower;
   }
   return lower;
}
bool hasUpper(string password){
   int uppercount = 0;
   bool upper = false;
   for(char c : password){
        if(isupper(c)){
            uppercount+=1;
        }
   }
   if(uppercount >= 1){
      upper = !upper;
   }
   return upper;
}
bool hasDigit(string password){
   int digitcount = 0;
   bool digit = false;
   for(char c : password){
        if(isdigit(c)){
            digitcount=1;
        }
   }
   if(digitcount >= 1){
      digit = !digit;
   }
   return digit;
}
bool hasSymbol(string password){
   int symbolcount = 0;
   bool symbol = false;
   for(char c : password){
        if(!isalnum(c)){
            symbolcount=1;
        }
   }
   if(symbolcount >= 1){
      symbol = !symbol;
   }
   return symbol;

}
bool hasRepeated(string password){
   bool hasrepeated = false;
    for(int i = 0; i < (password.length()-2); i++){
         if(password[i] == password[i+1] && password[i+1] == password[i+2]){
               hasrepeated = !hasrepeated;
               break;
         }
      else{
         continue;
      }
    }
    return hasrepeated;
}
bool hasSequential (string password){
    bool hassequential= false;
    for(int i = 0; i < (password.length()-2); i++){
         if((password[i]) == (password[i+1] - 1) && password[i+1] == (password[i+2] - 1)){
               hassequential = !hassequential;
               break;
         }
      else{
         continue;
      }
    }
    return hassequential;
}