#include <iostream>
using namespace std;

int main() {
    int lvl;
    int mp;
    bool hasSword;
    bool hasKey;
    bool isCursed;

    cout << "Enter lvl, mp, do you Have a sword, are you cursed, do you Have a key:  ";
    cin >> lvl >> mp >> hasSword >> isCursed >> hasKey;
   // Admin Key
   if(hasKey == 1){
      cout<< "Gate Opened";
   } else if( lvl < 50 && isCursed == 1){
           cout<< "Gate Locked";
     }else{
            bool resource= ( mp >50 || hasSword == 1);
           if( lvl >= 30 && resource){
               cout<< "Gate Opened";
            } else{
                cout<< " Gate closed";
            }
      }
}