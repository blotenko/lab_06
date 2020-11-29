#include <iostream>
#include <fstream>
//#include <cstring>
//#include <vector>
//#include <sstream>
#include <string>

using namespace std;

string wide(string s, unsigned long size){
    unsigned long len =  s.length();
    unsigned long spaceAdd = size-len;
    int j=0;
    if(spaceAdd==0) return s;
    else if(spaceAdd!=0){
            for(int i = 0; i<len;i++){
                if(j>=spaceAdd) break;
                if(s[i]==' '){
                s.insert(i,"1",1);
                j++;
                i=i+1;
            }
        }
    }
    return s;
}



void task3(){
    string s;
    unsigned long size = 87;
    string fileName = "D:\\hello.txt";
    ifstream file(fileName); 
    if (file.fail())

    {
    cerr << "Ошибка открытия : "<< fileName<< endl;
    exit(1);
    }
    //int counter=0;
    cout<<s.length();
      while(getline(file,s)){
          cout<<wide(s,size)<<endl;
      }

      file.close();
}






/*
 У бінарному файлі зберігається велика послідовність чисел. Вивести на екран
 середнє арифметичне всіх додатних елементів.
 */
void writeToFile(int n){
    int tmp;
       time_t temp = time(NULL);
       srand(temp);
       ofstream out("D:\\Vlad.txt", ios::binary | ios::out);
       for (int i = 0; i < n; i++)
       {
           tmp = rand() % 1001 -400;
           out.write((char*)&tmp, sizeof (tmp));
           cout << tmp << " ";
       }
       out.close();
       cout << endl << endl;

}



void readFromFile(int n){
    int tmp;
    float sumOfPos=0;
    float counter=0;
       ifstream in("D:\\Vlad.txt", ios::binary | ios::in);
       for (int i = 0; i < n; i++)
       {
           in.read((char*)&tmp, sizeof (tmp));
           if (tmp >0){
               sumOfPos=sumOfPos+tmp;
               counter++;
           }

       }
    cout<<"Середнє значення додатніх чисел : "<<sumOfPos/counter<<endl;

           in.close();
}


int main(){
    task3();
    cout<<endl<<endl;
    int n;
    cout << "Введите количество значений: ";
    cin >> n;
    writeToFile(n);
    readFromFile(n);
    return 0;
}

