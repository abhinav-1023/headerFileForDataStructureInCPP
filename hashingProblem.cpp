   #include<iostream> 
   #include<unordered_map>
   using namespace std;
   int main(){
    unordered_map<string,int> menu;
    menu["maggi"]=15;
    menu["colddrink"]=20;
    menu["dosa"]=99;
    string item;
    cin>>item;
    if(menu.count(item)==0){
        cout<<item<<"is not available";

    }
    else{
        cout<<item<<"is available and its cost is "<<menu[item]<<endl;
    }
   
   return 0;
   }